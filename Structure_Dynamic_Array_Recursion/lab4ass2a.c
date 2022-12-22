#include <stdio.h>

int main()
{
	static int arr1[10][10];
	int i, j, r, c;
	int f = 0;

	printf("Enter the row and col: ");
	scanf("%d%d", &r, &c);

	printf("Enter the matrix :\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)

			scanf("%d", &arr1[i][j]);

		if (arr1[i][j] == 0)
		{
			++f;
		}
	}
	if (f > ((r * c) / 2))
	{
		printf("matrix is sparse matrix. \n");
	}
	else
		printf("not a sparse matrix.\n");

	return 0;
}