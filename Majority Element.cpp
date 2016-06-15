class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //像这种找数组最多元素问题初始化一般让第一个作为major
        //典型的moor投票问题，超过半数以上才能算是主要元素
        //基本思想是:假设存在一个超过一半以上的候选者，那么其cancel off 其他人员后，如果得票数>=1,则一定是候选者
        int major=nums[0];//assume
        int timer=1;//至少一张选票，设置第一个为可能候选人-->计票器
        //寻找候选人
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==major)
            {
                timer++;
            }else{
                timer--;
            }if(0==timer)
            {
                major=nums[i];
                timer=1;
            }
        }
        //接下来需要判断上面找的的候选人是否选票过半
        int voter=0;//支持者
        for(int j=0;j<nums.size();j++)
        {
            if(major==nums[j])
            {
                voter++;
            }
        }
        if(voter>nums.size()/2)
        {
            return major;
        }else
        {
            return NULL;
        }
    }
};
