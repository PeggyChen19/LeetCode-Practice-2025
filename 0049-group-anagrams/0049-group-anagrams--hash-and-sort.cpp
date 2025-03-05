class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strsMap;
        vector<vector<string>> ans;
        for (auto i : strs) {
            string original = i;
            sort(i.begin(), i.end());
            (strsMap[i]).push_back(original);
        }
        for (auto it : strsMap) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

/*
unordered_map<string, vector<string>>
vector<vector<string>> ans
for all strs {
  sorted_str = sort(str[i])
  map[sorted_str].append(str[i])  
}

for all map {
    ans.apppend(map->second)
}

T: O(n)
S: O(n)
*/
