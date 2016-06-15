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

//method 2:周期性方法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //周期性问题-->%运算符派上了用处
        if(1==nums.size())
        {
            return;
        }
        if(k>nums.size())
        {
            k=k%nums.size();//周期为数组长度
        }
       // vector<int> temp_vector(k);
        vector<int> result;//不应该设置result长度
        for(int i=nums.size()-k;i<nums.size();i++)
        {
            result.push_back(nums[i]);
            //reverse(temp_vector.begin(),temp_vector.end());
        }
        for(int j=0;j<nums.size()-k;j++)
        {
           result.push_back(nums[j]);
        }
      nums=result;  
    }
};
