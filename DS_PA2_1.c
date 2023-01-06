#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
	int data[1000];
	int top;
} Stack;

void SInit(Stack * pstack)
{
	pstack->top = -1;
}

int Empty(Stack * pstack)
{
	if(pstack->top == -1)
		return 1;
	else
		return 0;
}

void Push(Stack * pstack, float data)
{
	pstack->top += 1;
	pstack->data[pstack->top] = data;
}

int Pop(Stack * pstack)
{
	if(Empty(pstack) == 1)
	{
		printf("Error: stack is empty");
		exit(-1);
	}
	else
	{
		int del = pstack->top;
		pstack->top -= 1;
		return pstack->data[del];
	}
}

void printS(Stack * pstack, int count)
{
	int arr[count];
	int i = count;
	for(i; i > 0; i--)
	{
		arr[i-1] = Pop(pstack);
	}
	int j = 0;
	for(j; j < count; j++)
	{
		printf("/");
		printf("%d", arr[j]);
		
	}
}

int main()
{
	Stack stack;
	SInit(&stack);
	int count = 0;
	
	while(1)
{
	size_t sz = 0;
	char* line = NULL;
	char* cmd;
	char* str_data;
	getline(&line, &sz, stdin);
	
	cmd = strtok(line, " \n");
	if(strcmp(cmd, "cd") == 0)
	{
		str_data = strtok(NULL, " \n");
		if(strcmp(str_data, "..") == 0)
		{
			Pop(&stack);
			count--;
		}
		else
		{
			int a = atoi(str_data);
			Push(&stack, a);
			count++;
		}
	}
	else if(strcmp(cmd, "pwd") == 0)
	{
		printf("/home/user");
		while(Empty(&stack) == 0)
		{
			printS(&stack, count);
		}
		return 0;
	}
	free(line);
}
}
