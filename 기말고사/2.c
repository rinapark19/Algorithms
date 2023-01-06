#include <stdio.h>

float arr[10000000];

int cmp(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	int i = 0;
	for(i; i < n; i++)
	{
		float a = 0;
		scanf("%f", &a);
		arr[i] = a;
	}
	
	qsort(arr, n, sizeof(int), cmp);
	
	float median = arr[n/2];
	
	printf("%.1f", median);
}
