#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int x[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int y[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
int biztonsagos(int, int, int**, int);
int huszarbejaras();
int bejar(int, int, int, int**, int*, int*, int);
void kiir(int**, int);
int main()
{

	huszarbejaras();
	//Lo(a,2,2,1,n);
	return 0;
}

int huszarbejaras()
{
	int **a, n;
	cout << "n=";
	cin >> n;
	a = (int**)calloc((n), sizeof(int*));
	for (int i = 0; i < n; ++i)
	{
		a[i] = (int*)calloc((n), sizeof(int));
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = -1;
		}
	}
	a[2][2] = 0;
	if (bejar(2, 2, 1, a, x, y, n) == 0)
	{
		cout << "Nincs megoldas";
		return 0;
	}
	else
		kiir(a, n);
	return 1;
}

int bejar(int i, int j, int k, int**a, int*x, int*y, int n)
{
	int kovX, kovY;
	if (k == n * n)
	{
		return 1;
	}
	for (int w = 0; w < 8; ++w)
	{
		kovX = i + x[w];
		kovY = j + y[w];
		if (biztonsagos(kovX, kovY, a, n))
		{
			a[kovX][kovY] = k;
			if (bejar(kovX, kovY, k + 1, a, x, y, n) == 1)
				return 1;
			else
				a[kovX][kovY] = -1;
		}
	}
	return 0;
}



void kiir(int **a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%d  ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int biztonsagos(int i, int j, int**a, int n)
{
	return (i >= 0 && i < n && j >= 0 &&
		j < n && a[i][j] == -1);
}