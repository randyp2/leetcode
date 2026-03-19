# BRUTE FORCE 


> [!NOTE]
> ```
> for each i in str:
>   for each j in str:
>       compute substr from [i...j]
> ```
>

> [!IMPORTANT]
> *Important formula:* replacements_needed = window_size - max_freq_of_chars
>  replacements_needed <= k in order to be valid


> [!NOTE]
> Optimized solution
> - Given our formula, that is the only constraint for the window to be 
> a valid size
> - Sliding window: 
>  1. start l and r on the lhs, 
>  2. check if window is valid 
>     * if it is then update max and ++r 
>     * else move shrink window until replacements_needed <= k 

*IMPORTANT*
 - Max substr answer is only maximized when a new max_freq is found
 - It's okay for a stale max_freq number and an invalid window
 - Since the valid window would be recorded earlier

RUNTIME: 
 - r < N: O(N) 
 - count frequencies: O(26) ~ O(1)


