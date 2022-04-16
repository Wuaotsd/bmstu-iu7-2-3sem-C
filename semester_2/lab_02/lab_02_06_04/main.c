#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>
# define N 10000 // размерность
# define I 10 // итерации

void process_1(int b[N], int nb);

void process_2(int c[N], int nc);

void process_3(int *pd, int nd);

int random_array(int a[N], int *na);

int main(void)
{
	int arr_a[N], na;

	struct timeval tv_start, tv_stop;
	int64_t start_time, end_time, elapsed_time = 0;

	int rc = random_array(arr_a, &na);
	if (rc == EXIT_FAILURE)
	{
		return rc;
	}
	printf("\nProcess_1 - a[i]:\n");
	
	for (int k = 1; k <= I; k++)
	{
		int arr_b[N], nb = na;
		for (int i = 0; i < nb; i++)
			arr_b[i] = arr_a[i];
			
		gettimeofday(&tv_start, NULL);
		process_1(arr_b, nb);
		gettimeofday(&tv_stop, NULL);
		
		start_time = (tv_start.tv_sec * 1000000LL + tv_start.tv_usec);
		end_time = (tv_stop.tv_sec * 1000000LL + tv_stop.tv_usec);
		elapsed_time += end_time - start_time;
	}
	elapsed_time = elapsed_time / (I - 2);
	printf("\nTime = %" PRId64, elapsed_time);
	
	//process_2
	printf("\nProcess_2 - *(a + i):\n");
	elapsed_time = 0;
	for (int k = 1; k < I; k++)
	{
		int arr_c[N], nc = na;
		for (int i = 0; i < nc; i++)
			arr_c[i] = arr_a[i];
			
		gettimeofday(&tv_start, NULL);
		process_2(arr_c, nc);
		gettimeofday(&tv_stop, NULL);
		
		start_time = (tv_start.tv_sec * 1000000LL + tv_start.tv_usec);
		end_time = (tv_stop.tv_sec * 1000000LL + tv_stop.tv_usec);
		elapsed_time += end_time - start_time;
	}
	elapsed_time = elapsed_time / (I - 2);
	printf("\nTime = %" PRId64, elapsed_time);

	//process_3
	printf("\nProcess_3 - *pa:\n");
	elapsed_time = 0;
	for (int k = 1; k < I; k++)
	{
		
		int arr_d[N], nd = na;
		for (int i = 0; i < nd; i++)
			arr_d[i] = arr_a[i];
			
		int *pd = arr_d;
		
		gettimeofday(&tv_start, NULL);
		process_3(pd, nd);
		gettimeofday(&tv_stop, NULL);
		
		start_time = (tv_start.tv_sec * 1000000LL + tv_start.tv_usec);
		end_time = (tv_stop.tv_sec * 1000000LL + tv_stop.tv_usec);
		elapsed_time += end_time - start_time;
	}
	elapsed_time = elapsed_time / (I - 2);
	printf("\nTime = %" PRId64, elapsed_time);
	
	return EXIT_SUCCESS;
}

int random_array(int a[N], int *na)
{
	printf("Input size of array: ");
	if (scanf("%d", na) != 1 || (*na <= 0) || (*na > N))
	{
		printf("Error! Input is incorrect!");
		return EXIT_FAILURE;
	}
	
	for (int i = 0; i < *na; i++)
		a[i] = rand() % 20;
	printf("\n");
	
	for (int i = 0; i < *na; i++)
		printf(" %d", a[i]);
		
	return EXIT_SUCCESS;
}

void process_1(int b[N], int nb)
{
	int count = 0, count_uniq;
	int i = 0, j;

	while (i < nb)
	{
		j = i + 1; 
		while (j < nb)
		{
			if (b[j] == b[i])
			{
				count++;
				break;
			}
			++j;
		}
		++i;
	}
	count_uniq = nb - count;
	printf(" %d", count_uniq);
}

void process_2(int c[N], int nc)
{
	int count = 0, count_uniq;
	int i = 0, j;

	while (i < nc)
	{
		j = i + 1; 
		while (j < nc)
		{
			if (*(c + j) == *(c + i))
			{
				count++;
				break;
			}
			++j;
		}
		++i;
	}
	count_uniq = nc - count;
	printf(" %d", count_uniq);
}

void process_3(int *pd, int nd)
{
	int count = 0, count_uniq;
	int *pe = (pd + nd);
	
	while (pd < pe)
	{
		int *pb = (pd + 1);
		while (pb < pe)
		{
			if (*pb == *pd)
			{
				count++;
				break;
			}
			++pb;
		}
		++pd;
	}
	count_uniq = nd - count;
	printf(" %d", count_uniq);
}