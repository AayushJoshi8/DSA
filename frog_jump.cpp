
//memoization (top-down)
#include<bits/stdc++.h>
using namespace std;

class aayush{
public:

int frog(int idx,vector<int> &nums, vector<int>& dp){
    if(idx==0)return 0;

    if(dp[idx]!=-1){
        return dp[idx];
    }

    int left=frog(idx-1,nums,dp) + abs(nums[idx] - nums[idx-1]);
    int right=INT_MAX;
    if(idx>1){
        right=frog(idx-2,nums,dp) + abs(nums[idx] - nums[idx-2]);
    }

    return dp[idx]= min(left,right);
}
};


int main(){
vector<int>nums{10,20,30,10};
int n=nums.size();
vector<int>dp(n+1,-1);

aayush a;
cout<<a.frog(n-1,nums,dp);
    return 0;
}