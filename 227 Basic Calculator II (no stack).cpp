
class Solution {
public:
    int calculate(string s) {
        char op = '+'; 
        int number = 0;
        int result = 0;
        int temp_result = 0;
        
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
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.length()-1)
            {
                // the c is not the same as op
                // the op is the operator before the number, c is the one after
                // the order: op number c (THIS IS IMPORTANT!)
                switch (op)
                {
                    case '+': temp_result += number; break;
                    case '-': temp_result -= number; break;
                    case '*': temp_result *= number; break;
                    case '/': temp_result /= number; break;
                }
                if (c == '+' || c == '-' || i == s.length()-1)
                {
                    // consider the order: op number c = temp_result c
                    // and when c is + or -, we can safely sum the temp_result to final result, and clear temp_result
                    // when c is * or /, we should not directly sum them to the final result, and we should keep the temp_result to be multiplied or divided by the next number
                    result += temp_result;
                    temp_result = 0;
                }
                op = c;
                number = 0;
            }
               
        }

    
        return result;
    }
    
};
