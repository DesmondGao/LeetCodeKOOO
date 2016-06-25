//happy number是一个整数的每个digit平方加和最终为1，其中有一种情况是数字重复的话则永远不可能达到happy
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;//存储出现过的数字
        while(true)
        {
            if(1==n)
            {
                return true;
            }
            if(nums.find(n)==nums.end())//-->没找到，没找到则返回end()
            {
                nums.insert(n);
                int sum=0;
                while(n)
                {
                   int remainder=n%10;
                   sum+=remainder*remainder;
                   n/=10;
                }
                n=sum;
            }else
            {
                return false;
            }
        }
    }
};
