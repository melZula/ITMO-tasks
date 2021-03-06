#include <stdio.h>
#define SWAP(A, B) { int t = A; A = B; B = t; }

int main(void)
{
  int x, m, i, N;
  FILE *fin, *fout;
  fin = fopen("smallsort.in", "r");
  fout = fopen("smallsort.out", "w");
  fscanf(fin, "%d\n", &N);
  long int a[N];
  for (i=0; i<N; ++i)
  {
  	fscanf(fin, "%ld", &a[i]);
  }
  
  x=N; //size
  
  do{
	m=0;
  	for (i=1; i<x; i++)
  	{
  		if (a[i-1]>a[i])
  		{
			SWAP(a[i-1],a[i]);
			m=i;
  		}
  	}
  	x=m;    //last ordered
  }while (x!=0);
  
  
  for (i=0; i<N; ++i)
  {
  	fprintf(fout, "%ld ", a[i]);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
