#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

void mintime(vector<int> &e , vector<int>&t , int distance , int ene)  {
int energy;
int q = distance;


int dis;
int time =0;
int cmin = INT_MAX;
       for(int i=1; i<=q ; i++){
            energy = ene;
            dis = distance;
            energy -= e[0]*i;
            if(energy < 0)break;
            dis-=i;
            time = t[0]*i;
            if(dis == 0)cmin = min(cmin,time);
        for(int j=1; j<=q-i; j++){
            energy -= e[1]*j;
            if(energy < 0)break;
            dis-=j;
            time += t[1]*j;
            if(dis == 0)cmin = min(cmin,time);

            for(int k=1 ; k<=q-i-j; k++){
                energy -= e[2]*k;
                if(energy < 0)break;
                dis-=k;
                time += t[2]*k;
                if(dis == 0)cmin = min(cmin,time);

                for(int l=1; l<=q-k-j-i; l++){
                    energy -= e[3]*l;
                    if(energy < 0)break;
                    dis-=l;
                    time += t[3]*l;
                    if(dis == 0)cmin = min(cmin,time);

                    for(int m=1; m<=q-l-k-j-i ; m++){
                      energy -= e[4]*m;
                      if(energy < 0)break;
                      dis-=m;
                      time += t[4]*m;
                      if(dis == 0)cmin = min(cmin,time);
                    }
                }
            }
        }
       }
       cout<<cmin<<endl;
    }

    int main(){
    vector<int> e = {10,8,7,5,3};
    vector<int> t = {1,2,3,4,5};
    int distance = 7;
    int ene = 40;
    mintime(e,t,distance,ene);
    return 0;
    }
