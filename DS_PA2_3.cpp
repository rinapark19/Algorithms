#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _node
{
	int coef;
	int expon;
	struct _node *next;
} Node;

typedef struct _List
{
	Node *front;
	Node *rear;
	Node *pointer;
} List;

void init(List * plist)
{
	plist->front = NULL;
	plist->rear = NULL;
	plist->pointer = NULL;
}

int empty(List * plist)
{
	if(plist->front == NULL)
		return 1; // true
	else
		return 0;
}

void insert(List * plist, int coef, int expon) // create_node, store_quotient, 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->coef = coef;
	newNode->expon = expon;
	
	if(empty(plist) == 1)
	{
		plist->front = newNode;
		plist->rear = newNode;
		plist->pointer = newNode;
	}
	else
	{
		plist->rear->next = newNode;
		plist->rear = newNode;
	}
	plist->pointer = plist->front;
}

void show(List * plist)
{
	while(plist->pointer != NULL)
	{
		printf("%d ", plist->pointer->coef);
		printf("%d", plist->pointer->expon);
		printf("\n");
		plist->pointer = plist->pointer->next;
	}
	plist->pointer = plist->front;
}

void form(int expon, int coef, List * plist)
{
	while(plist->pointer != NULL)
	{
		plist->pointer->expon = plist->pointer->expon + expon;
		plist->pointer->coef = plist->pointer->coef * coef;
		plist->pointer = plist->pointer->next;
	}
	plist->pointer = plist->front;
}

void copy(List * plist1, List * plist2)
{
	while(plist1->pointer != NULL)
	{
		int expon = plist1->pointer->expon;
		int coef = plist1->pointer->coef;
		insert(plist2, coef, expon);
		plist1->pointer = plist1->pointer->next;
	}
	plist1->pointer = plist1->front;
	plist2->pointer = plist2->front;
}

void sub(List * plist1, List * plist2, List * plist3)
{
	while(plist1->pointer != NULL && plist2->pointer != NULL)
	{
		if(plist1->pointer->expon > plist2->pointer->expon)
		{
			int coef = plist1->pointer->coef;
			int expon = plist1->pointer->expon;
			insert(plist3, coef, expon);
			plist1->pointer = plist1->pointer->next;
		}
		else if(plist1->pointer->expon < plist2->pointer->expon)
		{
			int coef = plist2->pointer->coef;
			int expon = plist2->pointer->expon;
			insert(plist3, coef, expon);
			plist2->pointer = plist2->pointer->next;
		}
		else
		{
			if(plist1->pointer->coef - plist2->pointer->coef != 0)
			{
				int coef = (plist1->pointer->coef) - (plist2->pointer->coef);
				int expon = plist1->pointer->expon;
				insert(plist3, coef, expon);
				plist1->pointer = plist1->pointer->next;
				plist2->pointer = plist2->pointer->next;
			}
			else
			{
				plist1->pointer = plist1->pointer->next;
				plist2->pointer = plist2->pointer->next;
			}
		}
	}
	
	while(plist1->pointer != NULL || plist2->pointer != NULL)
	{
		if(plist1->pointer != NULL)
		{
			int coef = plist1->pointer->coef;
			int expon = plist1->pointer->expon;
			insert(plist3, coef, expon);
			plist1->pointer = plist1->pointer->next;
		}
		if(plist2->pointer != NULL)
		{
			int coef = plist2->pointer->coef;
			int expon = plist2->pointer->expon;
			insert(plist3, coef, expon);
			plist2->pointer = plist2->pointer->next;
		}
	}
	plist1->pointer = plist1->front;
	plist2->pointer = plist2->front;
	plist3->pointer = plist3->front;
}

void divide(List * plist1, List * plist2)
{
	List rem;
	init(&rem);
	List quo;
	init(&quo);
	
	List q;
	init(&q);
	List r;
	init(&r);
	
	copy(plist1, &q);
	copy(plist2, &r);
	
	while(q.pointer != NULL && q.pointer->expon >= plist2->pointer->expon)
	{
		int expon = (q.pointer->expon) - (plist2->pointer->expon);
		int coef = (q.pointer->coef) / (plist2->pointer->coef);
		
		insert(&quo, coef, expon);
		
		List q2;
		init(&q2);
		copy(&r, &q2);
		form(expon, coef, &q2);
		
		List store;
		init(&store);
		sub(&q, &q2, &store);
		
		init(&q);
		copy(&store, &q);
	}
	
	if(empty(&quo) == 1)
	{
		insert(&quo, 0, 0);
	}
	show(&quo);
	
	copy(&q, &rem);
	if(empty(&rem) == 1)
	{
		insert(&rem, 0, 0);
	}
	show(&rem);
	
	plist1->pointer = plist1->front;
	plist2->pointer = plist2->front;
}

int main()
{
	List poly1;
	init(&poly1);
	List poly2;
	init(&poly2);
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	
	while(1)
	{
		size_t sz = 0;
		char *line = NULL;
		getline(&line, &sz, stdin);
		count2++;
		int len = strlen(line);
		
		if(len < 3)
		{
			count1++;
			int n = line[0] - '0';
			count3 += n;
		}
		else if(count1 == 1)
		{
			int coef = line[0] - '0';
			int expon = line[2] - '0';
			insert(&poly1, coef, expon);
		}
		else if(count1 == 2)
		{
			int coef = line[0] - '0';
			int expon = line[2] - '0';
			insert(&poly2, coef, expon);
		}
		free(line);
		
		if(count1 == 2 && count2 == count3+2)
		{
			break;
		}
		
	}
	divide(&poly1, &poly2);
}
