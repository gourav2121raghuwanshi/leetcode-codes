class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;

        for(int i=0;i<boxes.size();++i){
            int dist=0;
            for(int j=0;j<i;j++){
                if(boxes[j]=='1'){
                    dist+=(i-j);
                }
            }
            for(int j=i+1;j<boxes.size();++j){
                if(boxes[j]=='1'){
                    dist+=(j-i);
                }
            }
            ans.push_back(dist);
        }
        return ans;
    }
};