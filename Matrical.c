#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int* readSideLength();
bool useDefaultMatrix();
void createDefaultMatrix(int* default_mtx, int m, int n);
int* read_matrix(int m, int n);
void print_matrix(int* mtx, int m, int n);
int* add_matrix(int* mtx1, int* mtx2, int m, int n);
int* subtract_matrix(int* mtx1, int* mtx2, int m, int n);
int* scalar_multiply_matrix(int c, int* mtx, int m, int n);
int* readFirstSideLength();
int* readFirstSideLength();
int vector_multiply(int* mtx1, int i, int* mtx2, int m2, int j, int n);
int* matrix_multiply_matrix(int* mtx1, int* mtx2, int m1, int n, int m2);
int* transpose_matrix(int* mtx, int m, int n);

int i = 0;
int main()
{
	printf("Whoo-hoo! Welcome to my matrix calculater¡ª¡ªMatrical!\n");
	int id;

	while (true)
	{
		id = NULL;
		printf("Among the following matrix operations, choose the one that u want to play with!!!\n");
		printf("(1) addition; (2) subtraction; (3) scalar multiplication; (4) matrix multiplication; (5) transpose; (0) quit Matrical.\n");
		printf("Now show me your choice bro (1/2/3/4/5/0): ");
		scanf_s("%d", &id);
		if (id == 0)
			return 0;
		if (id == 1)
		{
			int* default_mtx1 = (int*)calloc(10000, sizeof(int)), * default_mtx2 = (int*)calloc(10000, sizeof(int));

			int* mn = readSideLength();
			int m = mn[0];
			int n = mn[1];
			if (useDefaultMatrix())
			{
				createDefaultMatrix(default_mtx1, m, n);
				createDefaultMatrix(default_mtx2, m, n);
				printf("Default matrix 1 is shown below:\n");
				print_matrix(default_mtx1, m, n);
				printf("Default matrix 2 is shown below:\n");
				print_matrix(default_mtx2, m, n);
				printf("Result of addition:\n");
				print_matrix(add_matrix(default_mtx1, default_mtx2, m, n), m, n);
			}
			else {
				printf("Please enter your first matrix dear~\n");
				int* mtx1 = read_matrix(m, n);
				printf("And the second:\n");
				int* mtx2 = read_matrix(m, n);
				printf("Result of addition:\n");
				print_matrix(add_matrix(mtx1, mtx2, m, n), m, n);
			}
		}
		else if (id == 2)
		{
			int* default_mtx1 = (int*)calloc(10000, sizeof(int)), * default_mtx2 = (int*)calloc(10000, sizeof(int));

			int* mn = readSideLength();
			int m = mn[0];
			int n = mn[1];
			if (useDefaultMatrix())
			{
				createDefaultMatrix(default_mtx1, m, n);
				createDefaultMatrix(default_mtx2, m, n);
				printf("Default matrix 1 is shown below:\n");
				print_matrix(default_mtx1, m, n);
				printf("Default matrix 2 is shown below:\n");
				print_matrix(default_mtx2, m, n);
				printf("Result of subtraction:\n");
				print_matrix(subtract_matrix(default_mtx1, default_mtx2, m, n), m, n);
			}
			else {
				printf("Please enter your first matrix dear~\n");
				int* mtx1 = read_matrix(m, n);
				printf("And the second:\n");
				int* mtx2 = read_matrix(m, n);
				printf("Result of subtraction:\n");
				print_matrix(subtract_matrix(mtx1, mtx2, m, n), m, n);
			}
		}
		else if (id == 3)
		{
			int c;
			printf("Sir or Madam, please enter your scalar: ");
			scanf_s("%d", &c);

			int* default_mtx1 = (int*)calloc(10000, sizeof(int));

			int* mn = readSideLength();
			int m = mn[0];
			int n = mn[1];
			if (useDefaultMatrix())
			{
				createDefaultMatrix(default_mtx1, m, n);
				printf("Shown below is our default matrix for you my dear~\n");
				print_matrix(default_mtx1, m, n);
				printf("Result of scalar multiplication:\n");
				print_matrix(scalar_multiply_matrix(c, default_mtx1, m, n), m, n);
			}
			else {
				printf("Please enter your matrix my dear~\n");
				int* mtx = read_matrix(m, n);
				printf("Result of scalar multiplication:\n");
				print_matrix(scalar_multiply_matrix(c, mtx, m, n), m, n);
			}
		}
		else if (id == 4)
		{
			int* default_mtx1 = (int*)calloc(10000, sizeof(int)), * default_mtx2 = (int*)calloc(10000, sizeof(int));

			int* mn = readFirstSideLength();
			int m1 = mn[0];
			int n = mn[1];
			mn = readSideLength();
			int m2 = mn[1];
			if (useDefaultMatrix())
			{
				createDefaultMatrix(default_mtx1, m1, n);
				createDefaultMatrix(default_mtx2, n, m2);
				printf("Default matrix 1 is shown below:\n");
				print_matrix(default_mtx1, m1, n);
				printf("Default matrix 2 is shown below:\n");
				print_matrix(default_mtx2, n, m2);
				printf("Result of matrix multiplication:\n");
				print_matrix(matrix_multiply_matrix(default_mtx1, default_mtx2, m1, n, m2), m1, m2);
			}
			else {
				printf("Please enter your first matrix dear~\n");
				int* mtx1 = read_matrix(m1, n);
				printf("And the second:\n");
				int* mtx2 = read_matrix(n, m2);
				printf("Result of matrix multiplication:\n");
				print_matrix(matrix_multiply_matrix(mtx1, mtx2, m1, n, m2), m1, m2);
			}
		}
		else if (id == 5)
		{

			int* default_mtx1 = (int*)calloc(10000, sizeof(int));

			int* mn = readSideLength();
			int m = mn[0];
			int n = mn[1];
			if (useDefaultMatrix())
			{
				createDefaultMatrix(default_mtx1, m, n);
				printf("Shown below is our default matrix for you my dear~\n");
				print_matrix(default_mtx1, m, n);
				printf("Result of transpose:\n");
				print_matrix(transpose_matrix(default_mtx1, m, n), n, m);
			}
			else {
				printf("Please enter your matrix my dear~\n");
				int* mtx = read_matrix(m, n);
				printf("Result of transpose:\n");
				print_matrix(transpose_matrix(mtx, m, n), n, m);
			}
		}
		else {
			printf("Oops, wrong input, let's restart and choose again my bro!\n");
		}
		
		printf("\n");
	}
	return 0;
}

