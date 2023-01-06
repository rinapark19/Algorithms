#include <stdio.h>
#include <stdlib.h>

const int capacity = 37; // m = 37

int** arr1; // three hash tables
int** arr2;
int** arr3;

int insert(int key, int choice) 
{
	int probe = 1; // initial probe
	int hashIndex = key % capacity; // initial index

	if (choice == 1) // choice = 1 -> linear probing
	{
		while (arr1[hashIndex] != -1) // collision
		{
			hashIndex++;
			hashIndex %= capacity; // calculate key index
			probe++;
		}

		arr1[hashIndex] = key; // insert the value to the table
	}
	else if (choice == 2) // choice = 2 -> quadratic probing
	{
		while (arr2[hashIndex] != -1) // collision
		{
			hashIndex = hashIndex + probe + (probe * probe) * 3; // calculate hash index
			hashIndex %= capacity;
			probe++;
		}
		arr2[hashIndex] = key; // insert the key to the table
	}
	else // double hashing
	{
		while (arr3[hashIndex] != -1) 
		{
			hashIndex = hashIndex + probe * (probe + (key % (capacity - probe))); // calculate hash index
			hashIndex %= capacity;
			probe++;
		}
		arr3[hashIndex] = key; // insert the key to the table
	}
	return probe; // return the number of probes
}

int print_table(int size, int choice) 
{
	int i;
	int largest = 0; // calculate the largest cluster length
	int count = 0;

	if (choice == 1)
	{
		for (i = 0; i < size; i++)
		{
			if (arr1[i] == -1)
			{
				printf("%d: \n", i);
				count = 0; // if cluster end, count = 0
			}
			else
			{
				printf("%d: ", i);
				printf("%d \n", arr1[i]); 
				count++; // if cluster not end, count + 1
			}
			if (count > largest) largest = count; // get maximum length
		}
	}
	else if (choice == 2)
	{
		for (i = 0; i < size; i++)
		{
			if (arr2[i] == -1)
			{
				printf("%d: \n", i);
				count = 0;
			}
			else
			{
				printf("%d: ", i);
				printf("%d \n", arr2[i]);
				count++;
			}
			if (count > largest) largest = count;
		}
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			if (arr3[i] == -1)
			{
				printf("%d: \n", i);
				count = 0;
			}
			else
			{
				printf("%d: ", i);
				printf("%d \n", arr3[i]);
				count++;
			}
			if (count > largest) largest = count;
		}
	}
	return largest; // return maximum length
}

int main()
{
	arr1 = (int**)malloc(sizeof(int*) * capacity);
	arr2 = (int**)malloc(sizeof(int*) * capacity);
	arr3 = (int**)malloc(sizeof(int*) * capacity);

	int i, j;
	int average1 = 0, average2 = 0, average3 = 0;

	for (i = 0; i < capacity; i++) // initialize the table
	{
		arr1[i] = -1;
		arr2[i] = -1;
		arr3[i] = -1;
	}

	int A[30] = { 0 };
	for (i = 0; i < 30; i++) // fill a with random values
	{
		A[i] = rand() % 1000;

		for (j = 0; j < i; j++)
		{
			if (A[i] == A[j]) i--;
		}
	}

	int largest1 = 0, largest2 = 0, largest3 = 0;

	for (i = 0; i < 30; i++) // insert three hash tables, and calculate average probe
	{
		average1 += insert(A[i], 1);
		average2 += insert(A[i], 2);
		average3 += insert(A[i], 3);
	}

	average1 /= 30;
	average2 /= 30;
	average3 /= 30;

	largest1 = print_table(capacity, 1); // print three hash tables. average number of probes, primary cluster length
	printf("\n Average number of probes: %d", average1);
	printf("\n Primary cluster length: %d\n\n", largest1);
	largest2 = print_table(capacity, 2);
	printf("\n Average number of probes: %d", average2);
	printf("\n Primary cluster length: %d\n\n", largest2);
	largest3 = print_table(capacity, 3);
	printf("\n Average number of probes: %d", average3);
	printf("\n Primary cluster length: %d\n\n", largest3);
}
