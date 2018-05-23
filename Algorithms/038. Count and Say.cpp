class Solution {
public:
    string countAndSay(int n) {
        string result = "1"; //Initial string
        for (int i = 0; i < n - 1; i ++) {
            string tmp = "";
            int k;
            for (int j = 0; j < result.length(); j += k) {
                k = 0; //count for repeat times记录重复次数
                for (; j + k < result.length() && result[j] == result[j + k]; k ++);
                tmp += std::to_string(k);
                tmp += result[j];
            }
            result = tmp; 
        }
        return result;
    }
};
