class Solution {
public:
    string leftshift(string s,int left)   
    {
        string ans = s.substr(left) + "" + s.substr(0 , left) ;  
        return ans ; 
    }
    string stringShift(string s, vector<vector<int>>& shift) {
        int left  = 0 , right = 0 ; 
        int n = s.length() ;   
        for(auto v : shift) 
        {
            if(v[0] == 0)  left += v[1] ; 
            else right += v[1] ;  
        } 
        string ans = "" ;  
        if(left == right || ((abs(left-right)%n) == 0))  return s ;  
        else if(left > right) 
        {
            left -= right ;  
            left = left % n ;  
            ans = leftshift(s,left) ;       
        } 
        else  
        {
            right -= left ;
            right = right % n ;    
            ans =  leftshift(s,n-right) ;       
        } 
        return ans ;  
    }
};