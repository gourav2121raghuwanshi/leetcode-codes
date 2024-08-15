class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int z=n;
        int y=m;
        int j=0;
        while(z--)
        {
            nums1[y++]=nums2[j++];
        }
        sort(nums1.begin(),nums1.end());
    }
};