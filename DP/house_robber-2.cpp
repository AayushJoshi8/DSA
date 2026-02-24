//-----------simple recursive code--------------

#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

int solve(vector<int>nums,int i,int end){
    if(i>end)return 0;

    int pick=nums[i] + solve(nums,i+2,end);
    int notPick=solve(nums,i+1,end);

    return max(pick,notPick);

}

    int rob(vector<int>nums){
        int n=nums.size();

        if(n==1)return nums[0];

        return max(solve(nums,0,n-2) , solve(nums,1,n-1));
    }
};
int main(){
    vector<int>nums{1,5,1,2,6};
solution sol;
sol.rob(nums);
    return 0;
}
