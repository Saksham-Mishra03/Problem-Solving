class TrieNode {
public:
    int ind;
    int sum;
    TrieNode* child[2];
    
    TrieNode(){
        ind = 0;
        sum = 0;
        child[0] = NULL;
        child[1] = NULL;
    }
};
class Solution {
    void insert(TrieNode* root, int num, int idx){
        for( int i = 31; i >= 0; i--){
       
            int bit = 1 & (num >> i) ;
        
            if ( root->child[bit] == NULL){
                root->child[bit] = new TrieNode();
            }
            root = root->child[bit];
        }
        root->sum += idx;
        root->ind++;
    }
    int count(TrieNode* root, int num, int idx){
        for( int i = 31; i >= 0; i--){
            int bit = 1 & (num >> i);
        
            if (root->child[bit] == NULL){
                return 0;
            }
            root = root->child[bit];
        }
        return ((root->ind * idx) - root->sum);
    }
public:
    int countTriplets(vector<int>& arr) {
       long long ans=0;
        int XOR = 0;
        TrieNode* root = new TrieNode();
    
        for ( int i = 0 ; i < arr.size(); i++){
            insert(root, XOR, i);
            XOR ^= arr[i];
            ans = (ans + count(root, XOR, i)) % 1000000007;
        }
        return ans; 
    }
};
