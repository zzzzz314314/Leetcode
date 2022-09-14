class Solution {
public:
    
    vector <int> find_left_smaller_index(vector <int> heights)
    {
        vector <int> left_smaller_index(heights.size());
        //vector <int> left_smaller_index;
        stack <int> st;
        st.push(-1);
        for (int i = 0; i < heights.size(); i++)
        {
            while(st.top() != -1 && heights[st.top()] >= heights[i])// maintain increasing sequence in stack
                st.pop();
            //left_smaller_index.push_back(st.top());
            left_smaller_index[i] = st.top();
            st.push(i);
        }
        return left_smaller_index;
    }
    
    vector <int> find_right_smaller_index(vector <int> heights)
    {
        vector <int> right_smaller_index(heights.size());
        //vector <int> right_smaller_index;
        stack <int> st;
        st.push(-1);
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while(st.top() != -1 && heights[st.top()] >= heights[i])// maintain increasing sequence in stack
                st.pop();
            //right_smaller_index.push_back(st.top());
            right_smaller_index[i] = st.top();
            st.push(i);
        }
        return right_smaller_index;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        vector <int> left_smaller_index = find_left_smaller_index(heights);
        vector <int> right_smaller_index = find_right_smaller_index(heights);
        /*
        cout << "left_smaller_index:" << endl;
        for (int i = 0; i < left_smaller_index.size(); i++)
            cout << left_smaller_index[i] << " ";
        cout << endl;
        cout << "right_smaller_index:" << endl;
        for (int i = 0; i < right_smaller_index.size(); i++)
            cout << right_smaller_index[i] << " ";
        cout << endl;
        */
        
        int maxx = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            int l = left_smaller_index[i];
            int r = right_smaller_index[i];
            //if (l == -1)
                //l = 0;
            if (r == -1)
                // r = heights.size() - 1;
                r = heights.size();
            // maxx = max(maxx, (r - l + 1) * heights[i]);
            maxx = max(maxx, (r - l - 1) * heights[i]);
            
        }
        return maxx;
    }
};
