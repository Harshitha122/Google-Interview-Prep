//Approach-1 (Using stack)
/*
	 Just remove balanced parts from string because they won't help us.
	 Put unbalanced halfs in stack.
	 In the end you will be left with unmatched halfs only.
	 Once done , you'll have following pattern:
	    Pattern                          Result                      stack in the end         stack size
		 "]["                             1                                "["                  1
		"]][["                            1                                "[["                 2
		"]]][[["                          2                                "[[["                3
		"]]]][[[["                        2                                "[[[["               4
		"]]]]][[[[["                      3                                "[[[[["              5
		 
		 If you notice, result = (stack.size()+1)/2;
*/
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(char &ch : s) {
            if(ch == '[')        st.push(ch);
            else if(!st.empty()) st.pop();
        }       
        return (st.size()+1)/2;
    }
};