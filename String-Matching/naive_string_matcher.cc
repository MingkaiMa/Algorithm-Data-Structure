#include <iostream>
#include <string>

using namespace std;

void naive_string_matcher(string T, string P)
{
    int n = T.size();
    int m = P.size();

    for(int s = 0; s <= n - m; s++)
    {
        string newString(T.begin() + s, T.begin() + s + m);
        if(newString == P)
            cout << "Pattern occurs with shift " << s << endl;
    }
}

int main()
{
    string T = "abcdecde";
    string P = "cde";

    naive_string_matcher(T, P);
}