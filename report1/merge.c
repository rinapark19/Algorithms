#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sort[100];
int count = 0; // count: comparison counter

void merge(int list[], int l, int m, int r) // merge sort function
{
	int i, j, k, cnt; // i: left index, j: middle index + 1, k: index for sorted array
	i = l;
	j = m + 1;
	k = l;

	while (i <= m && j <= r) // if i is in left, j is between middle and right
	{
		if (list[i] > list[j]) //  if i value is bigger than j value
		{
			sort[k++] = list[i++]; //  add i value to sorted array
		}
		else
		{
			sort[k++] = list[j++]; // add j value to sorted array
		}
		count++; // increase comparison counter
	}
	
	if (i > m) // if i is in right
	{
		for (cnt = j; cnt <= r; cnt++) // add j value to sorted array
		{
			sort[k++] = list[cnt];
		}
	}

	else
	{
		for (cnt = i; cnt <= m; cnt++) //  add i value to sorted array
		{
			sort[k++] = list[cnt];
		}
	}

	for (cnt = l; cnt <= r; cnt++) // add other values to original array
	{
		list[cnt] = sort[cnt];
	}

}

void merge_sort(int list[], int l, int r) // merge sort function
{
	int m;

	if (l < r)
	{
		m = (l + r) / 2;
		merge_sort(list, l, m); // left side
		merge_sort(list, m + 1, r); // right side
		merge(list, l, m, r); // merge two partial arrays
	}
}

void generator1(int list[], int n) // function for generating reversely sorted array
{
	int i;
	for (i = 0; i < n; i++)
	{
		list[i] = i + 1;
	}
}

void generator2(int list[], int n) // function for generating sorted array
{
	int i;
	for (i = 0; i < n; i++)
	{
		list[i] = n - i;
	}
}

int main()
{
	srand(time(NULL));
	int i, j, cnt = 0;
	int A[100];

	for (i = 0; i < 100; i++)
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

	merge_sort(A, 0, 99);

	printf("\n\nAfter sort \n");
	for (i = 0; i < 100; i++)
	{
		printf("%d ", sort[i]);
	}

	printf("\n\nThe number of comparison: %d\n\n", count);
	count = 0;

	printf("The second case: ");
	printf("\nBefore sort \n");

	generator2(A, 100);

	for (i = 0; i < 100; i++)
	{
		printf("%d ", A[i]);
	}

	merge_sort(A, 0, 99);

	printf("\n\nAfter sort \n");
	for (i = 0; i < 100; i++)
	{
		printf("%d ", sort[i]);
	}

	printf("\n\nThe number of comparison: %d\n\n", count);
	count = 0;
	
	printf("The Third case: ");
	printf("\nBefore sort \n");

	generator1(A, 100);

	for (i = 0; i < 100; i++)
	{
		printf("%d ", A[i]);
	}

	merge_sort(A, 0, 99);

	printf("\n\nAfter sort \n");
	for (i = 0; i < 100; i++)
	{
		printf("%d ", sort[i]);
	}

	printf("\n\nThe number of comparison: %d\n\n", count);
	count = 0;


}