int* readSideLength()
{
	int mn[2] = { 0 };
	printf("Now my dear, enter the side length m and n of your matrix (note m and n are less than 100): ");
	scanf_s("%d %d", &mn[0], &mn[1] );
	return mn;
}

bool useDefaultMatrix()
{
	getchar();
	char ifd = NULL;
	printf("Would u use my default matrix or not? (y/n): ");
	scanf_s("%c", &ifd, 1);
	if (tolower(ifd) == 'y')
		return true;	
	else if (tolower(ifd) == 'n')
		return false;
}

void createDefaultMatrix(int* default_mtx, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(default_mtx + i * n + j) = rand() % 20;
		}
	}
}

int* read_matrix(int m, int n)
{
	int* mtx = (int*)calloc(m*n, sizeof(int));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", mtx + i * n + j);
		}
	}
	return mtx;
}

void print_matrix(int* mtx, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", *(mtx + i * n + j));
		}
		printf("\n");
	}
}

int* add_matrix(int* mtx1, int* mtx2, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(mtx1 + i * n + j) += *(mtx2 + i * n + j);
		}
	}
	return mtx1;
}

int* subtract_matrix(int* mtx1, int* mtx2, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(mtx1 + i * n + j) -= *(mtx2 + i * n + j);
		}
	}
	return mtx1;
}

int* scalar_multiply_matrix(int c, int* mtx, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(mtx + i * n + j) *= c;
		}
	}
	return mtx;
}

int* readFirstSideLength()
{
	int mn[2] = { 0 };
	printf("Now my dear, enter the side length of your first matrix (which is m1 * n, note m and n are less than 100): ");
	scanf_s("%d %d", &mn[0], &mn[1]);
	return mn;
}

int* readSecondSideLength()
{
	int mn[2] = { 0 };
	printf("It's our time for the side length of your second matrix (which is n * m2): ");
	scanf_s("%d %d", &mn[0], &mn[1]);
	return mn;
}

int vector_multiply(int* mtx1, int i, int* mtx2, int m2, int j, int n)
{
	int m = 0;
	for (int k = 0; k < n; k++)
	{
		m += (*(mtx1 + i * n + k)) * (*(mtx2 + k * m2 + j));
	}
	return m;
}

int* matrix_multiply_matrix(int* mtx1, int* mtx2, int m1, int n, int m2)
{
	int* mtx = (int*)calloc(m1 * m2, sizeof(int));
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			*(mtx + i * m2 + j) = vector_multiply(mtx1, i, mtx2, m2, j, n);
		}
	}
	return mtx;
}

int* transpose_matrix(int* mtx, int m, int n)
{
	int* trans_mtx = (int*)calloc(n * m, sizeof(int));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(trans_mtx + j * m + i) = *(mtx + i * n + j);
		}
	}
	return trans_mtx;
}
