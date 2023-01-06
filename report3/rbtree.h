// header file for rb-tree

typedef struct info { // node for rb-tree that contains all information about reservation
	struct info* p;
	struct info* l;
	struct info* r;
	int id;
	char* name;
	char src;
	char dst;
	int date;
	int road[40];
	int time[40];
	int color;
} info;

typedef struct rbtree {
	info* root;
	info* NIL;
} rbtree;

info* newInfo(int id, char* name, char src, char dst, int date);
rbtree* newRbtree();
void LEFT_ROTATE(rbtree* t, info* x);
void RIGHT_ROTATE(rbtree* t, info* x);
void RB_INSERT_FIXUP(rbtree* t, info* z);
void RB_INSERT(rbtree* t, info* z);
void PRINT_BST(rbtree* t, info* n, int space);
void RB_DELETE_FIXUP(rbtree* t, info* x);
void RB_TRANSPLANT(rbtree* t, info* u, info* v);
void RB_DELETE(rbtree* t, int key);