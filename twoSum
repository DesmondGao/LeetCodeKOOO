
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
