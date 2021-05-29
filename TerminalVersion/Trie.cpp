//Simple Trie Datastructure
/*

How to run - 

g++ -std=c++0x TrieDS.cpp -o trie
./trie

*/

#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Trie{
    public:   
        char value;
        //vector<Trie*> mapper(CHARACTERS, NULL);
		unordered_map<char, Trie*> mapper;
        bool isLeaf;
		
		Trie(char value, bool isLeaf){
			this->value = value;
			this->isLeaf = isLeaf;
		}

};

class TrieParent{
    
    public:
    //vector<Trie*> parentMapper(CHARACTERS, NULL);
	unordered_map<char, Trie*> parentMapper;
    

};

TrieParent* trieParent;

void insert(string word){
	
	int index = 0;    
	Trie* trieLink = trieParent->parentMapper[word[index]];
	

	if(trieLink==NULL){        
		trieParent->parentMapper[word[index]] = new Trie(word[index], word.length()==1?true:false);        
        trieLink = trieParent->parentMapper[word[index]];
    }
	else{        
    }
    
	for(int index=1; index<word.length(); index++){
		        
		if(trieLink->mapper.find(word[index])==trieLink->mapper.end()){            
            // cout<<word<<" "<<word[index]<<endl;
			trieLink->mapper[word[index]] = new Trie(word[index], false);
			trieLink = trieLink->mapper[word[index]];
			continue;
		}		
		trieLink = trieLink->mapper[word[index]];
	}
	
	trieLink->isLeaf = true;
	
}

bool lookUp(string lookup_word){

    
    int index = 0;
    Trie* trieLink = trieParent->parentMapper[lookup_word[index]];
    index++;

    if(trieLink==NULL)
        return false;

    for(; index<lookup_word.length(); index++){
        trieLink = trieLink->mapper[lookup_word[index]];
        
        if(trieLink==NULL)
            return false;
    }

    return trieLink->isLeaf;

}

int main(){

	
	trieParent = new TrieParent();

	  insert("test");
    insert("testing");
    insert("t");
    
	
    vector<string> word_check = {"test","testing", "check", "tes","te","t"};

    for(string word : word_check){
        if(lookUp(word))
            cout<<"Found "<<word<<"\n";
        else
            cout<<"Not found "<<word<<"\n"  ;
    }    

	return 0;
}
