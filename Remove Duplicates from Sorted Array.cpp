//既然不能占用额外空间，那就只能将后面(特别是same-series和后面的接触点(3)赋值)--》1 2 2 2 2 3 4
//timer就是一个标记same-series起点的第二个点的一个标记
//这个题本身就有点小问题，上面的case其返回值为1 2 3 4 2 ，竟然通过测试
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int timer=1;
       if(0==nums.size())
       return 0;
       for(int i=1;i<nums.size();i++)
       {
           if(nums[i]==nums[i-1])
           {
            continue;   
           }else
           {
               nums[timer]=nums[i];
               timer++;
           }
       }
     return timer;
    }
};
