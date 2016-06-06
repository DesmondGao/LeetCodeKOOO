
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
//题干说明：You may assume that each input would have exactly one solution.即对于要加和到目标的两个数字有且只有一对

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
//，通过第二种方法发现，排序后寻找原始下标。其实质上是一种K-V结构，
//第三种方法是更换数据结构，用unordered_map,其比map容器有更快的访问效率

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
     // 在内部unordered_map的元素不以键值或映射的元素作任何特定的顺序排序，其存储位置取决于哈希值允许直接通过其键值为快速访问单个元素（具有恒定平均的平均时间复杂度）。
//unordered_map容器比map容器更快地通过键值访问他们的单个元素，虽然unordered_map一般都是比map通过其元素的一个子集范围迭代效率低。
      unordered_map<int,int> map;
      vector<int> ans;
      for(int i=0;i<nums.size();i++)
      {
          if(map.count(target-nums[i]))//map的count函数只能查找元素是否存在，即0/1，而find可以查到对应下标
          {
              ans.push_back(map[target-nums[i]]);
              ans.push_back(i);
              break;
          }else{
              map[nums[i]]=i;//一般来说要求啥就将其设置为键值对的值
          }
      }
        return ans;
    }
};//map思想起始类似桶排序，键值对思想，如果将 unordered_map<int,int> map修改为map<int,int>，那么leetCode效率会从64%->40%

//第四种方法是借助i,j从两端往里面走的思想，然后借助强大的unordered_map数据结构，暂时没有想来怎么写
