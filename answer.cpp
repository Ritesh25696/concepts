#include<bits/stdc++.h>
using namespace std;

long long countkDist(string s){
    int k  =0 ;
    long long res = 0;
    map<char , int> f;
    for(int i=0 ; i<s.length() ; i++){
        if(f.find(s[i]) == f.end())f[s[i]] = 1;
        else f[s[i]]++;
        if(f.size() == 26){
            while(f.size() == 26){
                res+=s.length()-i;
                f[s[k]]--;
                if(f[s[k]] == 0){f.erase(s[k]);}
                k++;
            }
        }
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    map<char , int> f;
    while(t--){
        string s;
        cin>>s;
        cout<<countkDist(s)<<endl;
    }
    return 0;
}





#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int max = INT_MIN;
    for(int i=1 ; i<=n ; i++){
        int x;
        cin>>x;
        if(x >= max){
            max = x;
            cout<<i<<" ";
        }
    }
    return 0;
}
