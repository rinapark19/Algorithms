#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y, tmp) ((tmp) =(x), (x)=(y), (y)=(tmp)) // define swap function: interchange two values

int selection_sort(int list[], int n) 
{
	int i, j, max, tmp, cnt = 0; // i: first counter, j: second counter, max: maximum value index, tmp: argument for swap function, cnt: comparison counter

	for (i = 0; i < n - 1; i++)
	{
		max = i; // max value update

		for (j = i + 1; j < n; j++)
		{
			if (list[j] > list[max]) // if there is bigger value
			{
				max = j; // max value update
			}
		}

		if (i != max) // if current value is not maximum value
		{
			SWAP(list[i], list[max], tmp); // interchange two values
			cnt++; // increase comparison counter
		}
	}

	return cnt;
}

void generator1(int list[], int n) // function for generating reversely sorted array
{
	int i;

	for (i = 0; i < n; i++)
	{
		list[i] = i + 1;
	}
}

void generator2(int list[], int n) // function for generating already sorted array
{
	int i;

	for (i = 0; i < n; i++)
	{
		list[i] = 100 - i;
	}
}

int main()
{
	srand(time(NULL)); // initialize random seed
	int A[100] = { 0 };
	int i, j, cnt = 0;

	for (i = 0; i < 100; i++) // fill a with random values
	{
		A[i] = rand() % 1000;
		
		for (j = 0; j < i; j++)
		{
			if (A[i] == A[j]) i--;
		}
	}

	printf("The first case: ");
	printf("\nBefore sort \n");

	for (i = 0; i < 100; i++)
	{
		printf("%d ", A[i]);
	}

	cnt = selection_sort(A, 100);

	printf("\n\nAfter sort \n");
	for (i = 0; i < 100; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n\nThe number of comparison: %d\n\n", cnt);

	printf("The second case: ");
	printf("\nBefore sort \n");

	generator2(A, 100);

	for (i = 0; i < 100; i++)
	{
		printf("%d ", A[i]);
	}

	cnt = selection_sort(A, 100);

	printf("\n\nAfter sort \n");
	for (i = 0; i < 100; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n\nThe number of comparison: %d\n\n", cnt);

	printf("The third case: ");
	printf("\nBefore sort: \n");

	generator1(A, 100);

	for (i = 0; i < 100; i++)
	{
		printf("%d ", A[i]);
	}

	cnt = selection_sort(A, 100);

	printf("\n\nAfter sort \n");
	for (i = 0; i < 100; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n\nThe number of comparison: %d\n", cnt);

}