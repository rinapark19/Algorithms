import random
from types import SimpleNamespace
from math import cos, sin
import numpy as np

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

PI = 3.141592
WIDTH = 1024
HEIGHT = 768


def KeyEvents():
    return SimpleNamespace(up=False, down=False, left=False, right=False)


def angular_tranform(angle, arr):
    x = PI * (angle / 180)
    R = np.array([[cos(x), -sin(x)], [sin(x), cos(x)]]).T
    return np.array(arr).dot(R).T.tolist()


def add2d(x, y):
    return [x[0] + y[0], x[1] + y[1]]


def get_rand_pos(sz, obj_size):
    x = random.randint(0, sz[0] - obj_size[0] + 1)
    y = random.randint(0, sz[1] - obj_size[1] + 1)
    return [x, y]
