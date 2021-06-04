#include<iostream>
#include<vector>
using namespace std;


void swap(long long* a, long long* b)
{
	long long temp = *a;
	*a = *b;
	*b = temp;
}

void partition(vector <long long> &a, int l, int h, int& i, int& j)
{ 
	if (h - l <= 1)
	{
		if (a[h] < a[l])
			swap(&a[h], &a[l]);
		i = l;
		j = h;
		return;
	}

	int mid = l;
	long long pivot = a[h];
	while (mid <= h)
	{
		if (a[mid] < pivot)
			swap(&a[l++], &a[mid++]);
		else if (a[mid] == pivot)
			mid++;
		else if (a[mid] > pivot)
			swap(&a[mid], &a[h--]);
	}

	i = l - 1;
	j = mid;
}
void print(vector <long long> a, int n)
{
	for (int i = 0; i < n; ++i)
		cout << a[i]<< " ";
}
void quicksort(vector <long long >& a, int l, int h)
{
	if (l >= h)  
		return;

	int i, j;
	partition(a, l, h, i, j);
	quicksort(a, l, i);
	quicksort(a, j, h);
}
int main()
{
	int N;
	cin >> N;
	vector <long long>A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	quicksort(A, 0 , N-1);
	print(A, N);
	return 0;
}
