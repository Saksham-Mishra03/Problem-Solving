#include<bits/stdc++.h>
using namespace std;
class TrieNode{
	public:
	bool end;
	TrieNode * children[26];
	vector<string>commonprefix;
	
	TrieNode()
	{
		end = false;
		for(int i = 0;i<26;i++)
		{
			children[i] = NULL;
		}
		for(auto i: commonprefix)
		{
			i = "";
		}
	}
};
void insert(TrieNode *root, string n)
{
	TrieNode *node = root;
	for(char ch: n)
	{
		if(node->children[ch-'a']==NULL)
		{
			node->children[ch-'a'] = new TrieNode();
		}
		node = node->children[ch-'a'];
		node->commonprefix.push_back(n);
	}
	node->end=true;
}
void  query(TrieNode *root)
{
	TrieNode* node = root;
	while(true)
	{
		char ch;
		cout<<"enter char";
		cin>>ch;
		if(ch=='*')
		break;
		if(node->children[ch-'a']==NULL)
		{
		cout<<"not found"<<endl;
		break;
		}
		node = node->children[ch-'a'];
		for(auto i:node->commonprefix)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		
	}
}
int main()
{
	string names[] = { "ram","raju","naman","nandu"};
	TrieNode* root = new TrieNode();
	for(string n:names)
	{
		insert(root, n);
	}
	query(root);
}
