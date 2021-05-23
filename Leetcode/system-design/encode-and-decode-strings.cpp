/*
https://leetcode.com/problems/encode-and-decode-strings/
*/

class Codec {
public:
    
    int count;    
    map<string, vector<string>> store;
    
    Codec(){
        count = 1;
    }        
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        vector<string> check;
        for(string temp:strs){
            check.push_back(temp);
        }
        
        int _count = count;
        
        store[to_string(_count)] = check;
        count++;
        
        return to_string(_count);
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        return store[s];
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
