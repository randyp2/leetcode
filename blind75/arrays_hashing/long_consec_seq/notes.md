# BRUTE FORCE
Sort -> O(nlogn) 
- We want it to be O(n)


# SOLUTION
```cpp
Create a set of the numbers in our vector

for each number in vector:
    start_number = number;

    while (set.contains(start_number - 1)) 
        start_number--;

    // Find the longest interval
    while (set.contains(start_number + 1)
        count++;
        start_number++;
```
