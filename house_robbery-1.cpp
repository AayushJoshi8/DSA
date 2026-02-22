//simple recursion
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int i){
    if(i==0)return arr[i];
    if(i<0)return 0;

    int pick=arr[i]+solve(arr,i-2);
    int notPick=0+solve(arr,i-1);

    return max(pick,notPick);
}

int main(){
vector<int>arr={1,2,4};
cout<<solve(arr,0);
    return 0;
}

//--------------memoization top-down-----------------
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int i,vector<int>dp){
    if(i==0)return arr[i];
    if(i<0)return 0;

    if(dp[i]!=-1)return dp[i];
    int pick=arr[i]+solve(arr,i-2,dp);
    int notPick=0+solve(arr,i-1,dp);

    return dp[i]=max(pick,notPick);
}

int main(){
vector<int>arr={1,2,4};
vector<int>dp(arr.size(),-1);
cout<<solve(arr,0,dp);
    return 0;
}
