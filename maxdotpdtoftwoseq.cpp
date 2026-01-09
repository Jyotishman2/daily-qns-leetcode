#include<bits/stdc++.h>
using namespace std;
class solution {
    int n , m;
    int t[501][501];
    private:
    int solve(vector<int>&nums1,vector<int>&nums2, int  i ,int j){
        if(i == n || j==n)return -1e9;
        if(t[i][j]!=-1e9)return t[i][j];
        int val = (nums1[i]*nums2[j]);
        int takeij = (nums1[i]*nums2[j]) + solve(nums1,nums2,i+1,j+1);
        int  takei = solve(nums1,nums2,i+1,j);
        int takej = solve(nums1,nums2,i,j+1);
        return t[i][j]=max(val,max(takeij,max(takei,takej)));
    }
    public:
    int maxdotpdt(vector<int>& nums1,vector<int>& nums2){
        n =nums1.size();
        m = nums2.size();
        for(int i =0 ;i<501;i++){
            for(int j =0 ;j<501;j++){
                t[i][j]=-1e9;
            }
        }
        return solve(nums1,nums2,0,0);
    }
};