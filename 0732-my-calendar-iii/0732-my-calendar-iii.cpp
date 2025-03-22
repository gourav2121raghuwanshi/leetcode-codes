class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        ++mp[startTime];
        --mp[endTime];
        int ans=INT_MIN;
        int s=0;
        for(auto&i:mp){
            s+=i.second;
            ans=max(ans,s);
            
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */