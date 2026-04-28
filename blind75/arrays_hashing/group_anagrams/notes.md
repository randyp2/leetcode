# BRUTE FORCE
input = ["act","pots","tops","cat","stop","hat"]
sorted = ["act", "tops", "tops", "act"]

```cpp
loop through the sorted string vector:
    group equal strings together
    store them into a bucket/2d array
```

# FREQUENCY MAP
```cpp

for each str strs:
    init freq_array
    // Calculate the frquency

    // Convert the frequency into a hashable value

    // Store into hashmap
    m[key].push_back(str);

for key, val in map:
    res.push_back(val);
```


# CPP EMPLACE_BACK or PUSH_BACK(std::move(object))

```cpp

push_back(const object& obj)

// if object was a string 
//  loop through each charcter in that string and copy it over too obj

//push_back(const object&& obj)
// obj.data = other.data

```

# KEY TAKEAWAYS
- Use move constructor when we have an objet already created to avoid 
O(n) deepy copy
- sort is highly efficiednt for short strings because of:
    - cache utilization
        - spatial locality
    - uses insertion sort
