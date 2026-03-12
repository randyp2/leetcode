# BRUTE FORCE METHOD

> [!NOTE]
> - Traverse through the array 
> -  for each i
> -     compare to every other form i + 1 to size() - 1
> -     keep track of max profit

> [!CAUTION]
> RUNTIME: O(N^2)

## SORTING
> [!NOTE]
> - create hashmap to store original indices
> - sort in ascending order
> - best time to buy & sell is the prices_sorted[0] & prices_sorted[size() - 1]

> [!CAUTION]
> RUNTIME: O(N^2)

### SLIDING WINDOW METHOD

> [!NOTE]
> - Not given a fixed sublength to look for K, thus this is *dynamic window*
>
>  *Contraints:*
>   Say given prices[l] > prices [r] ({10, 5, ...})
>   Doesn't make sense to keep track of prices[l]
>   Since we want to buy low
> 

*PSEUDO-CODE*
```
init l, r 
init max_profit
while (r < prices.size())
    if prices[l] > prices[r]
        l = r 
    else 
        update max_profit
        ++r;

```








