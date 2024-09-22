class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=s[0]=='0'?0:1;
        for(size_t i=2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]=dp[i-1];
            }
            int digit=stoi(s.substr(i-2,2));
            if(digit>=10 && digit<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};

/*class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        size_t n = s.length();
        int two_back = 1;
        int one_back = 1;

        for (size_t i = 1; i < n; i++) {
            int current = 0;
            if (s[i] != '0') {
                current = one_back;
            }
            int two_digit = stoi(s.substr(i - 1, 2));
            if (two_digit >= 10 and two_digit <= 26) {
                current += two_back;
            }

            two_back = one_back;
            one_back = current;
        }
        return one_back;
    }
}; */