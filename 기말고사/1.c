#include <stdio.h>

int p1[501];
int p2[501];

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	int i = 0;
	
	for(i; i < n; i++)
	{
		int a = 0;
		scanf("%d", &a);
		p1[i] = a;
	}
	
	i = 0;
	
	for(i; i < n; i++)
	{
		int a = 0;
		scanf("%d", &a);
		p2[i] = a;
	}
	
	i = 0;
	
	int s1 = 0;
	int s2 = 0;
	
	for(i; i < n; i++)
	{
		if(p1[i] == 1  && p2[i] == 2)
		{
			s2 += 1;
		}
		else if(p1[i] == 2 && p2[i] == 1)
		{
			s1 += 1;
		}
		else if(p1[i] == 1 && p2[i] == 3)
		{
			s1 += 2;
		}
		else if(p1[i] == 3 && p2[i] == 1)
		{
			s2 += 2;
		}
		else if(p1[i] == 3 && p2[i] == 2)
		{
			s1 += 5;
		}
		else if(p1[i] == 2 && p2[i] == 3)
		{
			s2 += 5;
		}
	}
	
	printf("%d %d", s1, s2);
}
