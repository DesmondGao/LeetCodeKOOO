//收集非零数放在一个数组，然后将这些数又全部扔进原始数组。就这样
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZero;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nonZero.push_back(nums[i]);
                count++;//多少非零数
                nums[i]=0;
            }
        }
        
        for(int j=0;j<count;j++)
        {
            nums[j]=nonZero[j];
        }
    }
};
