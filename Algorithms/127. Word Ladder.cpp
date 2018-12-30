#define SRC -1
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int wordLen = beginWord.length();
        int src = SRC, des = -1;
        int *dist = new int[n];       
        bool *collected = new bool[n];
        fill(collected, collected + n, false);
        for (int i = 0; i < n; i++) 
            if (wordList[i] == endWord) {                        
                des = i;      
                break;                
            }
        if (des == -1) return 0;
        queue<int> q;
        q.push(src);
        int result = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();            
            string word = v == SRC ? beginWord : wordList[v];
            for (int w = 0; w < n; w++) {
                if (collected[w]) continue;
                int sameSum = 0;      
                for (int i = 0; i < wordLen; i++)
                    if (wordList[w][i] == word[i]) sameSum++;
                if (sameSum == wordLen - 1) {
                    q.push(w);
                    collected[w] = true;
                    dist[w] = v == src ? 2 : dist[v] + 1;
                    if (w == des) {
                        result = dist[w];          
                        goto END;
                    }
                }
            }          
        }
        END: {
            free(dist);
            free(collected);
            return result;
        }
    }
};