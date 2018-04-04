#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool isPalindrome(string s)
{
    if(s.size() == 0)
        return false;

    int emptyFlag = 0;

    for(auto& c: s)
    {
        if(c != ' ')
        {
            emptyFlag = 1;
            break;
        }
    }

    if(emptyFlag == 0)
        return true;

    int i = 0, j = s.size() - 1;
    while(i <= j)
    {
        if(s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}

void partitionCore(string s, int startIndex, vector<string>& r, vector<vector<string>>& res)
{
//     if(isPalindrome(s.substr(startIndex, s.size() - startIndex)))
//     {
//         cout << "all\n";
//         r.push_back(s.substr(startIndex, s.size() - startIndex));
//
//         for(auto& c: r)
//            cout << c << ", ";
//         cout << "\n";
//
//         res.push_back(r);
//         r.pop_back();
//     }


     if(startIndex == s.size())
     {
        cout << "end\n";
         for(auto& c: r)
            cout << c << ", ";
         cout << "\n";
         res.push_back(r);
         return;
     }

     for(int i = startIndex + 1; i <= s.size(); i++)
     {
        if(isPalindrome(s.substr(startIndex, i - startIndex)))
        {
            r.push_back(s.substr(startIndex, i - startIndex));
            partitionCore(s, i, r, res);
            r.pop_back();
        }
    }
}


int main()
{
    string s = "aabaa";
    vector<string> r;
    vector<vector<string>> res;

    //cout << isPalindrome(s) << "\n";

    partitionCore(s, 0, r, res);
    for(auto& c: res)
    {
        for(auto& s: c)
            cout << s << ", ";
        cout << "\n";
    }
}