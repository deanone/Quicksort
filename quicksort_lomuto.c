#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int partition(int *A, int lo, int hi)
{
	int pivot = A[hi];
	int i = lo;
	for (int j = lo; j < hi; ++j)
	{
		if (A[j] < pivot)
		{
			swap(A, i, j);
			i++;
		}
	}
	swap(A, i, hi);
	return i;
}

void quicksort(int *A, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(A, lo, hi);
		quicksort(A, lo, p - 1);
		quicksort(A, p + 1, hi);
	}
}

int irand(int low, int high)
{
   return low + rand() / (RAND_MAX / (high - low + 1) + 1);
}

int main(int argc, char *argv[]) 
{
	if (argc == 4)
	{
		// for random integers generation
		srand(time(NULL));
	
		int N = atoi(argv[1]);
		int low = atoi(argv[2]);
		int high = atoi(argv[3]);
		
		// Allocate memory for the array
		int *A;
		A = malloc(N * sizeof(int));
		
		// Set values to array and print them before sorting
		printf("Unsorted array:\n");
		for (int i = 0; i < N; ++i)
		{
			A[i] = irand(low, high);
			if (i < (N - 1))
			{
				printf("%d ", A[i]);
			}
			else
			{
				printf("%d\n", A[i]);
			}
		}
		
		// Sort array
		quicksort(A, 0, N - 1);
		
		// Print sorted array
		printf("Sorted array:\n");
		for (int i = 0; i < N; ++i)
		{
			if (i < (N - 1))
			{
				printf("%d ", A[i]);
			}
			else
			{
				printf("%d\n", A[i]);
			}
		}
		
		// free memory
		free(A);
	}
	else
	{
		printf("Usage:\n");
		printf("./quicksort_lomuto.out <number of values in array> <lowest of values range> <highest of values range>\n");
	}

	return 0;
}