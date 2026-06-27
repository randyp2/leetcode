- sliding window solution 
- l = 0, r = 1

*When to move l and where:*

```cpp
if repeating charcter in substr:
    move l UNTIL NO REPEATING CHAR IN SUBSTR
```

*When to move r and where:*
```cpp
if no repeating charcter: 
    move r one space
```

## How to answer the question of repeating charcters 
- freq map/set
