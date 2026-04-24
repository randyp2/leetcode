class TimeMap {
  private:
    unordered_map<string, vector<std::pair<string, int>>>
        m; // str: [<value, timestamp>, ...]
  public:
    TimeMap() {
        // Nothing to implement?
    }

    void set(string key, string value, int timestamp) {

        // If key, value are the same just append to the list

        // Insert to hashmap
        m[key].push_back({value, timestamp});
    }

    // Get based on timestamp
    // Two edge cases:
    // 1) If timestamp doesn't exist get the next highest one
    // 2) If key doesn't exist just return ""
    string get(string key, int timestamp) {

        // Key doesn't exist
        if (!m.contains(key))
            return "";

        // Get vector associated w/ key
        const vector<std::pair<string, int>> &value_list = m[key];
        const int N = value_list.size();

        // Binary search
        int left = 0;
        int right = N - 1;
        string last_value = "";

        while (left <= right) {
            int mid = (right + left) / 2;
            int curr_timestamp = value_list[mid].second;

            if (curr_timestamp == timestamp) // Combine to just <=
                return value_list[mid].first;
            if (curr_timestamp > timestamp) {
                right = mid - 1;
            } else {
                last_value = value_list[mid].first; // !!
                left = mid + 1;
            }
        }

        return last_value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
