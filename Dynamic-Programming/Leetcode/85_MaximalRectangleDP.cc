class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        if(heights.size() <= 0)
            return 0;
        
        if(heights.size() == 1)
            return heights[0];
        
        
        int maxArea = 0;
        
        stack<int> Stack;
        
        for(int i = 0; i < heights.size(); i++)
        {
            if(Stack.empty() || Stack.top() <= heights[i])
                Stack.push(heights[i]);
            else
            {
                int count = 0;
                while(!Stack.empty() && Stack.top() > heights[i])
                {
                    count++;
                    maxArea = max(maxArea, Stack.top() * count);
                    Stack.pop();
                }
                while(count--)
                    Stack.push(heights[i]);
                Stack.push(heights[i]);
            }
        }
        
        int count = 1;
        while(!Stack.empty())
        {
            maxArea = max(maxArea, Stack.top() * count);
            Stack.pop();
            count++;
        }
        
        return maxArea;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() <= 0)
            return 0;
        
        //dynamic programming
        
        const int m = matrix.size();
        const int n = matrix[0].size();
        int * left = new int[n];
        int * right = new int[n];
        int * height = new int[n];
        for(int i = 0; i < n; i++)
        {
            left[i] = 0;
            right[i] = n;
            height[i] = 0;
        }
        int maxArea = 0;
        
        for(int i = 0; i < m; i++)
        {
            int cur_left = 0, cur_right = n;
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], cur_left);
                else
                {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            
            for(int j = n - 1; j >= 0; j--)
            {
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else
                {
                    right[j] = n;
                    cur_right = j;
                }
            }
            
            cout << "line is: " << i << "\n";
            
            cout << "height is: \n";
            for(int k = 0; k < n; k++)
                cout << height[k] <<", ";
            cout << "\n";
            
            cout << "left is: \n";
            for(int k = 0; k < n; k++)
                cout << left[k] <<", ";
            cout << "\n";
            
            cout << "right is: \n";
            for(int k = 0; k < n; k++)
                cout << right[k] <<", ";
            cout << "\n";
            

            
            
            for(int j = 0; j < n; j++)
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            
        }
        
        return maxArea;
    }
};
