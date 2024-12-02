class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int c=0;
        stringstream ss(sentence);
        string str;
        while(getline(ss,str,' ')){
            ++c;
            if(str.size()<searchWord.size()) continue;
            if(searchWord==str.substr(0,searchWord.size())) return c;
        }
        return -1;
    }
};