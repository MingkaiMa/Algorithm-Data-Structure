#include <iostream>
#include <string>

using namespace std;

int longestWanted(const string s)
{
    int maxLength = -1;
    int currLength = 0;

    int *array = new int[26];
    for(int i = 0; i < 26; i++)
        array[i] = -1;


    for(int i = 0; i < s.size(); i++)
    {
        int preIndex = array[s[i] - 'a'];

        if(preIndex < 0 || i - preIndex > currLength)
            currLength++;

        else
        {
            if(currLength > maxLength)
                maxLength = currLength;

            currLength = i - preIndex;
        }

        array[s[i] - 'a'] = i;
    }

    if(currLength > maxLength)
        maxLength = currLength;

    return maxLength;
}

int main()
{
    string s = "arabcacfr";
    cout << longestWanted(s) << endl;
}