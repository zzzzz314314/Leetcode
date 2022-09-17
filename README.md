# Leetcode
### Monotonic increasing/decreasing stack
找出比height小的index，stack維持 (1. pop 2. 計算 3. push) increasing sequence，找出比height大的index，stack維持 (1. pop 2. 計算 3. push) decreasing sequence
```cpp
// 以向左找出比height小的index為例
stack.push(-1);
for (int i = 0; i < vec.size(); i++)
{
  // 1. pop
  while(stack.top() != -1 && stack.top() >= vec[i])
    stack.pop();
  // 2. 計算
  ans.push(stack.top());
  // 3. push
  stack.push(vec[i]);
}
```
- 496 Next Greater Element I
- 503 Next Greater Element II
- 42 Trapping Rain Water
- [84 Largest Rectangle in Histogram](https://github.com/zzzzz314314/Leetcode/blob/master/84.%20Largest%20Rectangle%20in%20Histogram.cpp)
- [85 Maximal Rectangle](https://github.com/zzzzz314314/Leetcode/blob/master/85.%20Maximal%20Rectangle.cpp)  
- 907 Sum of Subarray Minimums


### String Parsing
- [224 Basic Calculator](https://github.com/zzzzz314314/Leetcode/blob/master/224.%20Basic%20Calculator.cpp)   
- [227 Basic Calculator II (stack version)](https://github.com/zzzzz314314/Leetcode/blob/master/227%20Basic%20Calculator%20II.cpp)   
- [227 Basic Calculator II (no stack version)](https://github.com/zzzzz314314/Leetcode/blob/master/227%20Basic%20Calculator%20II%20(no%20stack).cpp)   
- [772 Basic Calculator III](https://github.com/zzzzz314314/Leetcode/blob/master/772%20Basic%20Calculator%20III.cpp)  
