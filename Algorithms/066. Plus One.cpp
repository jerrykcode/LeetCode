class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int size = digits.size();
        if (size == 0) return result;
        int k = 1;
        stack<int> s;
        for (int i = size - 1; i >= 0; i--) {
            s.push((digits[i] + k) % 10);
            k = (digits[i] + k) / 10;
        }
        if (k != 0) s.push(k);
        while (!s.empty()) {
            result.push_back(s.top());    
            s.pop();
        }
        return result;
    }
};
