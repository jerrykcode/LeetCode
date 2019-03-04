class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int size = envelopes.size();
        if (size == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> dp;
        dp.resize(size);
        fill(dp.begin(), dp.end(), 0);
        int result = 0;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++)
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            result = max(result, dp[i]);
        }
        dp.clear();
        vector<int>().swap(dp);
        return result + 1;
    }

private:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return (a.first != b.first ? a.first < b.first : a.second < b.second);
    }

};