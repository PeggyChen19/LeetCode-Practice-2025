class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0]) { // before new
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < n && newInterval[1] >= intervals[i][0]) { // overlapping
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while (i < n) { // after new
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

/*
[1, 3], [7, 9]
New: [4, 5] -> [1, 3], [4, 5], [7, 9]
New: [2, 5] -> [1, 5], [7, 9]
New: [2, 10] -> [1, 10]

每個 interval 一定只屬於以下三類之一
1. 在 new 前，完全沒重疊 -> 直接放入 ans
2. 重疊 -> 開頭取 min，結尾取 max
3. 在 new 後，完全沒重疊的 -> 直接放入 ans
比較困難的點是怎麼去判斷，第一種是 i.end < new.start 很明顯，所以第一種結束的時候 i.end >= new.start，所以這兩個變數就不用再考慮了，接下來直接去想怎麼樣才會「重疊」很不直覺，所以可以先去想在 new 後的要怎麼樣才會「不重疊」，得到 new.end < i.start，所以反過來就會是重疊的條件
-> insight：先去想「不重疊」的條件，再去反推「重疊」的條件，不重疊又分為在前面或在後面

For intervals before new (i.end < new.start) -> insert to ans directly
For intervals overlap new (new.end >= i.start) -> merge
For intervals after new (new.end < i.start) -> insert to ans directly
*/