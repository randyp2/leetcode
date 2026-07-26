# Notes
- We can view the cells/elevation as edge weights
- This is simply asking us the fastest path to the bottom right target with edge weights
- This is **Dijkstras Algorithm**

Differnce is that:
 - Using a 2d grid instead of adjacency list
 - new_cost != curr_dist + edge_weight
 - new_cost = (curr_cost, edge_weight)
 - our new cost is defined by the highest elevation
