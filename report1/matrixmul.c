#include <stdio.h>
#include <stdlib.h>
int A1[4][4];
int B1[4][4];
int C1[4][4]; // answer matrix for standard algorithm
int C1_1[4][4]; // answer matrix for divide and conquer algorithm
int C1_2[4][4]; // answer matrix for strassen algorithm
int A2[8][8];
int B2[8][8];
int C2[8][8];
int C2_1[8][8];
int C2_2[8][8];

int cnt2 = 0; // computation counter for divide and conquer algorithm
int cnt3 = 0; // computation counter for strassen algorithm

int standard(int num) // standard algorithm
{
	int i, j;
	int cnt = 0;
	
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (num == 4) // multiplication for 4X4
			{
				int sum = 0;
				int k;
				for (k = 0; k < num; k++)
				{
					sum += A1[i][k] * B1[k][j];
					cnt++;
				}
				C1[i][j] = sum;
			}
			else // multiplication for 8X8
			{
				int sum = 0;
				int k;
				for (k = 0; k < num; k++)
				{
					sum += A2[i][k] * B2[k][j];
					cnt++;
				}
				C2[i][j] = sum;
			}
		}
	}
	return cnt;
}

void dac(int row_a, int col_a, int row_b, int col_b, int num, int c) // divde and conquer algorithm
{
	
	if (num == 1) // if the number of column is 1
	{
		cnt2++;
		
		if (c == 0) // for 4X4 case
		{
			C1_1[row_a][col_b] += A1[row_a][col_a] * B1[row_b][col_b]; // add values to matrix C

			if (row_a > 0 && col_a > 0 && row_b > 0 && col_b)
			{
				printf("partial matrix of divide and conquer: \n"); // print partial matrix
				int i, j;
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						printf("%d ", C1_1[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
		}
		else if (c == 1) // for 8X8 case
		{
			C2_1[row_a][col_b] += A2[row_a][col_a] * B2[row_b][col_b];

			if (row_a > 0 && col_a > 0 && row_b > 0 && col_b)
			{
				printf("partial matrix of divide and conquer: \n");
				int i, j;
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 8; j++)
					{
						printf("%d ", C2_1[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
		}
	}
	else
	{
		if (c == 0) // divide process for 4X4 case
		{
			dac(row_a + 0, col_a + 0, row_b + 0, col_b + 0, num / 2, 0);
			dac(row_a + 0, col_a + num / 2, row_b + num / 2, col_b + 0, num / 2, 0);
			dac(row_a + 0, col_a + 0, row_b + 0, col_b + num / 2, num / 2, 0);
			dac(row_a + 0, col_a + num / 2, row_b + num / 2, col_b + num / 2, num / 2, 0);
			dac(row_a + num / 2, col_a + 0, row_b + 0, col_b + 0, num / 2, 0);
			dac(row_a + num / 2, col_a + num / 2, row_b + num / 2, col_b + 0, num / 2, 0);
			dac(row_a + num / 2, col_a + 0, row_b + 0, col_b + num / 2, num / 2, 0);
			dac(row_a + num / 2, col_a + num / 2, row_b + num / 2, col_b + num / 2, num / 2, 0);
		}
		else if (c == 1) // divide process for 8x8 case
		{
			dac(row_a + 0, col_a + 0, row_b + 0, col_b + 0, num / 2, 1);
			dac(row_a + 0, col_a + num / 2, row_b + num / 2, col_b + 0, num / 2, 1);
			dac(row_a + 0, col_a + 0, row_b + 0, col_b + num / 2, num / 2, 1);
			dac(row_a + 0, col_a + num / 2, row_b + num / 2, col_b + num / 2, num / 2, 1);
			dac(row_a + num / 2, col_a + 0, row_b + 0, col_b + 0, num / 2, 1);
			dac(row_a + num / 2, col_a + num / 2, row_b + num / 2, col_b + 0, num / 2, 1);
			dac(row_a + num / 2, col_a + 0, row_b + 0, col_b + num / 2, num / 2, 1);
			dac(row_a + num / 2, col_a + num / 2, row_b + num / 2, col_b + num / 2, num / 2, 1);
		}
	}
}

void strassen(int row_a, int col_a, int row_b, int col_b, int n, int c) // strassen algorithm
{
	if (n == 2) // 2x2 partial matrix
	{
		if (c == 0) //  for 4x4 case
		{
			int m1, m2, m3, m4, m5, m6, m7; // compute all values for strassen algorithm
			m1 = (A1[row_a][col_a] + A1[row_a + 1][col_a + 1]) * (B1[row_b][col_b] + B1[row_b + 1][col_b + 1]);
			m2 = (A1[row_a + 1][col_a] + A1[row_a + 1][col_a + 1]) * B1[row_b][col_b];
			m3 = A1[row_a][col_a] * (B1[row_b][col_b + 1] - B1[row_b + 1][col_b + 1]);
			m4 = A1[row_a + 1][col_a + 1] * (B1[row_b + 1][col_b] - B1[row_b][col_b]);
			m5 = (A1[row_a][col_a] + A1[row_a][col_a + 1]) * B1[row_b + 1][col_b + 1];
			m6 = (A1[row_a + 1][col_a] - A1[row_a][col_a]) * (B1[row_b][col_b] + B1[row_b][col_b + 1]);
			m7 = (A1[row_a][col_a + 1] - A1[row_a + 1][col_a + 1]) * (B1[row_b = 1][col_b] + B1[row_b + 1][col_b + 1]);

			C1_2[row_a][col_a] = m1 + m4 - m5 + m7; // add values to C matrix
			C1_2[row_a][col_a + 1] = m3 + m5;
			C1_2[row_a + 1][col_a] = m2 + m4;
			C1_2[row_a + 1][col_a + 1] = m1 - m2 + m3 + m6;

			cnt3 = cnt3 + 25;

			int i, j;
			printf("Partial Matrix of strassen algorithm: \n"); // print partial matrix
			for (i = row_a; i <= row_a + 1; i++)
			{
				for (j = col_a; j <= col_a + 1; j++)
				{
					printf("%d ", C1_2[i][j]);
				}
				printf("\n");
			}
		}
		else if (c == 1) // for 8x8 case
		{
			int m1, m2, m3, m4, m5, m6, m7;
			m1 = (A2[row_a][col_a] + A2[row_a + 1][col_a + 1]) * (B2[row_b][col_b] + B2[row_b + 1][col_b + 1]);
			m2 = (A2[row_a + 1][col_a] + A2[row_a + 1][col_a + 1]) * B2[row_b][col_b];
			m3 = A2[row_a][col_a] * (B2[row_b][col_b + 1] - B2[row_b + 1][col_b + 1]);
			m4 = A2[row_a + 1][col_a + 1] * (B2[row_b + 1][col_b] - B2[row_b][col_b]);
			m5 = (A2[row_a][col_a] + A2[row_a][col_a + 1]) * B2[row_b + 1][col_b + 1];
			m6 = (A2[row_a + 1][col_a] - A2[row_a][col_a]) * (B2[row_b][col_b] + B2[row_b][col_b + 1]);
			m7 = (A2[row_a][col_a + 1] - A2[row_a + 1][col_a + 1]) * (B2[row_b = 1][col_b] + B2[row_b + 1][col_b + 1]);

			C2_2[row_a][col_a] = m1 + m4 - m5 + m7;
			C2_2[row_a][col_a + 1] = m3 + m5;
			C2_2[row_a + 1][col_a] = m2 + m4;
			C2_2[row_a + 1][col_a + 1] = m1 - m2 + m3 + m6;

			cnt3 = cnt3 + 25;

			int i, j;
			printf("Partial Matrix of strassen algorithm: \n");
			for (i = row_a; i <= row_a + 1; i++)
			{
				for (j = col_a; j <= col_a + 1; j++)
				{
					printf("%d ", C2_2[i][j]);
				}
				printf("\n");
			}
		}
	}
	else
	{
		if(c == 0) // divide process for 4x4 matrix
		{
			strassen(row_a + 0, col_a + 0, row_b + 0, col_b + 0, n / 2, 0);
			strassen(row_a + n / 2, col_a + 0, row_b + n / 2, col_b + 0, n / 2, 0);
			strassen(row_a + 0, col_a + n / 2, row_b + 0, col_b + n / 2, n / 2, 0);
			strassen(row_a + n / 2, col_a + n / 2, row_b + n / 2, col_b + n / 2, n / 2, 0);
		}
		else if (c == 1) // devide process for 8x8 matrix
		{
			strassen(row_a + 0, col_a + 0, row_b + 0, col_b + 0, n / 2, 1);
			strassen(row_a + n / 2, col_a + 0, row_b + n / 2, col_b + 0, n / 2, 1);
			strassen(row_a + 0, col_a + n / 2, row_b + 0, col_b + n / 2, n / 2, 1);
			strassen(row_a + n / 2, col_a + n / 2, row_b + n / 2, col_b + n / 2, n / 2, 1);
		}
	}
	
}

int main()
{
	srand(time(NULL));
	int i, j;
	for (i = 0; i < 4; i++) // generate random values to 4x4 matrix
	{
		for (j = 0; j < 4; j++)
		{
			A1[i][j] = rand() % 1000;
			B1[i][j] = rand() % 1000;
		}
	}

	int cnt1 = standard(4); // strandard algorithm, and computation counter
	dac(0, 0, 0, 0, 4, 0); 
	printf("\n");
	strassen(0, 0, 0, 0, 4, 0);
	printf("\n");

	printf("\nThe first case(4X4):\n");
	printf("The number of computation of standard algorithm: %d\n", cnt1);
	printf("The number of computation of divide and conquer algorithm: %d\n", cnt2);
	printf("The number of computation of strassen algorithm: %d\n", cnt3);
	cnt2 = 0;
	cnt3 = 0;
	printf("\nThe matrix A: \n"); // print all matrices

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", A1[i][j]);
		}
		printf("\n");
	}

	printf("\nThe matrix B: \n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", B1[i][j]);
		}
		printf("\n");
	}

	printf("\nThe matrix C: \n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", C1[i][j]);
		}
		printf("\n");
	}

	printf("\nThe second case(8X8):\n");
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			A2[i][j] = rand() % 1000;
			B2[i][j] = rand() % 1000;
		}
	}

	cnt1 = standard(8);
	dac(0, 0, 0, 0, 8, 1);
	printf("\n");
	strassen(0, 0, 0, 0, 8, 1);
	printf("\n");

	printf("The number of computation of standard algorithm: %d\n", cnt1);
	printf("The number of computation of divide and conquer algorithm: %d\n", cnt2);
	printf("The number of computation of strassen algorithm: %d\n", cnt3);

	printf("\nThe matrix A: \n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d ", A2[i][j]);
		}
		printf("\n");
	}

	printf("\nThe matrix B: \n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d ", B2[i][j]);
		}
		printf("\n");
	}

	printf("\nThe matrix C: \n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d ", C2[i][j]);
		}
		printf("\n");
	}
	

}