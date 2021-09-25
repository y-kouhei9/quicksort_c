# include <stdio.h>
# include <stdint.h>

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x   = *y;
	*y   = temp;
}

int partition(int A[], int l, int h)
{
	int pivot = A[l];
	int i = l, j = h;

	do {
		do {i++;} while (A[i] <= pivot);
		do {j--;} while (A[j] >  pivot);

		if (i < j) {
			swap(&A[i], &A[j]);
		}
	} while (i < j);

	swap(&A[l], &A[j]);
	return j;
}

void QuickSort(int A[], int l, int h)
{
	int j;

	if (l < h) {
		j = partition(A, l, h);
		QuickSort(A, l, j);
		QuickSort(A, j+1, h);
	}
}

int main(void)
{
	int A[] = {10, 33, 27, 6, 3, 38, 20, 48, 32, 1, 0, 47, 61, INT32_MAX};
	int n = sizeof(A)/sizeof(A[0]);
	int i;

	QuickSort(A, 0, n - 1);

	for (i = 0; i < n - 1; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}