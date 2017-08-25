#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
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

bool Search(trie *head, string s){
if(head == NULL)return 0;
trie *cur = head;
for(int i=0 ; i<s.length() ; i++){
    if(cur->child[s[i]-'a'] == NULL)return false;
    cur = cur->child[s[i]-'a'];
}
  return cur->eow;
}

bool children(trie *head){
for(int i=0 ; i<26; i++){
    if(head->child[i] != NULL)return true;
}
return false;
}

bool Delete(trie *&head, string s ,int i){
if(head == NULL)return false;
if(s[i]){
    if(head != NULL && head->child[s[i]-'a']!= NULL && Delete(head->child[s[i]-'a'],s,i+1) && head->eow == false){
        if(!children(head)){
            delete(head);
            head = NULL;
            return true;
        }
        else{return false;}
    }
}
 if(i == s.length() && head->eow == true){
        if(!children(head)){
            delete(head);
            head = NULL;
            return true;
        }
        else{
            head->eow = false;
            return false;
        }
    }
return false;
}

int main()
{
    trie* head = NULL;
    head = Insert(head , "abc");
    head = Insert(head, "akl");
    cout<<Delete(head , "abc", 0)<<endl;
    cout<<Search(head,"abc");
    return 0;
}
