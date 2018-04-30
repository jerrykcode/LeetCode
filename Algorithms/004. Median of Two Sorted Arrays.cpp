class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mlist = merge(nums1, nums2);
        return getMedian(mlist);
    }
    
private:
    // Merge 2 sorted arrays
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mlist;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) 
                mlist.push_back(nums1[i++]);
            else 
                mlist.push_back(nums2[j++]);
        }
        while (i < nums1.size())
            mlist.push_back(nums1[i++]);
        while (j < nums2.size())
            mlist.push_back(nums2[j++]);
        return mlist;
    }
    
    double getMedian(vector<int>& nums) {
        int size = nums.size();
        return size%2 ? nums[size/2] : (nums[size/2] + nums[size/2 - 1])/2.0;
    }
};
