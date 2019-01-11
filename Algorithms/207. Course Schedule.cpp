typedef struct GNode {
    int label;
    int indegree;
    vector<int> neighbors;
    GNode(int label) : label(label), indegree(0) {}
} *PGNode;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, PGNode> graph;
        int prerequisiteCourses = 0;
        for (auto it = prerequisites.begin(); it != prerequisites.end(); it++) {
            int v = it->first, w = it->second;
            if (graph[v] == NULL) {
                graph[v] = new GNode(v);
                prerequisiteCourses++;   
            }
            if (graph[w] == NULL) {
                graph[w] = new GNode(w);
                prerequisiteCourses++;                
            }
            graph[v]->indegree++;
            graph[w]->neighbors.push_back(v);
        }
        queue<int> q;
        for (auto it = graph.begin(); it != graph.end(); it++) 
            if (it->second->indegree == 0) {
                q.push(it->first);
            }
        int numV = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            numV++;
            for (int w : graph[v]->neighbors) 
                if (--(graph[w]->indegree) == 0) {
                    q.push(w);
                }      
        }
        for (auto it = graph.begin(); it != graph.end(); it++) 
            if (it->second != NULL) {
                delete it->second;
                it->second = NULL;
            }
        graph.clear();
        map<int, PGNode>().swap(graph);
        return numV == prerequisiteCourses;
    }
};