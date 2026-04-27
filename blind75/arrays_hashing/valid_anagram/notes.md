> [!NOTE] 
> Have an early guard to check if the lenghts are equal
> Anagrams would always have equal length, given that their
> character frequencies are equivalent

# BRUTE FORCE

```cpp
for c in S:
    for c_2 in T:
        if c_2 == '#': continue
        else c_2 = '#';

for c in T:
    if c != '#': return false;

return true;
```

> [!CAUTION]  
> *RUNTIME:* O(m * n)
> m - length of string s
> n - lenght of string t
> *SPACE COMPLEXITY:* O(1)

# FREQ MAP

```cpp
for c in s:
    m_s[c]++;

for c in t:
    m_t[c]++;

return m_s == m_t;
```

# FREQ ARRAY
> [!NOTE] 
> Similar approach to unorded MAP
> use arrays w/ fix size of 26


