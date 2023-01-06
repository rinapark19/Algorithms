#include <stdio.h>
#include <string.h> 
int arr[5001][5001] = {0};

int main()
{
	int m = 0, n = 0;
	scanf("%d %d", &m, &n);
	
	char input[5001];
	
	int i = 0, j = 0;
	for(i; i < m; i++)
	{
		scanf("%s", &input);
		
		for(j; j < n; j++)
		{
			arr[i][j] = input[j] - '0';
		}
		j = 0;
	}
	
	i = 0;
	j = 0;
	
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int f = 0;
	int max = 0;
	
	int lx = 0;
	int ly = 0;
	int rx = 0;
	int ry = 0;
	
	
	for(i; i < m; i++)
	{
		for(j; j < n; j++)
		{
			if(arr[i][j] == 0) continue;
			
			x1 = i;
			y1 = j;
			
			int a = m - 1;
			int b = n - 1;
			
			for(a; a>=0 && a >= i; a--)
			{
				for(b; b>=0 && b >= j; b--)
				{
					if(arr[a][b] == 0) continue;
					
					x2 = a;
					y2 = b;
					
					int check1 = 1;
					int check2 = 1;
					int check3 = 1;
					int check4 = 1;
					
					int p = x1;
					int q = y1;
					
					for(q; q <= y2; q++) // 위쪽 가로 
					{
						if(arr[p][q] == 0)
						{
							check1 = 0;
							break;
						}
					}
					if(check1 == 0) continue;
					
					
					p = x2, q = y1;
					
					for(q; q <= y2; q++) // 아래쪽 가로 
					{
						if(arr[p][q] == 0)
						{
							check2 = 0;
							break;
						}
					}
					
					if(check2 == 0) continue;
					
					
					p = x1, q = y1;
					
					for(p; p <= x2; p++) // 왼쪽 세로 
					{
						if(arr[p][q] == 0)
						{
							check3 = 0;
							break;
						}
					}
					
					if(check3 == 0) continue;
					
					
					p = x1, q = y2;
					
					for(p; p <= x2; p++) // 오른쪽 세로  
					{
						if(arr[p][q] == 0)
						{
							check4 = 0;
							break;
						}
					} 
					
					if(check4 == 0) continue;
					
					
					if(check1 == 1 && check2 == 1 && check3 == 1 && check4 == 1)
					{
						f = (x2 - x1 + 1) * (y2 - y1 + 1);
						
						if(f > max)
						{
							lx = x1 + 1;
							ly = y1 + 1;
							rx = x2 + 1;
							ry = y2 + 1;
							max = f;
						}
					}
				}
				b = n - 1;
			}
			a = m - 1;
		}
		j = 0;
	}
	
	printf("%d %d %d %d", lx, ly, rx, ry); 
	
}
