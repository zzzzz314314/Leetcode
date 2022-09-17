
class Solution {
public:
    int calculate(string s) {
        char op = '+'; 
        int number = 0;
        stack <int> st;
        
        for (int i = 0; i < s.length(); i++)
        {

            char c = s[i];
            
            if (c >= '0' && c <= '9')
            {
                // a number of multiple digits might follow, start accumulating
                
                while(s[i] >= '0' && s[i] <= '9')
                {
                    number = number * 10 + (s[i] - '0');
                    i += 1;
                }
                i -= 1; // though i is on the right place, the for loop outside might redo it.
            }
            
            // i == s.length()-1 is necessary
            // ex: 3+2*2
            // if no (i==s.length()-1)
            // we will not pop 2 out and multiply with 2
            // finally, we will only have +3, +2 in stack
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.length()-1)
            {
                // this c is not the same as op
                // the op is the one before the number, c is the one after
                // the order: op number c
                // as long as we see some operators (not digit number), we can push the signed number into the stack, and end a small round (renew op and number)
                if (op == '+') 
                    st.push(number);
                if (op == '-')
                    st.push(-number);
                if (op == '*')
                {
                    int temp = st.top() * number;
                    st.pop();
                    st.push(temp);
                }
                if (op == '/')
                {
                    int temp = st.top() / number;
                    st.pop();
                    st.push(temp);
                }
                op = s[i];
                number = 0;
            }
               
        }

        int result = 0;
        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }
        return result;
    }
    
};
