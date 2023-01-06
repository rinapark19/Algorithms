import sys

from gameobject import GameObject, Marisa
from util import *

import pygame.transform
from pygame.locals import *


class Game:
    def __init__(self, fps=30):
        self.fps = fps
        self.window_width = WIDTH
        self.window_height = HEIGHT
        self.window_sz = (WIDTH, HEIGHT)
        self.background = pygame.transform.scale(pygame.image.load('background.png'),
                                                 (self.window_width, self.window_height))
        pygame.init()
        self.fps_clock = pygame.time.Clock()
        self.display_surf = pygame.display.set_mode((self.window_width, self.window_height))
        self.basic_font = pygame.font.Font('freesansbold.ttf', 18)
        pygame.display.set_caption('Marisachan Ganbatte!')
        self.last_time = pygame.time.get_ticks()

    def initialize(self):
        self.score = 0
        self.marisa = Marisa(image="marisa.png", size=None, update_ms=100, pos=(150, 150))
        self.apples = []
        self.mushrooms = []

        while len(self.apples) < 3:
            collide = False
            new_apple = GameObject(image="apple.png",
                                   size=(30, 30), update_ms=1000,
                                   pos=get_rand_pos(self.window_sz, (128, 128)), velocity=(0, 0))

            for apple in self.apples:
                if GameObject.collide(apple, new_apple):
                    collide = True
                    break
            if collide is False:
                self.apples.append(new_apple)
            else:
                del new_apple

        while len(self.mushrooms) < 2:
            collide = False
            new_mushrooms = GameObject(image="mushroom.png",
                                       size=(40, 40),
                                       update_ms=1000,
                                       pos=get_rand_pos(self.window_sz,
                                                        (128, 128)), velocity=(0, 0))

            for mushroom in self.mushrooms:
                if GameObject.collide(mushroom, new_mushrooms):
                    collide = True
                    break
            if collide is False:
                self.mushrooms.append(new_mushrooms)
            else:
                del new_mushrooms

        self.last_time = int(pygame.time.get_ticks())

    def get_key(self, ):
        keyEvents = KeyEvents()
        pressed_key = pygame.key.get_pressed()
        if pressed_key[K_LEFT] or pressed_key[K_a]:
            keyEvents.left = True
        elif pressed_key[K_RIGHT] or pressed_key[K_d]:
            keyEvents.right = True

        if pressed_key[K_UP] or pressed_key[K_w]:
            keyEvents.up = True
        elif pressed_key[K_DOWN] or pressed_key[K_s]:
            keyEvents.down = True

        return keyEvents

    def start(self):
        self.initialize()

        self.last_time = int(pygame.time.get_ticks())

        while True:
            for event in pygame.event.get():
                if event.type == QUIT or (event.type == KEYDOWN and event.key == K_ESCAPE):
                    self.terminate()

            keyEvents = self.get_key()
            elapsed_ms = self.ms_tick()

            # Collision

            for i, apple in enumerate(self.apples):
                if GameObject.collide(self.marisa, apple):
                    self.score += 1
                    collide = True
                    while collide is True:
                        collide = False
                        apple.pos = get_rand_pos(self.window_sz, (30, 30))
                        for mushroom in self.mushrooms:
                            if GameObject.collide(apple, mushroom, r=2000):
                                collide = True
                    self.marisa.get_apple()

            for i, mushroom in enumerate(self.mushrooms):

                if GameObject.collide(self.marisa, mushroom):
                    self.gameover()
                    return

            # Update
            self.marisa.keyEventHandle(keyEvents=keyEvents, elapsed_ms=elapsed_ms)
            self.marisa.sprite_update(keyEvents=keyEvents, elapsed_ms=elapsed_ms)
            self.marisa.location_update()

            # Display
            self.update_display()
            self.marisa.clear()

    def ms_tick(self):
        now = int(pygame.time.get_ticks())
        ret = now - self.last_time
        self.last_time = now
        return ret

    def update_display(self):
        self.display_surf.fill(BLACK)
        self.display_surf.blit(self.background, (0, 0))
        self.drawScore()
        self.drawMarisa()
        self.drawObjs()
        pygame.display.update()

    def gameover(self):
        gameOverFont = pygame.font.Font('freesansbold.ttf', 150)
        gameSurf = gameOverFont.render('Game', True, WHITE)
        overSurf = gameOverFont.render('Over', True, WHITE)
        gameRect = gameSurf.get_rect()
        overRect = overSurf.get_rect()
        gameRect.midtop = (self.window_width / 2, 10)
        overRect.midtop = (self.window_width / 2, gameRect.height + 10 + 25)

        self.display_surf.blit(gameSurf, gameRect)
        self.display_surf.blit(overSurf, overRect)

        self.drawPressKeyMsg()

        pygame.display.update()
        pygame.time.wait(500)

        self.checkForKeyPress()

        while True:
            if self.checkForKeyPress():
                pygame.event.get()
                return

    def terminate(self):
        pygame.quit()
        sys.exit()

    def checkForKeyPress(self):
        if len(pygame.event.get(QUIT)) > 0:
            self.terminate()

        keyUpEvents = pygame.event.get(KEYUP)
        if len(keyUpEvents) == 0:
            return None
        if keyUpEvents[0].key == K_ESCAPE:
            self.terminate()
        return keyUpEvents[0].key

    def drawScore(self):
        score = self.score
        scoreSurf = self.basic_font.render('The number of apples: %d' % (score), True, WHITE)
        scoreRect = scoreSurf.get_rect()
        scoreRect.topleft = (self.window_width - 300, 10)
        self.display_surf.blit(scoreSurf, scoreRect)

    def drawMarisa(self):
        self.display_surf.blit(self.marisa.image, self.marisa.get_pos())

    def drawObjs(self):

        for apple in self.apples:
            self.display_surf.blit(apple.image, apple.get_pos())

        for mushroom in self.mushrooms:
            self.display_surf.blit(mushroom.image, mushroom.get_pos())

    def drawPressKeyMsg(self):
        pressKeySurf = self.basic_font.render('Press a key to play.', True, BLACK)
        pressKeyRect = pressKeySurf.get_rect()
        pressKeyRect.topleft = (self.window_width - 200, self.window_height - 30)
        self.display_surf.blit(pressKeySurf, pressKeyRect)


if __name__ == '__main__':
    MariChanGanbatte = Game()

    while True:
        MariChanGanbatte.start()
        MariChanGanbatte.gameover()
