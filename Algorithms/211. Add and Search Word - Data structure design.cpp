#define N_LETTERS 26
#define TO_INDEX(c) (c - 'a')
#define IS_LOWERCASE(c) (c >= 'a' && c <= 'z')
typedef struct TNode {
    char value;
    bool isWordEnd;
    struct TNode **subtrees;
    TNode(char value) : value(value), isWordEnd(false) {
        subtrees = new struct TNode*[N_LETTERS];
        for (int i = 0; i < N_LETTERS; i++)
            subtrees[i] = NULL;
    }
    ~TNode() { free(subtrees); }
} *Tree;
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary();
    
    /** Adds a word into the data structure. */
    void addWord(string word);
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word);
 
private:
    Tree root;
    bool searchWord(Tree tree, string& word, int index);
};

WordDictionary::WordDictionary() : root(new TNode(' ')) {
    
}

void WordDictionary::addWord(string word) {   
    Tree tree = root;
    for (int i = 0; i < word.size(); i++) {
        if (tree->subtrees[TO_INDEX(word[i])] == NULL) 
            tree->subtrees[TO_INDEX(word[i])] = new TNode(word[i]);
        tree = tree->subtrees[TO_INDEX(word[i])];
    }
    tree->isWordEnd = true;
}

bool WordDictionary::search(string word) {
    return searchWord(root, word, 0);
}

bool WordDictionary::searchWord(Tree tree, string& word, int index) {  
    for (int i = index; i < word.size(); i++) {
        if (IS_LOWERCASE(word[i])) {
            if (tree->subtrees[TO_INDEX(word[i])] == NULL) return false;
            tree = tree->subtrees[TO_INDEX(word[i])];
        }
        else {
            for (int j = 0; j < N_LETTERS; j++) 
                if (tree->subtrees[j] != NULL) {
                    if (searchWord(tree->subtrees[j], word, i + 1)) return true;
                }
            return false;            
        }
    }
    return tree->isWordEnd;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */