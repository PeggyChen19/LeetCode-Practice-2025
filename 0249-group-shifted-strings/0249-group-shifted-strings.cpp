class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strs) {
        unordered_map<string, int> dict;
        vector<vector<string>> result;
        for (string& s : strs) {
            // calculate distance pattern
            string distPattern = "";
            for (int i = 0; i < s.size() - 1; i++) {
                int distance = s[i + 1] - s[i];
                if (distance < 0)
                    distance += 26;
                distPattern += to_string(distance) + "#";
            }

            if (dict.count(distPattern)) {
                int idx = dict[distPattern];
                result[idx].push_back(s);
            } else {
                result.push_back({s});
                dict[distPattern] = result.size() - 1;
            }
        }

        return result;
    }
};