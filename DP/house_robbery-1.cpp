
//brute (simple recursion)
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr , int i){
     if(i >= arr.size())return 0;
    int pick=arr[i]+solve(arr,i+2);
    int notPick=solve(arr,i+1);

    return max(pick,notPick);
}

int main(){
vector<int>arr={2,1,4,9};

int ans=solve(arr,0);
cout<<ans;
    return 0;
}



