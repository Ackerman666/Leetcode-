struct TrieNode{
    array<TrieNode*, 26> child{};
    bool is_word = false;
};

class Trie {
private:
    TrieNode* root;
    void destroy(TrieNode* node){
        if(node){
            for(int i=0; i<node->child.size(); ++i)
                if(node->child[i])
                    destroy(node->child[i]);
            delete node;
        }
    }
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto &c : word){
            int idx = c-'a';
            if(!cur->child[idx])
                cur->child[idx] = new TrieNode();
            cur = cur->child[idx];
        }
        cur->is_word = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(auto &c : word){
            int idx = c-'a';
            if(!cur->child[idx])
                return false;
            cur = cur->child[idx];
        }
        return cur->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto &c : prefix){
            int idx = c-'a';
            if(!cur->child[idx])
                return false;
            cur = cur->child[idx];
        }
        return true;
    }

    ~Trie(){
        destroy(root);
    }

};