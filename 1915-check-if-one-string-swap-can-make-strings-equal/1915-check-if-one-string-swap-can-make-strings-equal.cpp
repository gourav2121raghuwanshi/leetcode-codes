class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int cnt = 0;
        int n = s1.size();
        char a='*',b='*';
        char c='*',d='*';
        bool f=1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i] && f){
                a=s1[i];
                b=s2[i];
                f=0;
                ++cnt;
            }
            else if(s1[i] != s2[i]){
                c=s1[i];
                d=s2[i];
                ++cnt;
            }

             if(cnt>2) return false;
        }
cout<<a<<b<<c<<d;
        return a==d && b==c;
    }
};