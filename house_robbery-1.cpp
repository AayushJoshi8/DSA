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

//----------------space optimization TC:O(n),SC:O(1)------------------
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr){
   int n=arr.size();

    if(n == 0) return 0;
    if(n == 1) return arr[0];

   int prev=arr[0];
   int prev2=0;

   for(int i=1;i<n;i++){
    int pick=arr[i]+prev2;
    int notPick=0+prev;

    int curr=max(pick,notPick);
    prev2=prev;
    prev=curr;
   }
   return prev;
}

int main(){
vector<int>arr={1,2,4};
cout<<solve(arr);
    return 0;
}
