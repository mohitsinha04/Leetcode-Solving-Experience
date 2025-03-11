class Solution {
public:
    bool helper(int i,int j, string &s,string &p,vector<vector<int>> &dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return dp[i][j]=1;
        if(j==0 && i>0) return dp[i][j]=0;
        if(i==0 && j>0)
        {
            while(j>0)
            {
                if(p[j-1]=='*') j--;
                else return dp[i][j]=0;
            }
            return dp[i][j]=1;
        }
        
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j] = helper(i-1,j-1,s,p,dp);
        
        if(p[j-1]=='*')
        {
            return dp[i][j] = helper(i-1,j,s,p,dp) || helper(i,j-1,s,p,dp) ? 1:0;
            //Two cases
            //Consider * as len=0
            //Give one charcter to * and remain at *
            //at next step it will again be decided from both these cases
        }
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        // int n = s.size();
        // int m = p.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        // return helper(n,m,s,p,dp);

        int n=s.length(),m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[0][0]=true;
        for(int i=1;i<=n;i++) dp[i][0]=false;
        
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')
                flag=false;
            dp[0][i]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];

    }
    bool isAllStars(string &S1, int i) {
        // S1 is taken in 1-based indexing
        for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }
};