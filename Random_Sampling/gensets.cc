#include <iostream>
#include <set>

using namespace std;

void gensets(int m, int n){
	set<int> S;
	while(S.size() < m)
		S.insert(rand() % n);
	set<int>::iterator i;
	for(i = S.begin(); i != S.end(); i++)
		cout << *i << ", ";
	cout << endl;
}

int main(){
	gensets(5, 1000);
}