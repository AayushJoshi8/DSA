
//memoization (top down)
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,vector<int>dp,int i){
    if(i>=arr.size())return 0;

    if(dp[i]!=-1){
        return dp[i];
    }

    int pick=arr[i]+solve(arr,dp,i+2);
    int notPick=solve(arr,dp,i+1);

    return dp[i]=max(pick,notPick);
}

int main(){
vector<int>arr={2,1,4,9};
vector<int>dp(arr.size(),-1);
cout<<solve(arr,dp,0);
    return 0;
}



