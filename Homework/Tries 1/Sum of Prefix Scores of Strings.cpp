class TrieNode
{   
    public:
    bool flag;
    TrieNode *child[26];
    int score;
    TrieNode()
    {
        flag = false;
        for(int i = 0;i<26;i++)
        child[i]  = NULL;
        score = 0;
    }
};
class Trie{
    public:
    TrieNode* root = new TrieNode();

    void insert(string word)
    {
        TrieNode * node = root;
        for(auto i:word)
        {
            if(node->child[i-'a']==NULL){
                node->child[i-'a'] = new TrieNode(); 
            }
            node->child[i-'a']->score++;
            node = node->child[i-'a'];
        }
        node->flag = true;
    }
    int count(string word)
    {
        TrieNode * node = root;
        int cnt = 0;
        for(auto i:word)
        {
            cnt += node->child[i-'a']->score;
            node = node->child[i-'a'];
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans;
        Trie *ob = new Trie();
        for(auto i: words)
        {
            ob->insert(i);
        }
        for(auto i:words)
        {
            ans.push_back(ob->count(i));
        }
        return ans;
    }
};
