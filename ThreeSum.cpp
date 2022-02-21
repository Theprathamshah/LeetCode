/**
 * @file ThreeSum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
 */

#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> threeSumSolution(vector<int>a)
{
    int n = a.size();
    if(n<=2)
    {
        return {};
    }
    if(a[0]>0  or a[n-1]<0)
    {
        return {};
    }
    vector<vector<int>>ans;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>0)
        {
            break;
        }
        if(i>0 and a[i]==a[i-1])
        {
            continue;
        }
        int low = i+1;
        int hi = n-1;
        while (low<hi)
        {
            int sum = a[low] + a[hi] + a[i];
            if(sum==0)
            {
                ans.push_back({a[i],a[low],a[hi]});
                while (a[low]==a[low+1] and low<hi)
                {
                    /* code */low++;
                }
                while(low<hi and a[hi]==a[hi-1])
                {
                    hi--;
                }
                
                low++;
                hi--;
            }
            else if(sum>0)
            {
                hi--;
            }
            else{
                low++;
            }
        }
        
    }
    return ans;
    
}


int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &i:a)
    {
        cin>>i;
    }
    sort(a.begin(),a.end());
    vector<vector<int>>ans = threeSumSolution(a);
    for(auto ele:ans)
    {
        cout<<"[";
        for(auto i:ele)
        {
            cout<<i<<",";
        }
        cout<<"]"<<endl;
    }
    
    return 0;
}
/**
 * @brief 
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
 */