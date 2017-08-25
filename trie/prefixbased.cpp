//trie with prefix based seach 

#include <iostream>
#include <vector>
using namespace std;

#include <stdio.h>

struct trie{
trie *child[26];
bool eow;
};

trie* getnewnode(){
trie* Node = new trie;
Node->eow = false;
for(int i=0 ; i<26 ; i++)
    Node->child[i]=NULL;
return Node;
}

trie* Insert(trie *head , string s){
if(head == NULL)
    head = getnewnode();
trie *cur = head;
for(int i=0 ; i<s.length() ; i++){
    if(cur->child[s[i]-'a'] == NULL)
        cur->child[s[i]-'a'] = getnewnode();
    cur = cur->child[s[i]-'a'];
}
cur->eow = true;
return head;
}

void print(trie *cur , string s){
    if(cur->eow == true){cout<<s<<" ";}
    for(int i=0 ; i<26 ; i++){
        if(cur->child[i] != NULL){
            print(cur->child[i] , s+= 'a'+i);
            s.erase(s.begin()+s.length()-1);
        }
    }
    return;
}

bool find(trie* head , string pre){
    if(head == NULL) return false;
    trie *cur = head;
    for(int i=0 ; i<pre.length() ; i++){
        if(cur->child[pre[i]-'a'] == NULL)return false;
        cur = cur->child[pre[i]-'a'];
    }
    print(cur,pre);
}

int main() {
	int t;
	cin >> t;
	for(int i=0 ; i<t ; i++){
	    trie * head = NULL;
	    int n;
	    cin>>n;
	    for(int i=0 ; i<n ; i++){
	    string k;
	    cin>>k;
	    head = Insert(head , k);
	    }
	    string pre;
	    cin>>pre;
	    for(int i=1 ; i<=pre.length() ; i++){
        //        cout<<"pre is  "<<pre.substr(0,i)<<endl;
        find(head , pre.substr(0,i));
        cout<<endl;
	    }

	}
	return 0;
}
