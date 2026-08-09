#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
    // Key, Value
    using Node = std::pair<int, int>;

  public:
    LRUCache(int capacity) : capacity_(capacity) {}

    /*
        - Lookup key in unordered map to get position in linked list
        - Move that node in LL to front

        Edge cases)
         - key doesnt exist
    */
    int get(int key) {
        if (!m_.contains(key))
            return -1;

        const auto it = m_[key];
        cache_.splice(cache_.begin(), cache_, it); // Move to MRU

        // Iterator points to node and follows it -> no need to update map
        return it->second;
    }

    /*

        If key is new & not at capacity:
         - put to front of the list
         - add to unordred_map

        If key is not new:
         - update the value of exiting key
         - move to front

        If at capcity:
         - Evict LRU node (back of the list)
         - Insert normally
    */
    void put(int key, int value) {

        // If key already exists
        if (m_.contains(key)) {
            get(key);                       // Moves to front
            cache_.begin()->second = value; // Update w/ new value
            return;
        }

        // Evict logic
        if (cache_.size() == capacity_) {
            const auto node = cache_.back();
            m_.erase(node.first);
            cache_.pop_back();
        }

        // Add another node
        cache_.push_front({key, value});
        m_[key] = cache_.begin();
    }

  private:
    std::list<Node> cache_;
    std::unordered_map<int, std::list<Node>::iterator> m_;

    int capacity_; // Max capcity
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    std::cout << "--- ---\n";
    return 0;
};
