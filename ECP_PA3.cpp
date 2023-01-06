#include <iostream>

using namespace std;

int arr1[10][10];
int arr2[10][10];
int arr3[10][10];

class matrix
{
	private:
		int r;
		int c;
		int number; 

	public:
		matrix(int row, int column, int num): r(row), c(column), number(num ){}
		void show()
		{
			if(number == 1)
			{
				for(int i = 0; i < r; i++)
				{
					for(int j =0; j < c; j++)
					{
						cout << arr1[i][j] << " ";
					}
					cout << "\n";
				}
			}
			else if(number == 2)
			{
				for(int i = 0; i < r; i++)
				{
					for(int j =0; j < c; j++)
					{
						cout << arr2[i][j] << " ";
					}
					cout << "\n";
				}
			}
			else if(number == 3)
			{
				for(int i = 0; i < r; i++)
				{
					for(int j =0; j < c; j++)
					{
						cout << arr3[i][j] << " ";
					}
					cout << "\n";
				}
			}
		}
		const matrix operator*(int num)
		{
			for(int i =0; i < r; i++)
			{
				for(int j = 0; j < c; j++)
				{
					arr3[i][j] = arr1[i][j] * num;
				}
			}
			matrix m(r, c, 3);
			return m;
		}
		friend const matrix operator+(const matrix &m1, const matrix &m2);
		friend const matrix operator-(const matrix &m1, const matrix &m2);
		friend const matrix operator*(const matrix &m1, const matrix &m2);
};

const matrix operator+(const matrix &m1, const matrix &m2)
{
	for(int i = 0 ; i < m1.r; i++)
	{
		for(int j = 0; j < m1.c; j++)
		{
			arr3[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	matrix m(m1.r, m1.c, 3);
	return m;
}

const matrix operator-(const matrix &m1, const matrix &m2)
{
	for(int i = 0; i < m1.r ; i++)
	{
		for(int j = 0; j < m1.c; j++)
		{
			arr3[i][j] = arr1[i][j] - arr2[i][j]; 
		}
	}
	matrix m(m1.r, m1.c, 3);
	return m;
}

const matrix operator*(const matrix &m1, const matrix &m2)
{
	for(int i = 0; i < m1.r; i++)
	{
		for(int j =0; j < m1.c; j++)
		{
			int sum = 0;
			for(int m =0; m < m1.c; m++)
			{
				sum += arr1[i][m] * arr2[m][j];
			}
			arr3[i][j] = sum;
		}
	}
	matrix m(m1.r, m2.c, 3);
	return m;
}

int main()
{
	char op;
	int r1, c1;
	
	cout << "Matrix Shape : ";
	cin >> r1 >> c1;
	matrix m1(r1, c1, 1);
	
	cout << "Matrix : ";
	for(int i =0; i < r1; i++)
	{
		for(int j =0; j < c1; j++)
		{
			cin >> arr1[i][j];
		}
	}
	
	cout << "Operation : ";
	cin >> op;
	
	int r2, c2;	
	cout << "Matrix Shape : ";
	cin >> r2 >> c2;
	matrix m2(r2, c2, 2);
	
	cout << "Matrix : ";
	for(int i =0; i < r2; i++)
	{
		for(int j =0; j < c2; j++)
		{
			cin >> arr2[i][j];
		}
	}
	
	
	if(op == '+')
	{
		if(r1 != r2 || c1 != c2)
		{
			cout << "Not matched shape : " << "(" << r1 << "," << c1 << ")" << " + " << "(" << r2 << "," << c2 << ")" << endl;
		}
		else
		{
			matrix m3 = m1 + m2;
			cout << "Matrix Operation Results" << endl;
			m3.show();
		}
	}
	else if(op == '-')
	{
		if(r1 != r2 || c1 != c2)
		{
			cout << "Not matched shape : " << "C" << r1 << "," << c1 << ")" << " - " << "(" << r2 << "," << c2 << ")" << endl;	
		}
		else
		{
			matrix m3 = m1 - m2;
			cout << "Matrix Operation Results" << endl;
			m3.show();
		}
	}
}
