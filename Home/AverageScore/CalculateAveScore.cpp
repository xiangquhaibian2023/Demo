#include <stdio.h>
#define N 16

typedef struct
{
	char name[10];
	double score;
}STREC;

int fun(STREC a[], STREC b[])
{
	double highest = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i].score > highest)
		{
			highest = a[i].score;
		}
	}

	int nums = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i].score == highest)
		{
			b[nums] = a[i];
			nums++;
		}
	}

	return nums;
}

void main()
{
	STREC Students[N] = { {"GA005",82},{"GA003",75},{"GA002",85},{"GA004",9},{"GA001",95},{"GA007",62},{"GA008",60},{"GA006",85},{"GA015",83},{"GA013",94},{"GA012",78},{"GA014",97},{"GA011",60},{"GA017",97},{"GA018",60},{"GA016",74} }, Results[N] = { 0 };
	
	int numbers = fun(Students, Results);

	printf("The Highest Score Is: %lf, The Numbers Is: %d\n", Results[0].score, numbers);

	printf("Students Name Is: ");

	for (int i = 0; i < N; i++)
	{
		printf("%s\t", Results[i].name);
	}

}