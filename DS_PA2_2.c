#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
}Node;


Node *init_node(int data){
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}


Node *init_deque(){
	Node *new_head = init_node(-1);
	new_head->prev = new_head;
	new_head->next = new_head;
	return new_head;
}


void push_front(Node *head, int data) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	
	if(head)
	{
		temp->next = head->next;
		head->next->prev = temp;
		head->next= temp;
		temp->prev = head;
	}
 }


void push_back(Node *head, int data)  {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data =data;
	
	if(head->prev)
	{
		head->prev->next = temp;
		temp->prev = head->prev;
		temp->next = head;
		head->prev = temp;
	}
}


int pop_back(Node *head){
 	Node* temp = head->prev;
	int item;
	
	item = temp->data;
	temp->prev->next = head;
	head->prev = temp->prev;
	free(temp);
	return item;
}


int pop_front(Node *head){
	Node *temp = head->next;
	int item;

	item = temp->data;
	temp->prev->next = temp->next;
	temp->next->prev = head;
	free(temp);
	return item;
}


void print_deque(Node *head)
{
	Node *temp = head->next;
	printf("["); 
	while(1)
	{
		if(temp->data == -1)
		{
			printf("]\n");
			return;
		}
		else
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}


int main(){
	Node *head = init_deque();
	while (1) {
		/* get user input 
		 @ line: user input 
		 @ sz: size of the user input: UNUSED 
		 @ cmd: user command one of the ["push_back" "pop_back" "push_front", "pop_front", "quit"]
		 @ str_data: user input data in string form 
		*/ 
		size_t sz = 0;
		char* line = NULL; 
		char* cmd; 
		char* str_data; 
		getline(&line, &sz, stdin);
		/* parse */
		cmd = strtok(line, " \n"); 
		if (strcmp(cmd, "quit") == 0)
		{
			exit(0);
		}
		else if (strcmp(cmd, "push_back") == 0)
		{
			/* do push_back */ 
			str_data = strtok(NULL, " \n");
			push_back(head, atoi(str_data));
		}
		else if (strcmp(cmd, "push_front") == 0)
		{
			/* do push_front */ 
			str_data = strtok(NULL, " \n");
			push_front(head, atoi(str_data));
		}
		else if (strcmp(cmd, "pop_front") == 0)
		{
			/* do pop_front */ 
			printf("%d\n", pop_front(head));
		}
		else if (strcmp(cmd, "pop_back") == 0)
		{
			/* do pop_back */ 
			printf("%d\n", pop_back(head));
		}
		else
		{
			/* error: user command is not in one of the push, pop or quit*/
			puts("input error"); 
			exit(-1); 
		}
		print_deque(head); 
		free(line); 
	}

	return 0;
}
