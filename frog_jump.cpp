
//-----------------------------memoization (top-down)-----------------------
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


// -------------------------space optimization----------------------

#include<bits/stdc++.h>
using namespace std;

class aayush{
public:

int frog(int idx,vector<int> &nums,int n){
    if(idx==0)return 0;

    int prev=0;
    int prev2=0;

    for(int i=1;i<n;i++){
        int fs=prev+ abs(nums[idx] - nums[idx-1]);
        int ss=INT_MAX;
        if(idx>1){
        ss=prev2 + abs(nums[idx] - nums[idx-2]);
        }
    int curri=min(fs,ss);
    prev2=prev;
    prev=curri;
    }

    return prev;
    
        
    
}
};


int main(){
vector<int>nums{10,20,30,10};
int n=nums.size();

aayush a;
cout<<a.frog(n-1,nums,n);
    return 0;
}
