#define MOD 1000000007
#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,r;
	    cin>>n>>r;
	    if(r>n){
	        cout<<0<<endl;
	        continue;
	    }
	    r = min(n-r , r);
	    vector<int> val(r+1 , 0);
	    val[0] =1;
	    for(int i=1 ; i<= n ; i++){
	        for(int j=min(i,r) ; j>0 ; j--){
	            val[j] += val[j-1]%MOD;
	            val[j] %= MOD;
	        }
	    }
	    cout<<val[r]<<endl;
	}
	return 0;
}
