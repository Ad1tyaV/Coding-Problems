// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<int> st;
        string ans = "";
        
        if(num.length()<=k)
            return "0";
            
        
        for(int i=0;i<num.length();i++){
            
            if(!i){
                st.push(num[i]-'0');                
            }
            else{                
                int incoming  = num[i]-'0';
                
                if(!st.size()){  
                    if(incoming)
                        st.push(incoming);    
                }  
                else{                    
                    
                    while(st.size() && k>0 && st.top()>incoming){                        
                        st.pop();
                        k--;                        
                    }
                    
                    if(!st.size()){
                        if(incoming)
                            st.push(incoming);
                    }
                    else
                        st.push(incoming);
                        
                    
                }                                
            }            
        }
        
        if(!st.size())
            return "0";
        
        if(k>st.size())
            return "0";
        
        while(k){
            st.pop();
            k--;
        }
                
        while(st.size()){               
            ans+=(st.top()+'0');
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
