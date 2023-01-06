#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"
#include "graph.h"

#define _CRT_SECURE_NO_WARNINGS

int road[40] = { -1 }; // global variable -> get road information and give the information to each rb-tree node to save reservation
int time[40] = { -1 }; // global variable -> get time information and give the information to each rb-tree node to save reservation

int main()
{
	graph* g = createGraph(26); // intialize graph
	int i, j, a, b;
	int A[10] = { 0 }; // ten cities that connected for each city

	int count = 10; // initialize count for ten (10 cities) 
	int length = 0; // calculate the length of the adjacency list 

	for (i = 0; i < 26; i++) // for 26 cities
	{
		for (a = 0; a < 10; a++) // for 10 connected cities
		{
			length = 0;
			A[a] = rand() % 26; // get random value(city)
			if (A[a] == i) a--; // if destination is the same source, get the random value again
			for (b = 0; b < a; b++) // no duplicated values in array
			{
				if (A[a] == A[b]) a--;
			}
			struct node* temp = g->adjLists[i]; // no duplicated edges in graph
			while (temp)
			{
				if (temp->vertex == A[a]) a--; // if there is duplicated edges
				temp = temp->next;
				length++; // count the length of the adjacency list
			}
		}
		if (length > 0) { // if there is some roads already 
			if (length < 10)
			{
				count = 10 - length; // decrease the count
			}
			else {
				count = 0;
			}
		}
		for (j = 0; j < count; j++) // for count 
		{
			addEdge(g, i, A[j]); // add edges
		}
	}

	int choice = 0; // variable that get choice from user
	rbtree* t = newRbtree(); // initialize rb-tree
	int id = 0; // reservation id
	while (choice != 3)
	{
		printf("============= Airport Reservation System =============\n");
		printf("1. Make Reservation\n");
		printf("2. Delete Reservation\n");
		printf("3. Quit\n");
		printf("Choose menu: ");
		scanf("%d", &choice); // get choice
		printf("\n");

		if (choice == 1) // make reservation
		{
			for (int i = 0; i < 40; i++) // initialize road and time 
			{
				road[i] = -1;
				time[i] = -1;
			}
			char* name = malloc(sizeof(char) * 10); // initialize each reservation information variables
			char src, dest;
			int date;
			char* input = malloc(sizeof(char) * 30);
			printf("Enter the reservation information\n"); // get reservation information
			scanf("%s %c %c %d", name, &src, &dest, &date);
			printf("\n");
			if (!name || !src || !dest || !date)
			{
				printf("Wrong input: choose menu again\n\n");
			}
			else
			{
				info* nn = newInfo(id++, name, src, dest, date); // make new node for rb-tree
				printf("Reservation ID: %d\n", id); // print out the reservation id and the route
				printf("Reservation name: %s\n", name);
				printf("The root is: ");
				bfs(g, src - 97, dest - 97, date);
				for (int i = 0; i < 40; i++) // save the route and time in reservation node
				{
					nn->road[i] = road[i];
					nn->time[i] = time[i];
					if (road[i] == dest - 97) break;
				}
				printf("\n");
				//print rb-tree
				printf("Before Insertion: \n");
				PRINT_BST(t, t->root, 0);
				printf("\n");
				RB_INSERT(t, nn);
				printf("Current Tree is: \n");
				PRINT_BST(t, t->root, 0);
				printf("\n");
			}
		}
		else if (choice == 2) // delete reservation
		{
			int deleteId = 0;
			printf("Enter the reservation ID: "); // get reservation id that user want to delete
			scanf("%d", &deleteId);

			if (deleteId > id)
			{
				printf("Wrong input: Choose menu again. \n\n");
			}
			else
			{
				printf("Before deletion: \n"); // print the rb-tree and delete the reservation
				PRINT_BST(t, t->root, 0);
				printf("\n");
				RB_DELETE(t, deleteId);
				printf("After deletion: \n");
				PRINT_BST(t, t->root, 0);
				printf("\n");
			}
		}
		else if (choice == 3) // finish the program 
		{
			break;
		}
		else // error handling: wrong input
		{
			printf("Wrong Input: Choose menu again. \n\n");
		}
	}



}
