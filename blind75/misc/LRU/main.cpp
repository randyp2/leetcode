#include <iostream>
#include <list>
#include <stdexcept>
#include <unordered_map>
#include <utility>

/**
 * Desing linked list where head is MRU and tail is LRU
 * get -> turns element into MRU so push to the front
 * and remove its current posiition
 */

/**
 * MRU = Elements that have been pushed, or elements that have been accessed
 *
 * Linked list s.t:
 * Head = MRU -> Tail = LRU
 */
class LRUCache {
  public:
    LRUCache(int capacity) : capacity(capacity) {}

    /* Must be constant time so no .remove */
    int get(int key) {

        // Check for existance
        if (m.find(key) == m.end())
            return -1;

        // Move element to the head meaning that it is MRU
        // 1) Erase element using .erase(iterator)
        // 2) Push to the front
        // 3) Return the value pair

        std::list<std::pair<int, int>>::iterator it = m[key];

        // Can't use erase because you need value -> use splice instead
        cache.splice(cache.begin(), cache, it); // Move element to the front
        m[key] = cache.begin();

        return cache.front().second;
    }

    /* Must be constant time so no .remove */
    // Two cases:
    // 1) key already exisst so must ovewrite value
    // 2) Capacity is full
    void put(int key, int value) {
        const int SIZE = cache.size();

        // Already in cache -> overwrite and push to front
        if (m.find(key) != m.end()) {
            // Push to front
            cache.splice(cache.begin(), cache, m[key]);

            // Overwrite value
            cache.front().second = value;
            m[key] = cache.begin();
            return;
        }

        if (SIZE >= this->capacity) {
            m.erase(cache.back().first);
            cache.pop_back();
        }

        cache.push_front({key, value});
        m[key] = cache.begin();
    }

  private:
    int capacity;

    // Keep track of the key and its position in the hashmap
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m;

    std::list<std::pair<int, int>> cache;
};

int main() {
    std::cout << "--- LRU CACHE ---\n";

    return 0;
}
