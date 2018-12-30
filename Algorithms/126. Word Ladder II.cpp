/*
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
*/
#define SRC -1
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		n = wordList.size();
		wordLen = beginWord.length();
		result.clear();
		src = SRC, des = -1;
		for (int i = 0; i < n; i++)
			if (wordList[i] == endWord) {
				des = i;
				break;
			}
		if (des == -1) return result;
		this->beginWord = beginWord;
		this->endWord = endWord;
		vector<int> *paths = new vector<int>[n];
		if (bfs(wordList, paths)) {
			vector<int> path;
			path.push_back(des);
			dfs(wordList, paths, path, src, des);
			path.clear();
			vector<int>().swap(path);
		}
		for (int i = 0; i < n; i++) {
			paths[i].clear();
			vector<int>().swap(paths[i]);
		}
		return result;
	}
private:
	bool bfs(vector<string>& wordList, vector<int> *paths);
	void dfs(vector<string>& wordList, vector<int> *paths, vector<int>& path, int src, int des);

	int n;
	int wordLen;
	int src, des;
	string beginWord, endWord;
	vector<vector<string>> result;
};

bool Solution::bfs(vector<string>& wordList, vector<int> *paths) {
	int *dist = new int[n];
	bool *collected = new bool[n];
	fill(collected, collected + n, false);
	queue<int> q;
	q.push(src);
	bool flag = false;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v == des) {
			flag = true;
			break;
		}
		string word = v == SRC ? beginWord : wordList[v];
		for (int w = 0; w < n; w++) {
			int sameSum = 0;
			for (int i = 0; i < wordLen; i++)
				if (word[i] == wordList[w][i]) sameSum++;
			if (sameSum == wordLen - 1) {
				if (!collected[w]) {
					dist[w] = v == SRC ? 2 : dist[v] + 1;
					collected[w] = true;
					paths[w].push_back(v);
					q.push(w);
				}
				else if (dist[v] + 1 == dist[w]) {
					paths[w].push_back(v);
				}
			}
		}
	} //while   
	free(dist);
	free(collected);
	return flag;
}

void Solution::dfs(vector<string>& wordList, vector<int> *paths, vector<int>& path, int src, int des) {
	if (paths[des][0] == src) {
		vector<string> tmp;
		tmp.push_back(beginWord);
		for (int i = path.size() - 1; i >= 0; i--)
			tmp.push_back(wordList[path[i]]);
		result.push_back(tmp);
		return;
	}
	for (int v : paths[des]) {
		path.push_back(v);
		dfs(wordList, paths, path, src, v);
		path.pop_back();
	}
}

/*
int main() {
	Solution s;
	int n;
	vector<string> wordList;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		wordList.push_back(word);
	}
	string beginWord, endWord;
	cin >> beginWord >> endWord;
	vector<vector<string>> ladders;
	ladders = s.findLadders(beginWord, endWord, wordList);
	for (vector<string> ladder : ladders) {
		bool flag = false;
		for (string word : ladder) {
			if (flag) cout << " ";
			else flag = true;
			cout << word;
		}
		cout << endl;
	}
	for (int i = 0; i < ladders.size(); i++) {
		ladders[i].clear();
		vector<string>().swap(ladders[i]);
	}
	ladders.clear();
	vector<vector<string>>().swap(ladders);
	return 0;
}
*/
