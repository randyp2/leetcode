# First Method

> [!NOTE]
> * Traverse through entire list 
> * For each element perform __*new_target = target - curr_num*__
>  - Then perform TWO SUM on the new target with the remaining list
*RUNTIME: O(N^2)*

> [!CAUTION]
> * Doing so does not handle duplicates well 
> * i.e.) [-1, -1, 0, 1] => [[-1, 0, 1], [-1, 0, 1]]

## Second Method

> [!NOTE]
>  * First sort the list
>  * Traverse through entire list 
>  * For each element perform __*new_target = target - curr_num*__
>   - Then perform TWO SUM on the new target with the remaining list

