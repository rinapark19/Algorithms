#include <stdio.h>
#include <stdlib.h>

#define size1 5 // for the first hash function
#define size2 7 // for the second hash function
#define size3 13 // for the thirt hash function


typedef struct Node { // define the structure of hash table
	int val;
	struct Node* next;
} Node;

Node* insert(Node* table, int hash_index, int val) // insert key to hash table
{
	Node* nn, * cur; // declare pointer of new node, and current node
	nn = (Node*)malloc(sizeof(Node));

	nn->val = val;
	nn->next = NULL;

	if (table[hash_index].next == NULL) // if table is empty
	{
		table[hash_index].next = nn; // add node just behind the table
		return table;
	}

	cur = table[hash_index].next;
	while (cur->next != NULL) // else -> move to the end of the linked list
	{
		cur = cur->next;
	}
	cur->next = nn; // add node
	return table;
}

void print_table(Node* table, int table_range) 
{
	int i;
	Node* cur;
	int longest = 0;
	int shortest = 10;
	int average = 0;

	for (i = 0; i < table_range; i++)
	{
		int length = 0;

		if (table[i].next == NULL) // if there is no node
		{
			printf("%d: \n", i);
			continue;
		}
		
		cur = table[i].next;
		printf("%d: ", i); // print the index

		while (cur != NULL) // print each linked list
		{
			printf("%d ", cur->val);
			cur = cur->next;
			length++;
		}
		printf("\n");
		
		if (length > longest) longest = length;
		if (length < shortest) shortest = length;
		average += length;
	}
	
	average = average / table_range;
	printf("\nThe length of the longest chain: %d\n", longest);
	printf("The length of the shortest chain: %d\n", shortest);
	printf("The average length of the hash table: %d\n", average);

}

int main()
{
	Node* table1; // declare the table(the first hash table)
	Node* table2; // the second hash table
	Node* table3; // the third hash table
	int i, j;

	table1 = (Node*)malloc(size1 * sizeof(Node)); // initialize the table
	table2 = (Node*)malloc(size2 * sizeof(Node));
	table3 = (Node*)malloc(size3 * sizeof(Node));
	for (i = 0; i < size1; i++)
	{
		table1[i].next = NULL;
	}
	for (i = 0; i < size2; i++)
	{
		table2[i].next = NULL;
	}
	for (i = 0; i < size3; i++)
	{
		table3[i].next = NULL;
	}

	int A[50] = { 0 };
	for (i = 0; i < 50; i++) // fill a with random values
	{
		A[i] = rand() % 1000;

		for (j = 0; j < i; j++)
		{
			if (A[i] == A[j]) i--;
		}
	}

	for (i = 0; i < 50; i++) // insert each value
	{
		table1 = insert(table1, A[i] % size1, A[i]); // the first hash function
		table2 = insert(table2, A[i] % size2, A[i]); // the second hash function
		table3 = insert(table3, A[i] % size3, A[i]); // the third hash function
	}

	printf("The first hash table (K mod 5)\n");
	print_table(table1, size1);
	printf("\nThe second hash table (K mod 7)\n");
	print_table(table2, size2);
	printf("\nThe third hash table (K mod 13)\n");
	print_table(table3, size3);
}