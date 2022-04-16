#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int n);
void selection_sort(int a[], int n);

int main(void)
{
	int n;
	FILE *myFile;
	
	myFile = fopen("my_data.txt", "r");
	if (fscanf(myFile, "%d,", &n) != 1)
	{
		if (n == 0)
			printf("The file is empty!");
		else
			printf("Error! The size is incorrect!");
		return EXIT_FAILURE;
	}
	if (n <= 0)
	{
		printf("The size must be > 0!");
		return EXIT_FAILURE;
	}	
	int arr_a[n];
	if (myFile == NULL) 
	{
        printf("\nError! Reading File\n");
		return EXIT_FAILURE;
	}
	
	for (int i = 0; i < n; i++) 
	{
        if (fscanf(myFile, "%d,", &arr_a[i]) != 1)
		{
			printf("Error! The element in file is incorrect!");
			return EXIT_FAILURE;
		}
    }
	
	fclose(myFile);
	
	selection_sort(arr_a, n);
	printf("\nArray was sorted with Selection Sort: ");
    print_array(arr_a, n);
	return EXIT_SUCCESS;
}

void print_array(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (i == (n - 1))
			printf("%d", a[i]);
		else
			printf("%d ", a[i]);
	}
}

void selection_sort(int a[], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;
		int buff = a[min];
		a[min] = a[i];
		a[i] = buff;
	}
}
