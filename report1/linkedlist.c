#include <stdio.h>
#include <stdlib.h>

int length = 0; // the length of linked list
int A[60]; // array for contain 60 integer values

typedef struct Node { // structure for linked list node
	int data;
	struct Node* next;
}Node;

void insert(Node** head, int data) // add values to liked list
{
	if (*head == NULL) // if there is no values
	{
		*head = (Node*)malloc(sizeof(Node)); // add head node
		(*head)->data = data;
		(*head)->next = NULL;
	}
	else
	{
		Node* cur = *head; // add node to end of the linked list
		while (cur->next != NULL)
		{
			cur = cur->next;
		}

		cur->next = (Node*)malloc(sizeof(Node));
		cur->next->data = data;
		cur->next->next = NULL;
	}
	length++;
}

void delete(Node** head) // delete 3rd last node
{
	Node* cur = *head;
	Node* before = *head;
	cur = cur->next;
	int i;

	for (i = 1; i < length - 3; i++) // move pointer
	{
		cur = cur->next;
		before = before->next;
	}

	before->next = cur->next; 
	free(cur); // delete node
	length--;
}

void print(Node** head) // print linked list's first 3rd, second 3rd, third 3rd value
{
	int first_3, second_3, third_3; // linked list's first 3rd, second 3rd, third 3rd value
	int num_line = length / 3; // each line has num_line values
	printf("num_line: %d\n", num_line);

	first_3 = 3;
	second_3 = num_line + 3;
	third_3 = num_line * 2 + 3;

	Node* cur = *head;

	int i;
	for (i = 1; i < first_3; i++) // print each values
	{
		cur = cur->next;
	}
	printf("%d\n", cur->data);

	cur = *head;

	for (i = 1; i < second_3; i++)
	{
		cur = cur->next;
	}
	printf("%d\n", cur->data);

	cur = *head;

	for (i = 1; i < third_3; i++)
	{
		cur = cur->next;
	}
	printf("%d\n", cur->data);
}

int main()
{
	srand(time(NULL));
	Node* head = NULL;
	int i, j;

	for (i = 0; i < 100; i++)
	{
		A[i] = rand() % 1000;

		for (j = 0; j < i; j++)
		{
			if (A[i] == A[j]) i--;
		}
	}

	for (i = 0; i < 60; i++)
	{
		insert(&head, A[i]);
	}

	delete(&head);
	
	print(&head);

	delete(&head);

	print(&head);

	delete(&head);

	print(&head);

}