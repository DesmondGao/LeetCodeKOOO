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
