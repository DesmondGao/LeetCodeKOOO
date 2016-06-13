
//method 1:
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int nums1_index=m-1;
     int nums2_index=n-1;
     int merge_index=m+n-1;
     while(nums1_index>=0&&nums2_index>=0)
     {
         //将大的放到merge数组里面
         if(nums1[nums1_index]>nums2[nums2_index])
         {
             nums1[merge_index--]=nums1[nums1_index--];
         }else
         {
             nums1[merge_index--]=nums2[nums2_index--];
         }
     }
     //由于是将nums2数组放到nums1数组，所以最终可能会有nums2数组里面有一部分元素剩余，
     //由于前面的工作主要是将大的元素放在nums1数组中，所以剩下的必定是小于已排列好的元素，需要将剩下的继续放进去
     //如果是放到nums2中，则刚好相反，要检测nums1中元素剩余情况
     while(nums2_index>=0)
     {
         nums1[merge_index--]=nums2[nums2_index--];
     }
     return;
    }
};

//method 2:--->可读性比method 1好
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   //采用更好的理解方式-->read and write下标--->读写操作
   for(int nums1r=m-1,nums2r=n-1,wi=m+n-1;nums2r>=0;--wi)
   {
    //采用for循环可以将nums2的所有元素扫进目标数组，而不需要进行剩余判断
    //谁大把谁放进去
    if(nums1r>=0&&nums1[nums1r]>nums2[nums2r])
    {
        nums1[wi]=nums1[nums1r--];
    }else//即使nums1没有元素，也是可以运算的
    {
        nums1[wi]=nums2[nums2r--];
    }
   }
    return;
    }
};
