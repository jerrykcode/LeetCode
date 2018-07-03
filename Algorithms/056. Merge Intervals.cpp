/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0)
            return result;
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0].start, end = intervals[0].end;        
        for (int i = 0; i < intervals.size(); i ++) {
            if (end >= intervals[i].start) 
                end = max(end, intervals[i].end);
            else {
                Interval interval(start, end);
                result.push_back(interval);
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        Interval interval(start, end);
        result.push_back(interval);
        return result;
    }
};
