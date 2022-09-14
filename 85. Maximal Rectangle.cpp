class Solution {
public:
    
    vector <int> find_left_smaller(vector <int> v)
    {
        stack <int> st;
        vector <int> ans(v.size());
        
        st.push(-1);
        
        for (int i = 0; i < v.size(); i++)
        {
            while(st.top() != -1 && v[st.top()] >= v[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector <int> find_right_smaller(vector <int> v)
    {
        stack <int> st;
        vector <int> ans(v.size());
        
        st.push(-1);
        
        for (int i = v.size() - 1; i >= 0; i--)
        {
            while(st.top() != -1 && v[st.top()] >= v[i])
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    int maximalRectangle_1d(vector <int> v)
    {
        vector <int> left_smaller = find_left_smaller(v);
        vector <int> right_smaller = find_right_smaller(v);
        int maxx = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int l = left_smaller[i];
            int r = right_smaller[i];
            //if (l == -1)
                //l = 0;
            if (r == -1)
                r = v.size();
            maxx = max(maxx, (r - l - 1) * v[i]);
        }
        return maxx;
    }
    
    
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> matrixx(matrix.size(), vector<int>(matrix[0].size()));
        
        // turn char to int
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                matrixx[i][j] = matrix[i][j] - '0';
            }
        }
        
        // some preprocessing to turn this 2d maximalRectangle problem to 1d maximalRectangle problem
        for (int i = 1; i < matrixx.size(); i++)
        {
            for (int j = 0; j < matrixx[i].size(); j++)
            {
                if (matrixx[i][j] == 1 && matrixx[i-1][j] != 0)
                    matrixx[i][j] += matrixx[i-1][j];
            }
        }
        //for each row, run the 1d maximalRectangle problem
        int maxx = 0;
        for (int i = 0; i < matrixx.size(); i++)
            maxx = max(maxx, maximalRectangle_1d(matrixx[i]));
        
        return maxx;
    }
};
