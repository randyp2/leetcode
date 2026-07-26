#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class Solution {

  public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {

        // <edge weight, neighbor>
        using State = std::pair<int, int>;

        // Construct our adjacency list
        std::vector<std::vector<State>> graph(n + 1);

        for (const auto &edge : times) {
            int source = edge[0];
            int target = edge[1];
            int weight = edge[2];

            graph[source].push_back({weight, target});
        }

        std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
        std::vector<int> edge_weights(n + 1, INT_MAX);

        edge_weights[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            const auto [weight, curr_node] = pq.top();
            pq.pop();

            if (weight > edge_weights[curr_node])
                continue;

            for (const auto &[travel_cost, neighbor] : graph[curr_node]) {
                int new_cost = weight + travel_cost;

                if (new_cost >= edge_weights[neighbor])
                    continue;

                edge_weights[neighbor] = new_cost;
                pq.push({new_cost, neighbor});
            }
        }

        /*
            Traverse through all the edge edge_weights
             - If one node as INT_MAX then we weren't able to traverse through
           all of them -> return -1;
             - Return max edge weight since that dictates the time needed to
           visit all nodes

         */
        int res = INT_MIN;
        for (int node = 1; node <= n; ++node) {
            if (edge_weights[node] == INT_MAX)
                return -1;

            res = std::max(res, edge_weights[node]);
        }

        return res;
    }
};

int main() {
    std::cout << "--- ---\n";
    return 0;
};
