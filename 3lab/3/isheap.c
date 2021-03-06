#include <stdio.h>

int sheap(long long arr[], int n)
{
	int i;
	for (i = 1; i<=n/2; i++)
	{
		if ( (arr[i] > arr[i*2]) || ((2*i+1 <= n)&&(arr[i] > arr[i*2+1])) )
			return 0;
	}
	return 1;
}

int main(void)
{
	int i, n;
	FILE *fin, *fout;
	fin = fopen("isheap.in", "r");
	fout = fopen("isheap.out", "w");

	fscanf(fin, "%d\n", &n);
	long long a[n+1];
	a[0] = 0;
	for (i = 1; i<n+1; i++)
		fscanf(fin, "%lld ", &a[i]);
		
	if (sheap(a, n) == 1)
		fprintf(fout, "YES\n");
	else
		fprintf(fout, "NO\n");
		
	fclose(fin);
	fclose(fout);
	return 0;
}
