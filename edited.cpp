#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<map>
using namespace std;

void mintime(vector<int> &e , vector<int>&t ,vector<int>& ml, int distance , int ene, int cnt)  {
int energy;
int q = distance;
int dis;
int time =0;
int minutes = 0;
int cmin = 0;
int cm;
       for(int i=0; i<=q ; i++){
            energy = ene;
            dis = distance;
            energy -= e[0]*i;
            if(energy < 0)break;
            dis-=i;
            time = t[0]*i;
            minutes = ml[0]*i;
            if(dis == 0){cmin = time;cm = minutes;}
        for(int j=0; j<=q-i; j++){
            energy -= e[1]*j;
            if(energy < 0)break;
            dis-=j;
            time += t[1]*j;
            minutes += ml[1]*j;
            if(dis == 0){cmin = time;cm = minutes;}

            for(int k=0 ; k<=q-i-j; k++){
                energy -= e[2]*k;
                if(energy < 0)break;
                dis-=k;
                time += t[2]*k;
                minutes += ml[2]*k;
                if(dis == 0){cmin = time;cm = minutes;}

                for(int l=0; l<=q-k-j-i; l++){
                    energy -= e[3]*l;
                    if(energy < 0)break;
                    dis-=l;
                    time += t[3]*l;
                    minutes += ml[3]*l;
                    if(dis == 0){cmin = time;cm = minutes;}

                    for(int m=0; m<=q-l-k-j-i ; m++){
                      energy -= e[4]*m;
                      if(energy < 0)break;
                      dis-=m;
                      time += t[4]*m;
                      minutes += ml[4]*m;
                      if(dis == 0){cmin = time;cm = minutes;}
                    }
                }
            }
        }
       }
       cout<<cmin<<" "<<cm<<endl;
       cmin+=cm/60;
       cm %= 60;
       cout<<"#"<<cnt<<" "<<cmin<<" "<<cm<<endl;
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
        e.push_back(a);
        m.push_back(b);
        t.push_back(c);
    }
    mintime(e,t,m,distance,ene,z);
    z++;
    }

    return 0;
    }
