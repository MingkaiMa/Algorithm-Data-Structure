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
    
    void solveCore(char** board, int& count, int col, int length)
    {
        if(col == length)
        {
            count += 1;
            return;
        }
        
        for(int i = 0; i < length; i++)
        {
            if(isSafe(board, i, col, length))
            {
                board[i][col] = 'Q';
                
                solveCore(board, count, col + 1, length);
                
                board[i][col] = '.';
                
            }
            
        }
        
    }
    
    
    int totalNQueens(int n) {
        if(n <= 0)
            return 1;
        
        
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
        

        
        int count = 0;
        int col = 0;
        solveCore(board, count, col, n);
        
        return count;
    }
};
