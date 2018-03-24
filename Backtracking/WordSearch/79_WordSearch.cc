class Solution {
public:
    
    bool aDFS(vector<vector<char>>& board, string word, int start_i, int start_j, int wordCount, int** helper)
    {
                
        int i = start_i;
        int j = start_j;

        // cout << "i : " << i << " j: " << j << "\n";
        helper[i][j] = true;
        
        if(i - 1 >= 0 && board[i - 1][j] == word[wordCount] && helper[i - 1][j] != true)
        {
            if(wordCount == word.size() - 1)
                return true;
            

            // cout << "*\n";
            if(aDFS(board, word, i - 1, j, wordCount + 1, helper))
            {
                return true;
            }
            helper[i - 1][j] = false;
            
        }

        if(i + 1 < board.size() && board[i + 1][j] == word[wordCount] && helper[i + 1][j] != true)
        {
            if(wordCount == word.size() - 1)
                return true;

            // cout << "**\n";
     
            if(aDFS(board, word, i + 1, j, wordCount + 1, helper))
                return true;
            helper[i + 1][j] = false;
        }

        if(j - 1 >= 0 && board[i][j - 1] == word[wordCount] && helper[i][j - 1] != true)
        {
            if(wordCount == word.size() - 1)
                return true;

            
            // cout << "***\n";
            if(aDFS(board, word, i, j - 1, wordCount + 1, helper))
                return true;
            helper[i][j - 1] = false;

        }

        if(j + 1 < board[0].size() && board[i][j + 1] == word[wordCount] && helper[i][j + 1] != true)
        {
            if(wordCount == word.size() - 1)
                return true;

            // cout << "****\n";
            if(aDFS(board, word, i, j + 1, wordCount + 1, helper))
                return true;
            helper[i][j + 1] = false;
        }

        
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        //leave corner case
        
        //don't forget
        
        int **helper = new int*[board.size()];
        

        for(int i = 0; i < board.size(); i++)
        {
            helper[i] = new int[board[0].size()];
        }
        

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
                helper[i][j] = false;
        }
        
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0])
                {
                    if(word.size() == 1)
                        return true;
                    
                    if(aDFS(board, word, i, j, 1, helper))
                        return true;
                    helper[i][j] = false;
                }
            }
        }
        return false;
                
    }
};
