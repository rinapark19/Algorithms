#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

#define QUEUE_SIZE 1000

typedef struct item_t_ {
	int r, c, color;
} item_t;

typedef struct queue_t_ {
	item_t items[QUEUE_SIZE];
	size_t front, rear;
} queue_t;

int p[1000][1000];
int n; 
int visited[1000][1000];
int color[255];

void q_init(queue_t *q)
{
	q->front = q->rear = 0;
}

int q_enqueue(queue_t *q, item_t item)
{
	if (q->rear >= QUEUE_SIZE) return -1;
	q->items[q->rear++] = item;
	return 0;
}

int q_is_empty(queue_t *q)
{
	return q->rear == q->front;
}

int q_dequeue(queue_t *q, item_t* res)
{
	if(q_is_empty(q))
		return -1;
	
	*res = q->items[q->front++];
	return 0;
}

void explore(int r, int c, int color)
{
	queue_t queue;
	int dr[] = {0, -1, 0, 1}, dc[] = {-1, 0, 1, 0};
	
	q_init(&queue);
	q_enqueue(&queue, (item_t) {r-1, c-1, color});
	
	int o_color = p[r-1][c-1];
	
	while(!q_is_empty(&queue))
	{
		item_t curr;
		q_dequeue(&queue, &curr);
		p[curr.r][curr.c] = color;
		
		int i = 0;
		for(i; i < 4; i++)
		{
			int next_r = curr.r + dr[i], next_c = curr.c + dc[i];
			int next_color = p[next_r][next_c];
			
			if(next_r < 0 || next_r >= n || next_c <0 || next_c >= n) continue;
			if(visited[next_r][next_c]) continue;
			
			if(p[next_r][next_c] == o_color)
			{
				visited[next_r][next_c] = 1;
				q_enqueue(&queue, (item_t) {next_r, next_c, next_color});
			}
		}
	}
}

int cmp(const void * a, const void * b)
{
	return (*(int*)b - *(int*)a);
}

int main()
{
    char cmd_type[11];

    while (1)
    {
        scanf("%s", cmd_type);

        if (!strcmp(cmd_type, "new"))
        {
        	scanf("%d", &n);
        	
        	int i = 0;
			int j = 0;
			for(i; i <= n; i++)
			{
    			for(j; j <= n; j++)
    			{
        			p[i][j] = 0;
				}
				j = 0;
			}
        }
        else if (!strcmp(cmd_type, "rect"))
        {
        	int r1, c1, r2, c2;
        	int color;
        	scanf("%d %d %d %d %d", &r1, &c1, &r2, &c2, &color);
        	
        	int i = r1 - 1;
        	int j = c1 - 1;
        	
        	for(i; i < r2; i++)
        	{
        		for(j; j < c2; j++)
        		{
        			p[i][j] = color;
				}
				j = c1 - 1;
			}
        }
        else if (!strcmp(cmd_type, "fill")) // bfs queue 이용하기 
        {
        	int r1, c1;
        	int color;
        	scanf("%d %d %d", &r1, &c1, &color);
        	
        	explore(r1, c1, color);
        }
        else if (!strcmp(cmd_type, "count")) // sorting 이용하기 
        {
        	int c[255];
        	int i, j = 0;
        	for(i; i < n; i++)
        	{
        		for(j; j < n; j++)
        		{
        			color[p[i][j]]++;
        			c[p[i][j]]++;
				}
				j = 0;
			}
			
			qsort(color, 255, sizeof(int), cmp);
			
			i = 0;
			while(color[i] != 0)
			{
				for(j = 0; j < 255; j++)
				{
					if(color[i] == c[j])
					{
						printf("%d:%d\n", j, color[i]);
						c[j] = 0;
					}
				}
				i++;
			}
        }
        else if (!strcmp(cmd_type, "exit"))
        {
            break;
        }
    }
    return 0;
}
