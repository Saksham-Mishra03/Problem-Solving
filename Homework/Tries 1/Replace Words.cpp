
class TrieNode{
    public:
    bool end;
    TrieNode* children[26];

    TrieNode()
    {
        end = false;
        for(int i = 0;i<26;i++)
        {
            children[i] = NULL;
        }
        
    }
};

class Trie
{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode;
    }
    void insert( string word )
    {
    TrieNode *node = root;
    for(auto i: word)
    {
        if(node->children[i - 'a']== NULL)
        {
            node->children[i-'a']  = new TrieNode();
        }
        node = node->children[i-'a'];
    }
    node->end = true;
}

string search(string word)
{
    TrieNode *node = root;
    if(node->children[word[0]-'a']==NULL)
    return word;

    string ans = "";
    for(auto i: word)
    {
        if(node->end==true)
        break;

        if(node->children[i-'a']== NULL)
        {
            return word;
        }
        ans += i;
        node = node->children[i-'a'];
    } 
    return ans;
}

};


class Solution {
public:


    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *root = new Trie;

        for(auto i: dictionary) //insert dictionary in trie
        {
            root->insert(i);
        }
        string word;
        istringstream iss(sentence);
        string res = "";
        while(getline(iss,word,' '))
        {

            res = res +root->search(word) + " "; //break sentense in words and for each word search for the string that can be appended in final ans 
        }
        res.pop_back();
        return res;
    }
};













/****************simplier Solution with  1 class only(using this keyword) ***************/
class TrieNode
{
public:
    bool end;
    TrieNode* children[26];

    TrieNode()
    {
        end = false;
        for(int i = 0;i<26;i++)
        {
            children[i] = NULL;
        }
        
    }
    void insert( string word )
    {
    TrieNode *node = this;
    for(auto i: word)
    {
        if(node->children[i - 'a']== NULL)
        {
            node->children[i-'a']  = new TrieNode();
        }
        node = node->children[i-'a'];
    }
    node->end = true;
}

string search(string word)
{
    TrieNode *node = this;
    if(node->children[word[0]-'a']==NULL) //agr word mile hi na to seedha return krdo
    return word;

    string ans = "";
    for(auto i: word)
    {
        if(node->end==true) //jhaa phle end mile word search krte time bahi break krdo ar jitna ans bna h return krdo
        break;

        if(node->children[i-'a']== NULL)//agr word ka kuch part toh h pr end ane se phle bdl gya to return krdo jo word aya tha
        {
            return word;
        }

        //word bnao ar age traverse kro
        ans += i; 
        node = node->children[i-'a'];
    } 
    return ans;
}

};


class Solution {
public:


    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode *root = new TrieNode;

        for(auto i: dictionary) //insert dictionary in trie
        {
            root->insert(i);
        }
        string word;
        istringstream iss(sentence);
        string res = "";
        while(getline(iss,word,' '))
        {

            res = res +root->search(word) + " "; //break sentense in words and for each word search for the string that can be appended in final ans 
        }
        res.pop_back();
        return res;
    }
};

//T.C - O(d*s*26)
