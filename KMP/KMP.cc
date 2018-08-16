#include <iostream>
#include <string>
#include <vector>

using namespace std;



void kmp_table(string W, vector<int>& T){
	// vector<int> T(W.size() + 1, -1);

	int pos = 1, cnd = 0;

	while(pos < W.size()){
		if(W[pos] == W[cnd]){
			T[pos] = T[cnd];
			pos += 1;
			cnd += 1;
		}
		else{
			T[pos] = cnd;
			cnd = T[cnd];

			while(cnd >= 0 && W[pos] != W[cnd])
				cnd = T[cnd];

			pos += 1;
			cnd += 1;
		}
	}
	T[pos] = cnd;
}

int kmp_search(string S, string W){

	vector<int> T(W.size() + 1, -1);

	kmp_table(W, T);

	for(auto& i: T)
		cout << i << ", ";
	cout << endl;

	int j = 0, k = 0, res = 0;

	while(j < S.size()){
		if(W[k] == S[j]){
			k += 1;
			j += 1;
			if(k == W.size()){
				res += 1;
				k = T[k];
			}
		}
		else{
			k = T[k];
			if(k < 0){
				j += 1;
				k += 1;
			}
		}
	}

	return res;
}

int main(){
	string S = "ABC ABCDABD ABCDABCDABDE";
	string W = "ABCDABD";
	//string W = "ababaca";
	cout << kmp_search(S, W) << endl;
}









