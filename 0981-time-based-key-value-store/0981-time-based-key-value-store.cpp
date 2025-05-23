class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> record;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        record[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!record.count(key)) return "";
        return binarySearch(record[key], timestamp);
    }
private:
    string binarySearch(vector<pair<string, int>>& vec, int target) {
        int left = 0, right = vec.size() - 1;
        string result = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            auto [val, time] = vec[mid];
            if (time <= target) { // go right
                result = val; // the candidate <= target
                left = mid + 1; // look for larger candidate
            } else { // go left
                right = mid - 1;
            }
        }
        return result;
    }
};

/**
* Your TimeMap object will be instantiated and called as such:
* TimeMap* obj = new TimeMap();
* obj->set(key,value,timestamp);
* string param_2 = obj->get(key,timestamp);

Format: key: {{value, time1}, {value, time2}, ....} // time is strictly increasing
Given a timestamp, find the time <= timestamp in a sorted array -> Binary Search
Time Compleixty:
set: O(1)
get: O(logn)
Data structure:
unordered_map<string, vector<pair<int, int>>>
*/