class TrieNode
{
    public:
    bool end;
    TrieNode *child[26];
    int ind ;
    int mini;
    TrieNode()
    {
        end = false;
        for(int i= 0;i<26;i++)
        child[i] = NULL;
        ind =INT_MAX;
        mini = INT_MAX;
    }
};
class Trie{
    TrieNode *root = new TrieNode();
    public:
    void insert(string word,int index)
    {
        TrieNode* node = root;
        for(auto i: word)
        {
            if(node->child[i-'a']==NULL)
            {
                node->child[i-'a'] = new TrieNode();
            }
 
            if(word.size()<node->child[i-'a']->mini)
            {
                node->child[i-'a']->mini= word.size();
                node->child[i-'a']->ind = index;
            }
            node = node->child[i-'a'];
            
        } 
        node->end = true;
    }
    int search(string word)
    {
        TrieNode *node = root;
        // int ans;
        for(auto i :word)
        {   
            if(node->child[i-'a']!=NULL)
            {
                node = node->child[i-'a'];
            }
            else
            {
                return node->ind;
            }
        }
        return node->ind;
    }

};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie *root = new Trie();
        //agr koi bhi string match na ho to usme minimum length nikalne k lie phle hi minimum lenth ki string dhun lo
        int m=INT_MAX;
        int x=-1;
        for(int i= 0;i<wordsContainer.size();i++){
            if(wordsContainer[i].size()<m)
            {
                m = wordsContainer[i].size();
                x = i;
            }
        reverse(wordsContainer[i].begin(),wordsContainer[i].end());
        root->insert(wordsContainer[i],i);
        }

        vector<int>ans;
        for(auto i:wordsQuery)
        {
        reverse(i.begin(),i.end());
        if(root->search(i)==INT_MAX)
        ans.push_back(x);
        else
        ans.push_back(root->search(i));
        }

        return ans;
    }
};
