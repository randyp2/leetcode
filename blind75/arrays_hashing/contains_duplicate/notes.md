# BRUTE FORCE SOLUTION

```cpp
for i ... N:
    for j ... N;
        if num[i] == num[j]: return true;
return false;
```

> [!CAUTION]
> *Runtime:* O(n^2)
> *Space Complexity:* O(1)

# UNORDERD_MAP FREQ APPROACH
```cpp
init unorderd_map m;
for i...N:
    m[i]++;
    if m[i] > 1: return true;
return false

```

# UNORDERD_SET 
```cpp
init unorderd_set s;

for i...N:
    check if i is already inserted
    if yes: return true;
    else:  s.insert(i);
return false
```


# SORT METHOD
```cpp
sort(vector);

for i...N:
    if nums[i] == nums[i + 1]: return true;
return false
```

# FREQ BUT W/ ARRAY
```cpp
init freq_aray;

for int num : nums: 
    incr decr nums[i]

```

> [!CAUTION]
> *Runtime:* O(nlogn)

