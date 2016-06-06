
//原始的直接暴力查找法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> holder(0);
        for(int i=0;i<nums.size();i++)
        {
         for(int j=i+1;j<nums.size();j++)
          {
              if(nums[i]+nums[j]==target)
              {
              holder.push_back(i);
              holder.push_back(j);
              }
          }
        }
    return holder;
    }
};

//当然可以先排序，建议快排，然后再暴力查找原始数组里面和排序后数组一样的数值下标

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> temp_nums=nums;
        vector<int> ans;
        sort(temp_nums.begin(),temp_nums.end());
        int i=0; int j=temp_nums.size()-1;
        while(i<j)
        {
            if(temp_nums[i]+temp_nums[j]==target)
            {
                //需要明确-->排序后的数字是以前数组的相同数组的那个下标
                for(int k=0;k<nums.size();k++)
                {
                    if(temp_nums[i]==nums[k]||temp_nums[j]==nums[k])
                    {
                        ans.push_back(k);
                    }
                }
                break;//break位置放不对会超时
            }else if(temp_nums[i]+temp_nums[j]<target){
               i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};
