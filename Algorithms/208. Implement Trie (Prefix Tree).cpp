typedef struct TNode {
    char value;
    struct TNode **subtrees;
    bool isWordEnd;
    TNode(char value) : value(value), isWordEnd(false) {
        subtrees = new struct TNode*[26];
        for (int i = 0; i < 26; i++)
            subtrees[i] = NULL;
    }
    ~TNode() { free(subtrees); }
} *Tree;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie();
    
    /** Inserts a word into the trie. */
    void insert(string word);
    
    /** Returns if the word is in the trie. */
    bool search(string word);
        
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);

private:
    Tree root;
};

Trie::Trie() : root(new TNode(' ')) {

}

void Trie::insert(string word) {
    Tree t = root;
    for (int i = 0; i < word.size(); i++) {
        if (t->subtrees[word[i] - 'a'] == NULL) {
            t->subtrees[word[i] - 'a'] = new TNode(word[i]);            
        }
        t = t->subtrees[word[i] - 'a'];
    }
    t->isWordEnd = true;
}

bool Trie::search(string word) {
    Tree t = root;
    for (int i = 0; i < word.size(); i++) {
        if (t->subtrees[word[i] - 'a'] == NULL) return false;
        t = t->subtrees[word[i] - 'a'];
    }
    return t->isWordEnd;
}

bool Trie::startsWith(string prefix) {
    Tree t = root;
    for (int i = 0; i < prefix.size(); i++) {
        if (t->subtrees[prefix[i] - 'a'] == NULL) return false;
        t = t->subtrees[prefix[i] - 'a'];
    }
    return true;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
