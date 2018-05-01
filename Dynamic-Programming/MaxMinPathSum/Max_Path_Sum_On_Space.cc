#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int maxPathSum(vector<vector<int>>& grid)
{
    int row = grid.size();
    int col = grid[0].size();

    // here is the extra space we use
    vector<int> v(row, grid[0][0]);

    for(int i = 1; i < row; i++)
        v[i] = v[i - 1] + grid[i][0];

    for(auto& i: v)
        cout << i << ", ";
    cout << endl;
    for(int j = 1; j < col ; j++)
    {
        v[0] += grid[0][j];
        for(int i = 1; i < row; i++)
            v[i] = max(v[i - 1], v[i]) + grid[i][j];

        for(auto& ii: v)
            cout << ii << ", ";
        cout << endl;
    }

    return v[row - 1];

}

int main()
{
    vector<vector<int>> grid = {{5,6,2,3},
                                {6,10,-2,5},
                                {10,3,1,15},
                                {4,6,1,2}};

    cout << maxPathSum(grid) << endl;

}