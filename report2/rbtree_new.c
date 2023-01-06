#include <stdio.h>
#include <stdlib.h>

typedef struct node // structure for red-black tree node
{
	struct node* p; // parent node
	struct node* l; // left-child node
	struct node* r; // right-child node
	int data;
	int color; // 0: red 1: black
} node;

typedef struct rbtree // structure for red-black tree
{
	node* root;
	node* NIL;
} rbtree;

node* newNode(int data) // make new node
{
	node* n = malloc(sizeof(node));
	n->p = NULL; // initialize each value
	n->l = NULL;
	n->r = NULL;
	n->data = data;
	n->color = 0;

	return n;
}

rbtree* newRbtree() // make new rbtree
{
	rbtree* t = malloc(sizeof(rbtree));
	node* nilNode = malloc(sizeof(node));

	nilNode->p = NULL; // initialize each value
	nilNode->l = NULL;
	nilNode->r = NULL;
	nilNode->data = 0;
	nilNode->color = 1;
	t->NIL = nilNode;
	t->root = t->NIL; 

	return t;
}

void LEFT_ROTATE(rbtree* t, node* x) 
{
	node* y = x->r;
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

void RIGHT_ROTATE(rbtree* t, node* x)
{
	node* y = x->l;
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

void RB_INSERT_FIXUP(rbtree* t, node* z)
{
	while (z->p->color == 0)
	{
		if (z->p == z->p->p->l)
		{
			node* y = z->p->p->r;
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
			node* y = z->p->p->l;
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

void RB_INSERT(rbtree* t, node* z)
{
	node* y = t->NIL;
	node* x = t->root;

	while (x != t->NIL)
	{
		if (z->data == x->data) return;
		y = x;
		if (z->data < x->data)
		{
			x = x->l;
		}
		else
			x = x->r;
	}
	z->p = y;

	if (y == t->NIL)
		t->root = z;
	else if (z->data < y->data)
		y->l = z;
	else
		y->r = z;

	z->l = t->NIL;
	z->r = t->NIL;
	z->color = 0;
	RB_INSERT_FIXUP(t, z);
}

void PRINT_BST(rbtree* t, node *n, int space)
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
	printf("%d\n", n->data);
	PRINT_BST(t, n->l, space);
}

void RB_DELETE_FIXUP(rbtree* t, node* x)
{
	while (x != t->root && x->color == 1)
	{
		node* w;
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

void RB_TRANSPLANT(rbtree* t, node* u, node* v)
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
	node* z = t->root;
	node* temp = t->NIL;
	node* x = NULL;
	char targetColor;

	while (key != z->data)
	{
		if (z->data > key)
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

int TREE_SEARCH(rbtree* t, node* n, int key)
{
	if (n == t->NIL || key == n->data)
		return key;
	
	if (key < n->data)
		return TREE_SEARCH(t, n->l, key);
	else
		return TREE_SEARCH(t, n->r, key);
}

int TREE_SUCCESSOR(rbtree* t, node* n, int key)
{
	if (n->r != t->NIL)
	{
		while (n->l != t->NIL)
			n = n->l;
		return n->data;
	}
	node* y = n->p;
	while (y != t->NIL && n == y->r)
	{
		n = y;
		n = y->p;
	}
	return y->data;
}

int TREE_PREDECESSOR(rbtree* t, node* n, int key)
{
	if (n->l != t->NIL)
	{
		while (n->r != t->NIL)
		{
			n = n->r;
		}
		return n->data;
	}
	node* y = n->p;
	while (y != t->NIL && n == y->l)
	{
		n = y;
		n = y->p;
	}
	return y->data;
}

int NEAREST_NEIGHBOR(rbtree* t, int key)
{
	int y1 = TREE_SEARCH(t, t->root, key);
	int y2 = TREE_SUCCESSOR(t, t->root, key);
	int y3 = TREE_PREDECESSOR(t, t->root, key);

	int d1 = y1 - key; // get each differences
	int d2 = y2 - key;
	int d3 = y3 - key;

	if (d1 < 0) d1 = -d1; // make all number unsigned
	if (d2 < 0) d2 = -d2;
	if (d3 < 0) d3 = -d3;

	if (d1 < d2 && d1 < d3) return y1; // return smallest value
	if (d2 < d1 && d2 < d3) return y2;
	if (d3 < d1 && d3 < d2) return y3;
}

int main()
{
	rbtree* t = newRbtree();

	int i, j;

	int A[15] = { 0 };
	for (i = 0; i < 15; i++) // fill a with random values
	{
		A[i] = rand() % 50;

		for (j = 0; j < i; j++)
		{
			if (A[i] == A[j]) i--;
		}
	}

	printf("\nNumber 2: \n");
	for (i = 0; i < 15; i++)
	{
		node* a;
		a = newNode(A[i]);
		RB_INSERT(t, a);
	}

	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nNumber 3: \n");
	printf("Add 13");
	node* b = newNode(13);
	RB_INSERT(t, b);
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nAdd 22");
	b = newNode(22);
	RB_INSERT(t, b);
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nAdd 21");
	b = newNode(21);
	RB_INSERT(t, b);
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nAdd 11");
	b = newNode(11);
	RB_INSERT(t, b);
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nAdd 45");
	b = newNode(45);
	RB_INSERT(t, b);
	PRINT_BST(t, t->root, 0);
	printf("======================================");

	printf("\nNumber 4: \n");
	printf("The first result: %d\n", NEAREST_NEIGHBOR(t, 5));
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nThe second result: %d\n", NEAREST_NEIGHBOR(t, 23));
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nThe third result: %d\n", NEAREST_NEIGHBOR(t, 38));
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	
	printf("\nNumber 5: \n");
	printf("Delete 13");
	RB_DELETE(t, 13);
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nDelete 22");
	RB_DELETE(t, 22);
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nDelete 45");
	RB_DELETE(t, 45);
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nDelete 11");
	RB_DELETE(t, 11);
	PRINT_BST(t, t->root, 0);
	printf("======================================");
	printf("\nDelete root");
	RB_DELETE(t, t->root->data);
	PRINT_BST(t, t->root, 0);
	printf("======================================");

}