/*
https://practice.geeksforgeeks.org/problems/k-pangrams0909/1
*/
bool kPangram(string str, int k){
    
    unordered_set<char> character_set;
    vector<char> characters;
    
    for(int index = 0; index<str.size(); index++){
        if(str[index]==' ')
            continue;
        characters.push_back(str[index]);
        character_set.insert(str[index]);
    }
    
    int first = characters.size();
    int second = character_set.size();
    
    
    
    if(second==26)
        return true;
    
    if(first<26)
        return false;
    
    
    
    int duplicates = first - second;
    
    int to_swap = 26 - second; 
    
    // cout<<"All chars="<<first<<" unique_chars="<<second<<"\n";
    
    // How many characters can i use to swap ? - > duplicates
    // How many do I need ? 26-unique => to_swap
    
    // cout<<"to_swap = "<<to_swap<<" duplicates="<<duplicates<<endl;
    
    if(to_swap >duplicates)
        return false;
    
    
    if(to_swap > k ){
        return false;
    }
    
    
    return true;
    
}
