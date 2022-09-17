class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1; // 1: +, -1: -
        stack <int> st;
        
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            
            if (c >= '0' && c <= '9')
            {
                // we might see a number of many digits, start accumulating
                int temp = 0;
                while(s[i] >= '0' && s[i] <= '9')
                {
                    temp = temp * 10 + (s[i] - '0');
                    i += 1;
                }
                i -= 1; // although i is one right place, the for outside will do it again
                result += sign * temp;
            }
            if (c == '+')
                sign = 1;
            if (c == '-')
                sign = -1;
            if (c == '(')
            {
                // we are going to start a new calculation. 
                // 1. Put the current results and sign into stack
                // 2. clear out the current results and sign
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            if (c == ')')
            {
                // we have finished the "new calculation" and have a result of that calculation
                // we also have the previous stored result (the calculation result before '(') and sign (just before the '(') in the stack
                // we take them out and combine with the results of the "new calculation"
                result *= st.top(); st.pop(); // the sign
                result += st.top(); st.pop();
            }
        }
        return result;
    }
};
