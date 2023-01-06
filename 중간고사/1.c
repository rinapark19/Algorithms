#include <stdio.h>
#include <stdlib.h>

int arr[501][501];

void right(int n);
void left(int n);
void up(int n);
void down(int n);

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	int i = 0;
	for(i; i < n; i++)
	{
		int j = 0;
		for(j; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
		scanf("\n");
	}
	
	int x = 0, y = 0;
	
	scanf("%d %d", &x, &y);
	
	while(x < 0)
	{
		left(n);
		x++;
	}
	while(x > 0)
	{
		right(n);
		x--;
	}
	while(y < 0)
	{
		up(n);
		y++;
	}
	while(y > 0)
	{
		down(n);
		y--;
	}
	
	int p = 0;
	for(p; p < n; p++)
	{
		int q = 0;
		for(q; q< n; q++)
		{
			printf("%d ", arr[p][q]);
		}
		printf("\n");
	}
}

void right(int n)
{
	int c = n-1;
	int e = n - 1;
	
	while(n > 0)
	{
		int a = arr[n-1][e];
		while(c >= 1)
		{
			arr[n-1][c] = arr[n-1][c-1];
			c--;
		}
		c = e;
		arr[n-1][0] = a;
		n--;
	}
}

void left(int n)
{
	int c = 0;
	int e = n - 1;
	while(n > 0)
	{
		int a = arr[n-1][0];
		while(c <= n-2)
		{
			arr[n-1][c] = arr[n-1][c+1];
			c++;
		}
		c = 0;	
		arr[n-1][e] = a;
		n--;
	}
}

void up(int n)
{
	int r = 0;
	int e = n - 1;
	while(n >= 1)
	{
		int a = arr[0][n-1];
		while(r <= n-1)
		{
			arr[r][n-1] = arr[r+1][n-1];
			r++;
		}
		r = 0;
		arr[e][n-1] = a;
		n--;
	}
}

void down(int n)
{
	int r = n-1;
	int e = n - 1;
	while(n >= 1)
	{
		int a = arr[e][n-1];
		while(r >= 0)
		{
			arr[r][n-1] = arr[r-1][n-1];
			r--;
		}
		r = e;
		arr[0][n-1] = a;
		n--;
	}
}
