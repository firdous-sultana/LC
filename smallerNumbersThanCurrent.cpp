/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
*/


#include<bits/stdc++.h>
using namespace std;
// vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
void smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> v;
    v = nums;
    sort(v.begin(), v.end());
    unordered_map<int, int> mp;
    mp[v[0]] = 0;
    for(int i=1; i<nums.size(); i++){
        if(v[i] != v[i-1])
            mp.insert({v[i], i});
        else
            mp.insert({v[i], mp[v[i-1]]});
    }
    for(int i=0; i<nums.size(); i++){
        nums[i] = mp[nums[i]];
    }
    // return nums;
    for(int i=0; i<nums.size(); i++)
        cout<<nums[i]<<" ";
}
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> v1;
        int x;
        for(int i=0; i<n; i++){
            cin>>x;
            v1.push_back(x);
        }
        // for(int i=0; i<n; i++)
        //     cout<<v1[i]<<" ";
        // cout<<"\n";
        smallerNumbersThanCurrent(v1);
        cout<<"\n";
    }
    return 0;
}