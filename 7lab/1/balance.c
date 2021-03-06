#include <stdio.h>
 
long long tree[200001][3];
int HGT = 0;
 
void height(int curr, int h){
	if (curr != 0){
		HGT = (h > HGT) ? h : HGT;
		if (tree[curr][1] != 0){
		    height(tree[curr][1], h+1);
		}
		if (tree[curr][2] != 0){
		    height(tree[curr][2], h+1);
		}
	} else
		HGT = 0;
}
int main() {
    FILE *fin, *fout;
	fin = fopen("balance.in", "r");
	fout = fopen("balance.out", "w");
	
    int n, i, temp;
    fscanf(fin, "%d\n", &n);
   
    for (i = 1; i < n+1; i++) {
        fscanf(fin, "%lld %lld %lld\n", &tree[i][0], &tree[i][1], &tree[i][2]);
    }
    
    int right;
    
    for (i = 1; i < n+1; i++){
    	height(tree[i][2], 1);
    	right = HGT;
    	HGT = 0;
    	height(tree[i][1], 1);
    	fprintf(fout, "%d\n", right-HGT);
    	HGT = 0;
    }
    fclose(fin);
	fclose(fout);
    return 0;
}
