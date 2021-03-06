#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
 
long long tree[200001][5];

long long max(long long a, long long b){
	return (a > b) ? a : b;
}
 
void height(int curr){
	if (curr != 0){
		height(tree[curr][1]);
		height(tree[curr][2]);
		tree[curr][3] = 1 + max(tree[tree[curr][1]][3],tree[tree[curr][2]][3]);
		tree[curr][4] = tree[tree[curr][2]][3] - tree[tree[curr][1]][3];
	}
}
int main() {
    ifstream fin("balance.in");
	ofstream fout("balance.out");
	
    int n, i, temp;
    fin >> n;
   	
    for (i = 1; i < n+1; i++) {
        fin >> temp;
        tree[i][0] = temp;
        fin >> temp;
        tree[i][1] = temp;
        fin >> temp;
        tree[i][2] = temp;
        tree[i][3] = 1;
    }
    
    height(1);	
    
    for (i = 1; i < n+1; i++){
    	fout << tree[i][4] << endl;
    }
    return 0;
}
