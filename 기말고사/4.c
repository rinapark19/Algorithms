#include <stdio.h>
int arr[500];
int dp[500];

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	int i = 0;
	for(i; i <n; i++)
	{
		int a = 0;
		scanf("%d", &a);
		arr[i] = a;
	}
	
	int max = 0;
	int saved = 0;
	dp[0] = 1;
	
	i = 1;
	for(i; i < n; i++)
	{
		dp[i] = 1;
		int j = 0;
		for(j = 0; j < i; j++)
		{
			if(arr[i] >= arr[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		if(arr[i] < arr[i-1])
		{
			dp[i] = max + 1;
		}
		if(dp[i] > max) max = dp[i];
 	}
 	printf("%d", max);
}
