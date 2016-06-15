//method 1：基本方法->超时
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp=0;
        for(int step=0;step<k;step++)
        {
            temp=nums[nums.size()-1];
            for(int i=nums.size()-1;i>0;i--)
            {
                nums[i]=nums[i-1];
            }
            nums[0]=temp;
        }
    }
};
