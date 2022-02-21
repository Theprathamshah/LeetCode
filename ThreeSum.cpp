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
