class TrieNode {
public:
    TrieNode *children[26];
    bool end = false;
    /*
    TrieNode() {
        end = false;
        for (auto i : children) 
        i = NULL;
    }
    */
};
class Trie {
    TrieNode* root ;
    
public:
    Trie() {
         root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(auto i:word)
        {
            if(node->children[i-'a']==NULL)
            {
                node->children[i-'a'] = new TrieNode();
            }
            node = node->children[i-'a'];
        }
        node->end = true;
        
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(auto i:word)
        {
            if(node->children[i-'a']==NULL)
            return false;
            node = node->children[i-'a'];
        }
        if(node->end==true)
        return true;
        else
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(auto i:prefix)
        {
            if(node->children[i-'a']==NULL)
            return false;
            node = node->children[i-'a'];
        }
        return true;
    }
};
