# BRUTE FORCE

> [!NOTE]
> *"abcabcbb"*
> Look at each char
>   find the longest non repeating substr from that char 
>   repeat for all other chars

> [!CAUTION]
> *Runtime:* O(N^2)


## DYNAMIC SLIDING WINDOW 

> [!NOTE]
> l = 0, r = 1
> if l and r, are equal chars
> then incr l 
> else incr r 
> 
> we should be discarding every repeating character by moving the left over
> and expanding the window if there are no repeating characters found

> [!NOTE]
> "pwwkkew"
> using our approach this would result in max_substr = 3 because of the nested w
> -> Keep hashmap: char -> frequency
> if hashmap[char] > 1 set incr l, hashmap[lchar]--,
> ++r

