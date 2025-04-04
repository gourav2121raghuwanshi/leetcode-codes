class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> freq;
        for (auto& i : hand) {
            ++freq[i];
        }
        for (auto& i : freq) {
            int curr = i.first;
            int want = i.second;
            if(want==0) continue;
            // cout<<curr<<" range "<<curr + groupSize-1<<endl;
            for (int j = curr + 1; j < curr + groupSize; ++j) {
                if (!freq.count(j) || freq[j] < want)
                    return false;
                freq[j] -= want;
            }
        }
        return true;
    }
};