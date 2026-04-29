> [!CAUTION]
> No division can be used in algorithm
> *RUNTIME:* O(n)
> *SPACE-COMPLEXITY:* O(1) -> No extra data structures should be used

# BRUTE FORCE
```cpp
vector ans;
for int i ... N:
    product = 1;

    for int j ... N:
        if (i == j) continue;
        product *= arr[j]

    ans[i] = product;
```

*RUNTIME:* O(n^2)
*SPACE-COMPLEXITY* O(1)

# PRECOMPUTE LEFT PRODUCTS AND RIGHT PRODCUTS
- Precompute the left products of each i
- Precompute the right products of each i
- Output[i] = leftP[i] * rightP[i]

```cpp
vector leftP;
for each i in input array:
    leftP[i] = leftP[i - 1] * nums[i - 1]

vector rightP;
for each i in input array: // Reverse order
    rightP[i] = rightP[i + 1] * nums[i + 1]

// Build the output array
```
 
*RUNTIME:* O(3n) = O(n)
*SPACE COMPLEXTY:* O(2n) = O(n)
