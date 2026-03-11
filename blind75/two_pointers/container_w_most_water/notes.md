# INPUT AND OUTPUT
*input:* std::vector<int> height
 * Contains the height of each cordinate where the index is the x-axis
 * (x,y) -> (i, height[i])

*output:* two indices i such that it translates to the max area of the graph

## BRUTE FORCE
> [!NOTE]
> For each i:
>    for each j: 
>       calculate height 
>       update max height 

> [!CAUTION]
> *RUNTIME:* O(N^2) 

### TWO POINTER METHOD 
> [!NOTE]
> * Keep track of left ponter and right pointer 
> * l = 1, r = size() - 1; => Max possible width
> * update max height
> * height[l] <= height[r] => shift l 
> * height[l] > height[r] => shift r
>
> ```
> l = 1, r = size() - 1; // Initialize pointers
> maxArea = 0;
> while (l < r):
>   currArea = calculateArea(l, r); 
>   maxArea = currArea > maxArea ? currArea : maxArea;
>   
>   if (heights[l] <= heights[r])
>       shift l;
>   else
>       shift r;
> ``` 


