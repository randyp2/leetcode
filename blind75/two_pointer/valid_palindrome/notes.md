# BRUTE FORCE
- Strip string of non alphanumeric characters
- Reverse the string and compare w/ original
- Return true if equal else false

*RUNTIME:* O(N)
*SPACE COMPLEXITY:* O(1)


# TWO POINTER APPROACH 
- Keep track of leftmost pointer
- Keep track of rightmost pointer
- Palinedrome if equal all the way through

```cpp
int l = 0;
int r = N - 1;
while (l < r):
    while (str[l] is non-alphnum) l++;
    while (str[r] is non-alphnum) r--;

    // Compare logic convert to lowercase

return true;
```
