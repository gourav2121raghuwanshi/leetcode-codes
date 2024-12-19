class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>freq;
        unordered_map<int,int>end;

        for(int i=0;i<nums.size();++i){
            ++freq[nums[i]];
        }
        for(auto&i:nums){
            if(freq[i]==0) continue;
            --freq[i];
            if(end[i-1]>0){
                --end[i-1];
                end[i]++;
            }else if(freq[i+1]>0 && freq[i+2]>0){
                --freq[i+1];
                --freq[i+2];
                end[i+2]++;
            }else return false;
        }
        return true;
    }
};