#include<iostream>
#include<vector>

using namespace std;

vector<int> buildPrefixTable(string matchPattern){
    int updateIndex = 1;
    int pivot = 0;

    vector<int> prefix_table(matchPattern.size(), -1);

    while(updateIndex<matchPattern.size()){

        if(matchPattern[updateIndex]==matchPattern[pivot]){
            prefix_table[updateIndex] = pivot;
            updateIndex++;
            pivot++;
        }
        else{

            if(pivot>0){
                pivot = prefix_table[pivot-1]+1;
            }
            else{
                updateIndex++;
            }


        }
    }
    return prefix_table;
}

void print(vector<int> prefix_table){

    cout<<"Prefix Table:"<<endl;
    for(int prefix:prefix_table)
        cout<<prefix<<"\t";
    
    cout<<endl;

}

bool isSubpattern(string pattern, string subpattern, vector<int> prefix){

    int mainPointer = 0;
    int subPointer = 0;

    while(mainPointer<pattern.size()){

        int pointer = mainPointer;
        int subPointer = subPointer;
        bool matched = true;

        while(pointer<pattern.size() && subPointer<subpattern.size()){

            if(pattern[pointer]==subpattern[subPointer]){
                pointer++;
                subPointer++;
            }
            else{

                if(subPointer>0){
                    subPointer = prefix[subPointer-1] + 1;
                }
                else{
                    pointer++;
                    matched = false;                    
                }

            }
        }

        if(matched)
            return matched;

        mainPointer++;
    }

    return false;
}

int main(){

    vector<string> mainStrings = {"aefoaefcdaefcdaed", "testwafwafawfawfawfawfawfawfawfa", "aaabaabacdedfaabaabaaa", "decadaafcdf"};
    vector<string> matchPatterns = {"aefaedaefaefa", "fawfawfawfawfa", "aabaabaaa", "daf"};
    
    vector<int> prefix_table;    

    for(int i=0; i<mainStrings.size(); i++){

        string matchPattern = matchPatterns[i];
        string mainString = mainStrings[i];

        prefix_table = buildPrefixTable(matchPattern);
                

        if(isSubpattern(mainString, matchPattern, prefix_table))
            cout<<"Yes "<<mainString<<" and "<<matchPattern<<" are matched"<<endl;
        else
            cout<<"No, "<<mainString<<" and "<<matchPattern<<" are not matched"<<endl;
    
    }

    return 0;
}
