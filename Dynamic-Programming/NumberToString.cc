#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numberToString(string s){
	if(s.size() == 0)
		return 0;

	if(s.size() == 1)
		return 1;

	vector<int> res(s.size() + 1, 0);

	res[s.size()] = 1;
	for(int i = s.size() - 1; i >= 0; i--){
		if(i == s.size() - 1){
			res[i] = 1;
			continue;
		}

		res[i] += res[i + 1];

		string nbs = "";
		nbs += s[i];
		nbs += s[i + 1];


		int nb = stoi(nbs);

		cout << "nb is: " << nb << endl;
		if(nb <= 25)
			res[i] += res[i + 2];

	}

	for(int i = 0; i < res.size(); i++)
		cout << res[i] << ", ";
	cout << endl;

	return res[0];
}

int main(){

	string nb = "12215";

	cout << numberToString(nb) << endl;

}