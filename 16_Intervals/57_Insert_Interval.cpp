class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<vector<int>> ans;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        for(int i = 0; i < intervals.size(); i++) {
            if(newStart > intervals[i][1]) {
                ans.push_back(intervals[i]);
            } else if(newEnd < intervals[i][0]) {
                ans.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), std::back_inserter(ans));
                return ans;
            } else {
                // Overlapping
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};

