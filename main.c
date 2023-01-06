#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct {
	char t;
	int h;
	int p;
} land;

land L[5000][5000];
int cnt[5000][5000];
int size_n, size_m;

int main()
{
    char cmd_type[11];

    while (1)
    {
        scanf("%s", cmd_type);

        if (!strcmp(cmd_type, "new"))
        {
        	scanf("%d %d", &size_n, &size_m);
        	
        	int i = 0;
			int j = 0;
			for(i; i <= size_n; i++)
			{
    			for(j; j <= size_m; j++)
    			{
        			L[i][j].t = 'P';
       				L[i][j].h = 0;
        			L[i][j].p = 0;
				}
				j = 0;
			}	
        }
        else if (!strcmp(cmd_type, "sett"))
        {
        	int r1, c1, r2, c2;
        	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        	int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
        	
        	char terrain[cnt+1];
        	scanf("%s", terrain);
        	
        	int ind = 0;
        	
        	int i = r1;
        	int j = c1;
        	for(i; i <= r2; i++)
        	{
        		for(j; j <= c2; j++)
        		{
        			L[i][j].t = terrain[ind];
        			ind++;
				}
				j = c1;
			}
        }
        else if (!strcmp(cmd_type, "seth"))
        {
        	int r1, c1, r2, c2;
        	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        	
        	int cnt = (r2 -r1 + 1) * (c2 - c1 + 1);
        	
        	int arr[cnt+1];
        	
        	int i = 0;
        	for(i;i < cnt; i++)
        	{
        		int a;
        		scanf("%d", &a);
        		scanf("\0");
        		arr[i] = a;
			}
			
			int ind = 0;
			
			int i1 = r1;
			int j = c1;
			
			for(i1; i1 <= r2; i1++)
			{
				for(j; j <= c2; j++)
				{
					L[i1][j].h = arr[ind++];
				}
				j = c1;
			}
        }
        else if (!strcmp(cmd_type, "setp"))
        {
        	int r1, c1, r2, c2;
        	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        	
        	int cnt = (r2 -r1 + 1) * (c2 - c1 + 1);
        	
        	int arr[cnt+1];
        	
        	int i = 0;
        	for(i;i < cnt; i++)
        	{
        		int a;
        		scanf("%d", &a);
        		scanf("\0");
        		arr[i] = a;
			}			
			int ind = 0;
			
			int i1 = r1;
			int j = c1;
			for(i1; i1 <= r2; i1++)
			{
				for(j; j <= c2; j++)
				{
					L[i1][j].p = arr[ind];
					ind++;
				}
				j = c1;			
			}
        }
        else if (!strcmp(cmd_type, "climb"))  
        {
        	int i = size_n;
        	int j = size_m;
        	
        	for(i; i >= 1; i--)
        	{
        		for(j; j >=1; j--)
        		{
        			if(L[i][j].h > L[i-1][j].h)
        			{
        				L[i][j].p += L[i-1][j].p;
        				L[i-1][j].p = 0;
					}
					
					if(L[i][j].h > L[i+1][j].h)
					{
						L[i][j].p += L[i+1][j].p;
						L[i+1][j].p = 0;
					}
					
					if(L[i][j].h > L[i][j-1].h)
					{
						L[i][j].p += L[i][j-1].p;
						L[i][j-1].p = 0;
					}
					
					if(L[i][j].h > L[i][j+1].h)
					{
						L[i][j].p += L[i][j+1].p;
						L[i][j+1].p = 0;
					}
				}
				j = size_m;
			}
        	
    	}
        else if (!strcmp(cmd_type, "scatter")) // 간단하게 만들어서 실행 시간 줄이기  
        {
        	int i = 1;
        	int j = 1;
        	int n = 0;
        	for(i; i <= size_n; i++)
        	{
        		for(j; j <= size_m; j++)
        		{
        			if(L[i][j].p != 0)
        			{
        				if(i==1 && j== 1)
        				n = 2;
        				else if(i == size_n && j == size_m)
        					n = 2;
	        			else if(i == 1 && j == size_m)
	        				n = 2;
	        			else if(i == size_n && j==1)
	        				n = 2;
	        			else if(i==1 || j == 1)
	        				n = 3;
	        			else
	        				n = 4;
	        			
	        			int val = L[i][j].p % n;
        				cnt[i][j] = (L[i][j].p - val) / n;
        				L[i][j].p -= (cnt[i][j]*n);
					}
				}
				j = 1;
			}		
			int i1 = 0;
			int j1 = 0;
			for(i1; i1 <= size_n; i1++)
			{
				for(j1; j1 <= size_m; j1++)
				{
					L[i1][j1].p = L[i1][j1].p + cnt[i1][j1-1] + cnt[i1][j1+1] + cnt[i1-1][j1] + cnt[i1+1][j1];	
				}
				j1 = 0;
			}
        }
        else if (!strcmp(cmd_type, "settle")) 
        {
        	int k;
        	scanf("%d", &k);
        	
        	int i = size_n;
        	int j = size_m;
        	int max = 0;
        	int max_n = 0;
        	int max_m = 0;
        	for(i; i >= 1; i--)
        	{
        		for(j; j >= 1; j--)
        		{
        			int sum = 0;
        			sum += L[i][j].p;
        			sum += L[i-k][j].p;
        			sum += L[i+k][j].p;
        			sum += L[i][j+k].p;
        			sum += L[i][j-k].p;
        			sum += L[i+1][j+k].p;
        			sum += L[i-1][j+k].p;
        			sum += L[i+1][j-k].p;
        			sum += L[i-1][j-k].p;
        			
        			if(sum >= max)
        			{
        				max = sum;
        				max_n = i;
        				max_m = j;
					}
				}
				j = size_m;
			}			
			L[max_n][max_m].t = 'C';
        	L[max_n][max_m].p += L[max_n-k][max_m].p;
        	L[max_n-k][max_m].p = 0;
       		L[max_n][max_m].p += L[max_n+k][max_m].p;
       		L[max_n+k][max_m].p = 0;
       		L[max_n][max_m].p += L[max_n][max_m+k].p;
       		L[max_n][max_m+k].p = 0;
      		L[max_n][max_m].p += L[max_n][max_m-k].p;
      		L[max_n][max_m-k].p = 0;
       		L[max_n][max_m].p += L[max_n+1][max_m+k].p;
       		L[max_n+1][max_m+k].p = 0;
      		L[max_n][max_m].p += L[max_n-1][max_m+k].p;
      		L[max_n-1][max_m+k].p = 0;
      		L[max_n][max_m].p += L[max_n+1][max_m-k].p;
      		L[max_n+1][max_m-k].p = 0;
      		L[max_n][max_m].p += L[max_n-1][max_m-k].p;
			L[max_n-1][max_m-k].p = 0;
        }
        else if (!strcmp(cmd_type, "print"))
        {
        	int n, m;
        	scanf("%d %d", &n, &m);
        	
        	printf("%c %d %d\n", L[n][m].t, L[n][m].p, L[n][m].h);
        }
        else if (!strcmp(cmd_type, "count"))
        {
        	int p_count = 0;
        	int m_count = 0;
        	int c_count = 0;
        	      	
        	int i = 0;
        	int j = 0;
        	for(i; i <= size_n; i++)
        	{
        		for(j; j <= size_m; j++)
        		{
        			land L1 = L[i][j];
        			if(L1.t == 'P')
        			{
        				p_count += L1.p;
					}
					else if(L1.t == 'M')
					{
						m_count += L1.p;
					}
					else if(L1.t == 'C')
					{
						c_count += L1.p;
					}
					
				}
				j = 0;
			}		
			printf("%d %d %d\n", p_count, m_count, c_count);        	
        }
        else if (!strcmp(cmd_type, "exit"))
        {
            break;
        }
    }
    return 0;
}
