class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>freq(26,0);
        for(auto&i:s){
            ++freq[i-'a'];
        }
        vector<int>ans;
        int c=0;
        unordered_set<char>st;
        for(int i=0;i<s.size();++i){
            --freq[s[i]-'a'];
            if(freq[s[i]-'a']==0){
                bool f=false;
                for(auto&j:st){
                    if(freq[j-'a']!=0){
                        f=true;
                        break;
                    }
                }
                if(!f){
                    ans.push_back(i-c+1);
                    c=i+1;
                    st.clear();
                }
            }else{
                st.insert(s[i]);
            }
        }
        return ans;
    }
};