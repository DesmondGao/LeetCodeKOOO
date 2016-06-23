//这道中等题很简单，先排序，找到有可能的重复性数字，然后以此重复性数字为原材料在原始数组里面找到距离小于等于k的两个数值并返回
//唯一需要注意的是在原始数组里面的找到的目标值起点是m=j+1，而不是其本身
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==1)
        {
            return false;
        }
        vector<int> tmp=nums;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                for(int j=0;j<tmp.size();j++)
                {
                    if(nums[i]==tmp[j])
                    {
                        for(int m=j+1;m<tmp.size();m++)
                        {
                            if((tmp[j]==tmp[m])&&((m-j)<=k))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
