#include "rbtree.h"
#include "stddef.h"
#include <stdio.h>
#include <stdlib.h>

info* newInfo(int id, char* name, char src, char dst, int date) // make new node for rb-tree
{
	info* n = malloc(sizeof(info));
	n->p = NULL; // initalize each pointer
	n->l = NULL;
	n->r = NULL;

	n->id = id; // initialize reservation information
	n->name = name;
	n->src = src;
	n->dst = dst;
	n->date = date;
	n->color = 0;

	return n;
}
rbtree* newRbtree() // make new rb-tree
{
	rbtree* t = malloc(sizeof(rbtree));
	info* nilNode = malloc(sizeof(info));

	nilNode->p = NULL; // initialize each value
	nilNode->l = NULL;
	nilNode->r = NULL;
	nilNode->id = 0;
	nilNode->color = 1;
	t->NIL = nilNode;
	t->root = t->NIL;

	return t;
}
void LEFT_ROTATE(rbtree* t, info* x)
{
	info* y = x->r;
	x->r = y->l;
	if (y->l != t->NIL)
	{
		y->l->p = x;
	}
	y->p = x->p;
	if (x->p == t->NIL)
	{
		t->root = y;
	}
	else if (x == x->p->l)
	{
		x->p->l = y;
	}
	else
	{
		x->p->r = y;
	}
	y->l = x;
	x->p = y;
}
void RIGHT_ROTATE(rbtree* t, info* x)
{
	info* y = x->l;
	x->l = y->r;

	if (y->r != t->NIL)
	{
		y->r->p = x;
	}
	y->p = x->p;
	if (x->p == t->NIL)
	{
		t->root = y;
	}
	else if (x == x->p->l)
	{
		x->p->l = y;
	}
	else
	{
		x->p->r = y;
	}
	y->r = x;
	x->p = y;
}
void RB_INSERT_FIXUP(rbtree* t, info* z)
{
	while (z->p->color == 0)
	{
		if (z->p == z->p->p->l)
		{
			info* y = z->p->p->r;
			if (y->color == 0)
			{
				z->p->color = 1;
				y->color = 1;
				z->p->p->color = 0;
				z = z->p->p;
			}
			else
			{
				if (z == z->p->r)
				{
					z = z->p;
					LEFT_ROTATE(t, z);
				}
				z->p->color = 1;
				z->p->p->color = 0;
				RIGHT_ROTATE(t, z->p->p);
			}

		}
		else
		{
			info* y = z->p->p->l;
			if (y->color == 0)
			{
				z->p->color = 1;
				y->color = 1;
				z->p->p->color = 0;
				z = z->p->p;
			}
			else
			{
				if (z == z->p->l)
				{
					z = z->p;
					RIGHT_ROTATE(t, z);
				}
				z->p->color = 1;
				z->p->p->color = 0;
				LEFT_ROTATE(t, z->p->p);
			}
		}
	}
	t->root->color = 1;
}
void RB_INSERT(rbtree* t, info* z)
{
	info* y = t->NIL;
	info* x = t->root;

	while (x != t->NIL)
	{
		if (z->id == x->id) return; // the id value of each node for rb-tree is used for insertion
		y = x;
		if (z->id < x->id)
		{
			x = x->l;
		}
		else
			x = x->r;
	}
	z->p = y;

	if (y == t->NIL)
		t->root = z;
	else if (z->id < y->id)
		y->l = z;
	else
		y->r = z;

	z->l = t->NIL;
	z->r = t->NIL;
	z->color = 0;
	RB_INSERT_FIXUP(t, z);
}
void PRINT_BST(rbtree* t, info* n, int space)
{
	char red = 'R';
	char black = 'B';

	if (n == t->NIL) return;

	space += 10;
	PRINT_BST(t, n->r, space);
	printf("\n");
	for (int i = 10; i < space; i++)
	{
		printf(" ");
	}
	if (n->color == 0) printf("%c", red);
	else printf("%c", black);
	printf("%d\n", n->id);
	PRINT_BST(t, n->l, space);
}
void RB_DELETE_FIXUP(rbtree* t, info* x)
{
	while (x != t->root && x->color == 1)
	{
		info* w;
		if (x == x->p->l)
		{
			w = x->p->r;
			if (w->color == 0)
			{
				w->color = 1;
				x->p->color = 0;
				LEFT_ROTATE(t, x->p);
				w = x->p->r;
			}

			if (w->l->color == 1 && w->r->color == 1)
			{
				w->color = 0;
				x = x->p;
			}
			else if (w->r->color == 1)
			{
				w->l->color = 1;
				w->color = 0;
				RIGHT_ROTATE(t, w);
				w = x->p->r;
			}
			w->color = x->p->color;
			x->p->color = 1;
			w->r->color = 1;
			LEFT_ROTATE(t, x->p);
			x = t->root;
		}
		else
		{
			w = x->p->l;
			if (w->color == 0)
			{
				w->color = 1;
				x->p->color = 0;
				RIGHT_ROTATE(t, x->p);
				w = x->p->l;
			}

			if (w->r->color == 1 && w->l->color == 1)
			{
				w->color = 0;
				x = x->p;
			}
			else if (w->l->color == 1)
			{
				w->r->color = 1;
				w->color = 0;
				LEFT_ROTATE(t, w);
				w = x->p->l;
			}
			w->color = x->p->color;
			x->p->color = 1;
			w->l->color = 1;
			RIGHT_ROTATE(t, x->p);
			x = t->root;
		}
	}
	x->color = 1;
}
void RB_TRANSPLANT(rbtree* t, info* u, info* v)
{
	if (u->p == t->NIL)
		t->root = v;
	else if (u == u->p->l)
		u->p->l = v;
	else
		u->p->r = v;
	v->p = u->p;
}
void RB_DELETE(rbtree* t, int key)
{
	info* z = t->root;
	info* temp = t->NIL;
	info* x = NULL;
	char targetColor;

	while (key != z->id)
	{
		if (z->id > key)
			z = z->l;
		else
			z = z->r;
	}
	targetColor = z->color;

	if (z->l = t->NIL)
	{
		x = z->r;
		RB_TRANSPLANT(t, z, z->r);
	}
	else if (z->r == t->NIL)
	{
		x = z->l;
		RB_TRANSPLANT(t, z, z->l);
	}
	else
	{
		temp = z->r;
		while (temp->l != t->NIL)
			temp = temp->l;
		targetColor = temp->color;
		x = temp->r;

		RB_TRANSPLANT(t, temp, temp->r);
		temp->r = z->r;
		temp->r->p = temp;

		RB_TRANSPLANT(t, z, temp);
		temp->l = z->l;
		temp->l->p = temp;
		temp->color = z->color;
	}

	if (targetColor == 1)
		RB_DELETE_FIXUP(t, x);
}