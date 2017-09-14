#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<map>
using namespace std;

void mintime(vector<int> &e , vector<int>&t , int distance , int ene , int cnt)  {
int energy;
int q = distance;
map<int,int> mymap;
for(int i=0 ; i<t.size() ; i++){
    mymap[t[i]] = e[i];
}
int j=0;
for(auto i=mymap.begin() ; i!=mymap.end() ; i++){
    t[j] = i->first;
    e[j] = i->second;
    j++;
}
int dis;
int time =0;
int cmin = INT_MAX;
       for(int i=1; i<=q ; i++){
            energy = ene;
            dis = distance;
            energy -= e[0]*i;
            if(energy < 0 || dis < 0)break;
            dis-=i;
            time = t[0]*i;
            cout<<"l1 dis "<<dis<<" time "<<time<<" energy "<<energy<<endl;
            if(dis == 0)cmin = min(cmin,time);
        for(int j=1; j<=q-i; j++){
            energy -= e[1]*j;
            if(j != 1) energy+=e[1]*(j-1);
            if(energy < 0 || dis < 0)break;
            dis--;
            time += t[1];
            cout<<"l2 dis "<<dis<<" time "<<time<<" energy "<<energy<<endl;
            if(dis == 0)cmin = min(cmin,time);

            for(int k=1 ; k<=q-i-j; k++){
                energy -= e[2]*k;
                if(k != 1) energy+=e[2]*(k-1);
                if(energy < 0 || dis < 0)break;
                dis--;
                time += t[2];
                cout<<"l3 dis "<<dis<<" time "<<time<<" energy "<<energy<<endl;
                if(dis == 0)cmin = min(cmin,time);

                for(int l=1; l<=q-k-j-i; l++){
                    energy -= e[3]*l;
                    if(energy < 0 || dis < 0)break;
                    if(l != 1) energy+=e[3]*(l-1);
                    dis--;
                    time += t[3];
                    cout<<"l4 dis "<<dis<<" time "<<time<<" energy "<<energy<<endl;
                    if(dis == 0)cmin = min(cmin,time);

                    for(int m=1; m<=q-l-k-j-i ; m++){
                      energy -= e[4]*m;
                      if(m != 1) energy+=e[4]*(m-1);
                      if(energy < 0 || dis < 0)break;
                      dis--;
                      time += t[4];
                      cout<<"l5 dis "<<dis<<" time "<<time<<" energy "<<energy<<endl;
                      if(dis == 0)cmin = min(cmin,time);
                    }
                }
            }
        }
       }
        cout<<"#"<<cnt<<" "<<cmin/60<<" "<<cmin%60<<endl;
    }

    int main(){
     int t;
    cin>>t;
    int z = 1;
    while(t--){
    int ene, distance;
    cin>>ene>>distance;
    vector<int> e , t , m;
    for(int i=0 ; i<5 ; i++){
        int a , b , c;
        cin>>a>>b>>c;
        e.push_back(c);
        t.push_back(a*60 + b);
    }
    mintime(e,t,distance,ene,z);
    z++;
    }

    return 0;
    }
