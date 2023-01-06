#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	float data[1000];
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

float Pop(Stack * pstack)
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

float Peek(Stack * pstack)
{
	if(Empty(pstack) == 1)
	{
		printf("Error: stack is empty");
		exit(-1);
	}
	else
	{
		return pstack->data[pstack->top];
	}
}

int rank(char op)
{
	switch(op)
	{
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
	}
	return -1;
}

int highrank(char op1, char op2)
{
	int rank1 = rank(op1);
	int rank2 = rank(op2);
	
	if(rank1 > rank2)
		return 1;
	else if (rank1 < rank2)
		return -1;
	else
		return 0;
 }

void Convert(char input[])
{
	Stack stack;
	int len = strlen(input);
	char * convert = (char*)malloc(len+1);
	
	int i = 0;
	int idx = 0;
	char cnt;
	char next;
	char Op;
	
	memset(convert, 0, sizeof(char)*len+1);
	SInit(&stack);
	
	for(i=0; i<len; i++)
	{
		cnt = input[i];
		next = input[i+1]; 
		
		if(isdigit(cnt) && isdigit(next))
		{
			convert[idx++] = 'Q';
			while(isdigit(cnt))
			{
				cnt = input[i];
				convert[idx++] = cnt;
				i += 1;
				cnt = input[i];
			}
			convert[idx++] = 'Q';
		}
				
		else if(isdigit(cnt))
		{
			convert[idx++] = cnt;
		}
		
		else if(cnt == ' ')
		{
			continue;
		}
		
		else
		{
			while(Empty(&stack) == 0 && highrank(Peek(&stack), cnt) >= 0)
				convert[idx++] = Pop(&stack);
			
			Push(&stack, cnt);
		}
	}
	
	while(Empty(&stack) == 0)
		convert[idx++] = Pop(&stack);
	
	strcpy(input, convert);
	free(convert);
 }
 
 float Calculate(char input[])
{
	Stack stack;
	int len = strlen(input);
	int i;
	char cnt;
	float op1, op2;
	
	
	SInit(&stack);
	
	for(i=0; i<len; i++)
	{
		cnt = input[i];
		
		if(input[i] == 'Q')
		{
			char temp[1000] = {NULL};
			i = i +1;
			int j = 0;
			while(isdigit(input[i]))
			{
				temp[j] = input[i];
				i = i + 1;
				j = j + 1;
			}
			
			float a = atof(temp);
			Push(&stack, a);			
		}
		else if(isdigit(cnt))
		{
			Push(&stack, cnt - '0');
		}
		else
		{
			op2 = Pop(&stack);
			op1 = Pop(&stack);
						
			switch(cnt)
			{
				case '+':
					Push(&stack, op1+op2);
					break;
				case '-':
					Push(&stack, op1-op2);
					break;
				case '*':
					Push(&stack, op1*op2);
					break;
				case '/':
					Push(&stack, op1/op2);
					break;
			}
		} 
	}	
	return Pop(&stack);
 }
 
 int main()
 {
 	char input[100];
 	gets(input);
 	Convert(input);
 	float answer = Calculate(input);
 	printf("%.2f", (float)answer);
 }
