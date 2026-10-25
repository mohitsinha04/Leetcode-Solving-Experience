class AuthenticationManager {
public:
    int t;
    unordered_map<string,int> mp;
    AuthenticationManager(int timeToLive) {
        t=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId]=currentTime+t;
    }
    
    void renew(string tokenId, int currentTime) {
        auto p=mp.find(tokenId);
        if(p!=mp.end() && p->second > currentTime)
            p->second=currentTime+t;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int c=0;
        for(auto p:mp){
            if(p.second>currentTime) c++;
        }
        return c;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */