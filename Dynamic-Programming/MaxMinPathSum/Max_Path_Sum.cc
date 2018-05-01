#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxPathSum(vector<vector<int>>& grid)
{
    int row = grid.size();
    int col = grid[0].size();

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            // start position
            if(i == 0 && j == 0)
                ;

            // no choice, get this position only from left
            else if(i == 0)
                grid[i][j] += grid[i][j - 1];

            // no chiose, get this position only from top
            else if(j == 0)
                grid[i][j] += grid[i - 1][j];

            // choose the max value between top and left direction
            else
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
        }
    }

    // print path

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            cout << grid[i][j] << ", ";
        cout << endl;
    }


    int i = row - 1;
    int j = col - 1;

    cout << i << "  " << j << endl;
    // 0: down
    // 1: right
    stack<int> path;
    while(i >= 0 && j >= 0)
    {

        if(i == 0 && j == 0)
            break;

        if(j == 0)
        {
            path.push(0);
            i--;
            continue;
        }

        if(i == 0)
        {
            path.push(1);
            j--;
            continue;
        }

        if(grid[i - 1][j] >= grid[i][j - 1])
        {
            path.push(0);
            i--;
        }

        else
        {
            path.push(1);
            j--;
        }



    }


    while(!path.empty())
    {
        if(path.top() == 0)
            cout << "D";
        else
            cout << "R";

        path.pop();
    }



    return grid[row - 1][col -1];
}

int main()
{
    vector<vector<int>> grid = {{5,6,2,3},
                                {6,10,-2,5},
                                {10,3,1,15},
                                {4,6,1,2}};

    cout << maxPathSum(grid) << endl;

}