#include <iostream>
#include <stdlib.h>  
#include <time.h>  

using namespace std;

void genknuth(int m, int n){
	for(int i = 0; i < n; i++){
		srand(time(NULL));
		if((rand() % (n - i)) < m){
			cout << i << ", ";
			m--;
		}
	}
}


int main(){
	genknuth(10, 200);
}