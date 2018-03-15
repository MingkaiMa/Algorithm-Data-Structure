class Solution {
public:
    
    bool isSafe(char** board, int row, int col, int length)
    {
        for(int i = 0; i < col; i++)
        {
            if(board[row][i] == 'Q')
                return false;
        }
        
        int i = row;
        int j = col;
        
        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        
        i = row;
        j = col;
        while(i < length && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            
            i++;
            j--;
        }
        
        return true;
        
    }
    
    void solveCore(char** board, vector<vector<string>>& R, int col, int length)
    {
        if(col == length)
        {
            vector<string> r;
            for(int i = 0; i < length; i++)
            {
                string s = "";
                for(int j = 0; j < length; j++)
                    s += board[i][j];
                
                r.push_back(s);
            }
            R.push_back(r);
            return;
        }
        
        for(int i = 0; i < length; i++)
        {
            if(isSafe(board, i, col, length))
            {
                board[i][col] = 'Q';
                
                solveCore(board, R, col + 1, length);
                
                board[i][col] = '.';
                
            }
            
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        if(n <= 0)
        {
           vector<vector<string>> R;
            return R;
        }
        
        
        char **board = new char*[n];
        
        for(int i = 0; i < n; i++)
            board[i] = new char[n];
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                board[i][j] = '.';
            }
        }
        

        
        vector<vector<string>> R;
        int col = 0;
        solveCore(board, R, col, n);
        
        return R;
    }
};
