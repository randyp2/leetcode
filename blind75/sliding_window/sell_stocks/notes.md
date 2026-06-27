- find profit to buy and sell stock given input array
- can't return a negative floor is at 0
- arr[i] represents monetary profit
- trying to maximize our profit by choosing two indices: x, y
 - x: purchase price
 - y: selling price 

```cpp
// init l and r pointer

l = 0
r = 1
maxprofit
while (r < size):
    profit = arr[r] - arr[l]
    if (profit >= 0): ++r;
    else ++l

```

