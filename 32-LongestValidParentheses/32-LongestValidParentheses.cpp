class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else{
                if(st.empty())
                    st.push(i);
                else{
                    if(s[st.top()]=='('){
                        st.pop();
                        res=max(i-(st.empty() ? -1 : st.top()),res);
                    }
                    else
                        st.push(i);
                }
            }
        }
        return res;
    }
};