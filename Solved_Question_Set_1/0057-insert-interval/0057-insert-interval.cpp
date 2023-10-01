class Solution {
public:
    // Returns true if the intervals a and b have a common element.
    bool doesIntervalsOverlap(vector<int>& a, vector<int>& b) {
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }
    
    // Return the interval having all the elements of intervals a and b.
    vector<int> mergeIntervals(vector<int>& a, vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    // Insert the interval newInterval, into the list interval keeping the sorting order intact.
    void insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool isIntervalInserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] < intervals[i][0]) {
                // Found the position, insert the interval and break from the loop.
                intervals.insert(intervals.begin() + i, newInterval);
                isIntervalInserted = true;
                break;
            }
        }
        
        // If there is no interval with a greater value of start value,
        // then the interval must be inserted at the end of the list.
        if (!isIntervalInserted) {
            intervals.push_back(newInterval);
        }
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Insert the interval first before merge processing.
        insertInterval(intervals, newInterval);
        
        vector<vector<int>> answer;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> currInterval = {intervals[i][0], intervals[i][1]};
            // Merge until the list gets exhausted or no overlap is found.
            while (i < intervals.size() && doesIntervalsOverlap(currInterval, intervals[i])) {
                currInterval = mergeIntervals(currInterval, intervals[i]);
                i++;
            }
            // Decrement to ensure we don't skip the interval due to outer for-loop incrementing.
            i--;
            answer.push_back(currInterval);
        }
        
        return answer;
    }
};
