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
- 84 Largest Rectangle in Histogram
- 85 Maximal Rectangle
- 907 Sum of Subarray Minimums


### String Parsing
- 224 Basic Calculator
- 227 Basic Calculator II
- 772 Basic Calculator III
