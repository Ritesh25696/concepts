#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int maxCoinsBottomUpDp(vector<int>& nums) {

        int T[nums.size()][nums.size()];
         for(int i=0 ; i<nums.size() ; i++){
            for(int j=0 ; j<nums.size() ; j++){
                T[i][j] = 0;
            }
        }
            for (int len = 1; len <= nums.size(); len++) {
            for (int i = 0; i <= nums.size()- len; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    int leftValue = 1;
                    int rightValue = 1;
                    bool left = false , right = false;
                    if (i != 0) {
                        leftValue = nums[i-1];
                        left = true;
                    }
                    if (j != nums.size() -1) {
                        rightValue = nums[j+1];
                        right = true;
                    }

                    int before = 0;
                    int after = 0;
                    if (i != k) {
                        before = T[i][k-1];
                    }
                    if (j != k) {
                        after = T[k+1][j];
                    }
                    if(!left && !right)
                    T[i][j] = max(nums[k] + before + after,T[i][j]);
                    else
                    T[i][j] = max(leftValue * rightValue + before + after,T[i][j]);
                }
            }
        }
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=0 ; j<nums.size() ; j++){
                cout<<T[i][j]<<" ";
            }
            cout<<endl;
        }
        return T[0][nums.size() - 1];
    }

    int main(){
    vector<int> nums = {3,1,5,8};
    cout<<maxCoinsBottomUpDp(nums);
    return 0;
    }
