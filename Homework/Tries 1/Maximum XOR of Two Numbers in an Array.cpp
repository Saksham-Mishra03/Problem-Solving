class TrieNode{
    public:
    bool end;
    TrieNode * child[2];
    
    TrieNode()
    {
       end = false;
        child[0] = NULL;
        child[1] = NULL;
    }
    
};
class Trie
{
    
    public:
    TrieNode* root = new TrieNode();
   
    void insert(int data)
    {
        TrieNode* node = root;
        for(int i = 31;i>=0;i--)
        {   
            int bit = (data>>i) &1;
            if(node->child[bit]==NULL)
            {
                node->child[bit] = new TrieNode();
            }
            node = node->child[bit];
        }
        node->end = false;
    }

    int checkmax(int data)
    {
        TrieNode* node = root;
        int res = 0;
        for(int i = 31;i>=0;i--)
        {
            int bit = (data>>i) &1;
            if(node->child[!bit])  //agr bit 1 mili to xor max k lie 0 dunege
            {
                res += (1<<i); //res += 1<<i; 
                node = node->child[!bit];
            }   
            else node = node->child[bit];
        }
        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *ob = new Trie();
        for(auto i:nums)
        {
            ob->insert(i);
        }
        int maxi = 0;
        for(auto i:nums)
        {
            maxi = max(maxi,ob->checkmax(i));
        }
        return maxi;
    }
};
