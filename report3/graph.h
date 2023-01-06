// header file for graph and queue(for bfs)
#define SIZE 40

typedef struct queue {
	int items[SIZE];
	int front;
	int rear;
} queue;

typedef struct node {
	int vertex; // int value -> + 97 to get alphabet value
	struct node* next;
	int time[31]; // each node have 31 integers - 31 departure times for 31 days
	int x;
	int y;
} node;

typedef struct graph {
	int num;
	struct node** adjLists;
	int* visited;
} graph;

queue* createQueue();
int isEmpty(queue* q);
void enqueue(queue* q, int value);
int dequeue(queue* q);
node* createNode(int v);
graph* createGraph(int vertices);
void addEdge(graph* g, int src, int dest);
void bfs(graph* g, int start, int dest, int date);
