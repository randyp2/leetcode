# BRUTE FORCE

```cpp
create a freq map
for each num in the vector:
    m[num]++;

vector v;
for each key value pair in map:
    v.push_back({key, value});

sort based on the pair's second value in descending order
return the first k elements in that sorted vector of pairs
```

> [!CAUTION]
> *RUNTIME:* O(nlogn)
> *SPACE COMPLEXITY:* O(n)


# 2D BUCKET
- First create a freq hashmap -> num: freq
- Create a vector of size N
- For each key value pair in the map:
    - index the vector based on the freq
    and then append the key to v[freq]

*RUNTIME:* O(n);
