//这类要求不占用额外空间的数组性问题大部分就是通过两个指针用后面的值覆盖前面的值
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int shift=0;
       
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]==val)
           {
               shift++;
           }else if(shift>0)
           {
               nums[i-shift]=nums[i];
           }
      
        }
        return nums.size()-shift;
    }
};
