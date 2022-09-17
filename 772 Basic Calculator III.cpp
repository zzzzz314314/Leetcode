// not tested on leetcode
class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int temp_result = 0;
        int result = 0;
        int number = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c >= '0' && c <= '9')
            {
                while (s[i] >= '0' && s[i] <= '9')
                {
                     number = number * 10 + (s[i] - '0');
                     i += 1;
                }
                i -= 1;
            }
            
            if (c == '(')
            {
                // find the ending )
                int par_start = i + 1;
                int par_cnt = 0;
                for ( ; i < s.length(); i++)
                {
                    if (s[i] == '(') par_cnt += 1;
                    if (s[i] == ')') par_cnt += 1;
                    if (par_cnt == 0) break;
                }
                number = calculate(s.substr(par_start, i-1-par_start+1)) // the thing inside () has index [par_start, i-1]
                // the ')' is automatically ignored by the increment of i in the for loop (line 9)   
            }
            
            if (c == '+' || c == '-' || c == '*' || c == '/' || i = s.length()-1)
            {
                // order: op number c
                switch (op)
                {
                    case '+': temp_result += number; break;
                    case '-': temp_result -= number; break;
                    case '*': temp_result *= number; break;
                    case '/': temp_result /= number; break;
                }
                // if c is + or -, we can safely sum the temp_result to result, and clear temp_result
                // if c is * or /, we should wait for the following numbers to be multiplied or divided by temp_result
                if (c == '+' || c == '-' || i ==s.length() - 1)
                {
                    result += temp_result;
                    temp_result = 0;
                }
                number = 0;
                op = c;
            }
        }
      return result;
    }
  
};
