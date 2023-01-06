#include "graph.h"
#include "stddef.h"
#include <stdio.h>
#include <stdlib.h>

queue* createQueue() {
	queue* q = malloc(sizeof(struct queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

int isEmpty(queue* q) {
	if (q->rear == -1) return 1;
	else return 0;
}

void enqueue(queue* q, int value) {
	if (q->rear != SIZE - 1)
	{
		if (q->front == -1) q->front = 0;
		q->rear += 1;
		q->items[q->rear] = value;
	}
}
int dequeue(queue* q) {
	int item;
	if (isEmpty(q)) return -1;
	else {
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear) q->front = q->rear = -1; // reset queue
	}
	return item;
}

node* createNode(int v) {
	node* nn = malloc(sizeof(node));
	nn->vertex = v;
	nn->next = NULL;
	for (int i = 0; i < 31; i++) // get random value -> departure time for 31 days
	{
		nn->time[i] = rand() % 23;
	}
	nn->x = rand() % 3000; // get random value -> x coordinate
	nn->y = rand() % 3000; // get random value-> y coordinate
	return nn;
}

graph* createGraph(int vertices) {
	graph* g = malloc(sizeof(graph));
	g->num = vertices;
	g->adjLists = malloc(vertices * sizeof(node*));
	g->visited = malloc(vertices * sizeof(int));

	int i;
	for (i = 0; i < vertices; i++)
	{
		g->adjLists[i] = NULL;
		g->visited[i] = 0;
	}
	return g;
}

void addEdge(graph* g, int src, int dest) {
	// edge src->dest
	node* nn = createNode(dest);
	nn->next = g->adjLists[src];
	g->adjLists[src] = nn;

	// edge dest->src
	nn = createNode(src);
	nn->next = g->adjLists[dest];
	g->adjLists[dest] = nn;
}

void bfs(graph* g, int start, int dest, int date) {
	queue* q = createQueue();
	int count = 0;

	for (int i = 0; i < 260; i++)
	{
		g->visited[i] = 0; // intialize visited array for checking
	}

	g->visited[start] = 1;
	enqueue(q, start);

	extern int road[40]; // get road array - save the route
	extern int time[40]; // get time array - save the time
	int counter = 0;

	for (int i = 0; i < 40; i++) // initialize road
	{
		road[i] = -1;
		time[i] = -1;
	}

	while (!isEmpty(q))
	{
		count++;
		int cur = dequeue(q);
		road[counter++] = cur;

		node* tmp = g->adjLists[cur]; // bfs part
		int i = 0;
		while (tmp)
		{
			int adj = tmp->vertex;
			if (g->visited[adj] == 0) // if not visited
			{
				g->visited[adj] = 1;
				enqueue(q, adj); // put into queue
			}
			if(i == 0) time[i] = tmp->time[date]; // get the first city's departure time
			else
			{
				time[i] = time[i - 1] + 1; // simplified version - flight time between two cities is one hour
				if (time[i] >= 24) time[i] = 0; // get next day's time
			}
			i++;
			tmp = tmp->next;
		}

		if (cur == dest) // when get the destination
		{
			int beforeTime = 0; // get before time
			for (int i = 0; i < 40; i++)
			{
				if (time[i] < beforeTime) date++; // if the departure time of next day is smaller -> next day
				if (date > 31) date = 1; // if the day is bigger than 31 -> next month
				if (road[i] == dest) // print the destination city
				{
					printf("%c", road[i] + 97);
					printf("(%d:00, %d)", time[i], date);
					break;
				}
				printf("%c", road[i] + 97); // print intermediate city
				printf("(%d:00, %d)-> ", time[i], date);
				beforeTime = time[i]; // get before time
			}
			printf("\n");
			break;
		}
	}
}