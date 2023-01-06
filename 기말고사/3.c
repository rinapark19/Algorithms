#include <stdio.h>

int arr[100000];
int oven[100000];

int main()
{
	int m = 0, n = 0;
	
	scanf("%d", &m);
	scanf("%d", &n);
	
	int check = 0;
	
	int i = 0;
	for(i; i < m; i++)
	{
		int a = 0;
		scanf("%d", &a);
		oven[i] = a;
	}
	arr[0] = 0;
	
	i = 1;
	
	int ans = 0;
	
	for(i; i <= 100000; i++)
	{
		int sum = 0;
		sum += arr[i-1];
		
		int j = 0;
		
		for(j; j < m; j++)
		{
			if(i % oven[j] == 0)
				sum += 1;
		}
		
		arr[i] = sum;
		//printf("%d : %d\n",i, arr[i]);
		
		if(arr[i] >= n)
		{
			ans = i;
			break;	
		}
	}
	
	printf("%d", ans);
}
