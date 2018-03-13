//Maximun Subarray(LeetCode 53)
#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
//暴力枚举（时间复杂度O（n3），附加空间复杂度O（1））
class Solution1{
public:
        int maxSubArray(vector<int>& nums){
		int n=nums.size();
		int ans=-100000000;
		for(int i=0;i<n;++i){
			for(int j=i;j<n;++j){
				int sum=0;
				for(int k=i;k<=j;++k){
					sum+=nums[k];
					}
				if(sum>ans)
				{
					ans=sum;
				}
			}
		}
		return ans;
	}
};

//复杂度高时考虑冗余操作（被执行次数最多的操作），暴力枚举中sum+=sums[k]为冗余操作;每次都重新计算
//改进：优化枚举（两重循环）时间复杂度O（n2），附加空间复杂度O（1）
class Solution2{

public:
        int maxSubArray(vector<int>& nums){
		int n=nums.size();
		int ans=-100000000;
		for(int i=0;i<n;++i){
			int sum=0;
			for(int j=i;j<n;++j)
			{
					sum+=nums[j];
				if(sum>ans)
				{
					ans=sum;
				}
			}
		}
		return ans;
	}

};
//再次优化冗余:以负数开头的不必计算
class Solution3{
public:
	int maxSubArray(vector<int>& nums){
		int n=nums.size();
		int ans=-100000000;
		int sum=0;
		for(int i=0;i<n;++i){
			sum+=nums[i];
			if(sum>ans){
				ans=sum;
			}
			if(sum<0){
				sum=0;
            }
		}
    return ans;
	}
};

int main(){
    Solution1 a;
    Solution2 b;
    Solution3 c;
    int x,count=0;
    int total=0;
    cout<<"please input total numbers~"<<endl;
    cin>>total;
    cout<<"please input every number~"<<endl;
    vector<int> test;
    for(int i=0;i<total;i++)
    {
       cin>>x;
        test.push_back(x);
        count++;
    }
    cout<<"Solution1 answer is: "<<a.maxSubArray(test)<<endl;
    cout<<"Solution2 answer is: "<<b.maxSubArray(test)<<endl;
    cout<<"Solution3 answer is: "<<c.maxSubArray(test)<<endl;
}
