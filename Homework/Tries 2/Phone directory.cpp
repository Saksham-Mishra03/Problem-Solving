    class TrieNode
    {
        public:
        TrieNode *child[26];
        bool end;
        
        TrieNode()
        {
            end=0;
            for(int i=0;i<26;i++)
            child[i]=NULL;
        }
    };
    
    class Trie
    { 
        TrieNode *root;
        
        public:
        Trie()
        {
            root=new TrieNode();
        }
        
        
        void insert(string word)
        {
            TrieNode *node=root;
            
            for(char c:word)
            {
                int index=c-'a';
                
                if(node->child[index]==NULL)
                {
                    node->child[index]=new TrieNode();
                    node=node->child[index];
                }
                
                else
                node=node->child[index];
            }
            
            node->end=true;
        }
        
        
        
        void findContact(string prefix,TrieNode *node,vector<string>&contact)
    {
        if(node->end)
        contact.push_back(prefix);
        
        
        for(char c='a';c<='z';c++)
        {
            int index=c-'a';
            
            if(node->child[index])
            findContact(prefix+c,node->child[index],contact);
        }
    }
    
    vector<string> searchContact(string prefix)
    {
        TrieNode *node=root;
        
        for(char c:prefix)
        {
           int index=c-'a';
        //   prefix doesnt exist
            if(node->child[index]==NULL)
            return {"0"};
            node=node->child[index];
        }
        
        vector<string>contact;
        
        findContact(prefix,node,contact);
        
        return contact;
    }
    };
    
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie ob;
        
        for(int i=0;i<n;i++)
        ob.insert(contact[i]);
        
        vector<vector<string>>result;
        
        string prefix="";
        
        for(int i=0;i<s.size();i++)
        {
            prefix+=s[i];
            
            vector<string> contact=ob.searchContact(prefix);
            result.push_back(contact);
        }
        
        return result;
    }
