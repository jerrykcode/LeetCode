class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> result;
        if (n == 0) return result;
        initSet(n);
        for (vector<int> edge : edges) {
            int u = edge[0], v = edge[1];
            u--; v--;
            int rootu = findRoot(u);
            int rootv = findRoot(v);
            if (rootu == rootv) {
                result = edge;
                break;
            }
            else 
                unionSet(rootu, rootv);
        }
       // free(set_);
        return result;
    }

private:
    int *set_;
    void initSet(int n);
    int findRoot(int a);
    void unionSet(int a, int b);
};

void Solution::initSet(int n) {
    set_ = new int[n];
    fill(set_, set_ + n, -1);
}

int Solution::findRoot(int a) {
    if (set_[a] < 0) return a;
    return set_[a] = findRoot(set_[a]);
}

void Solution::unionSet(int a, int b) {
    int roota = findRoot(a);
    int rootb = findRoot(b);
    if (set_[roota] < set_[rootb]) {
        set_[roota] += set_[rootb];
        set_[rootb] = roota;
    }
    else {
        set_[rootb] += set_[roota];
        set_[roota] = rootb;
    }
}