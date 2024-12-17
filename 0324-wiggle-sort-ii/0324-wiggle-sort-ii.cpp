class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int count[5001];
        int maxi = 0;
        for (auto& i : nums) {
            maxi = max(i, maxi);
            ++count[i];
        }
        int j=maxi;
        int i=1;
        int n=nums.size();
        while(i<n){
            while(count[j]==0) --j;
            nums[i++]=j;
            --count[j];
        }

         i=0;
        while(i<n){
            while(count[j]==0) --j;
            nums[i++]=j;
            --count[j];
        }

    }
};