/*

smallest substring of all characters from pramp, not efficient sliding window

Run Instructions

$ g++ -std=c++0x smallest-substring.cpp -o smallSub
$ ./smallSub

*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>

using namespace std;

int main(){

    // string source = "xyyzyzyx";
    // vector<char> substring = {'x', 'y', 'z'};
    string source = "ADOBECODEBANC";
    vector<char> substring = {'A', 'B', 'C'};
    pair<int, int> ans;
    int min_length = INT_MAX;
    
    unordered_map<char, int> character_track;

    for(char character : substring){
        character_track[character]++;
    }

    int leftPointer = 0;
    int rightPointer = 0;

    while(rightPointer<source.length()){        
        // cout<<"RP="<<rightPointer<<endl;
        if(character_track.find(source[rightPointer])==character_track.end()){
            rightPointer++;
            continue;
        }
        // cout<<"First="<<rightPointer<<" lp="<<leftPointer<<endl;
        character_track[source[rightPointer]]--;
        // for(auto pointer = character_track.begin(); pointer!=character_track.end(); pointer++){
        //             cout<<pointer->first<<"=>"<<pointer->second<<endl;
        // }
        int uniqueElements = 0;
        for(auto it = character_track.begin(); it!=character_track.end(); it++){
            if(it->second<=0)
                uniqueElements++;
        }
        if(uniqueElements==substring.size()){
            // cout<<"here 1 rP="<<rightPointer<<" LP="<<leftPointer<<endl;
            min_length = min(min_length, rightPointer-leftPointer+1);        
            ans={leftPointer, rightPointer};
            if(character_track.find(source[leftPointer])!=character_track.end())
                character_track[source[leftPointer]]++;                
            else
                continue;

            
            //Try to compress window        
            // character_track[source[leftPointer]]++;
            leftPointer++;     
            while(leftPointer<rightPointer){
                // cout<<"inside=>"<<leftPointer<<" "<<rightPointer<<endl;            
                // for(auto pointer = character_track.begin(); pointer!=character_track.end(); pointer++){
                //     cout<<pointer->first<<", "<<pointer->second<<endl;
                // }
                // cout<<"ever here?"<<"LP="<<leftPointer<<" rp="<<rightPointer<<endl;
                if(character_track.find(source[leftPointer])==character_track.end()){
                    leftPointer++;
                    continue;
                }                
                int unique = 0;
                // cout<<"rP="<<rightPointer<<" LP="<<leftPointer<<endl;
                for(auto pointer = character_track.begin(); pointer!=character_track.end(); pointer++){
                    // cout<<pointer->first<<", "<<pointer->second<<endl;
                    if(pointer->second<=0)
                        unique++;
                }
                if(unique==substring.size()){
                    // cout<<"here="<<"LP="<<leftPointer<<" rp="<<rightPointer<<endl;
                    ans={leftPointer, rightPointer};
                    // cout<<"RP="<<rightPointer<<" LP="<<leftPointer<<" minlength="<<min_length<<endl;
                    min_length = min(min_length, rightPointer-leftPointer+1);                      
                    character_track[source[leftPointer]]++;
                    leftPointer++;
                    continue;
                }
                else{
                    // leftPointer++;
                    // cout<<"Else part=>"<<leftPointer<<" "<<rightPointer<<endl;
                    // rightPointer++;
                    break;
                    // continue;
                }                
            }
        }
        
        rightPointer++;

    }
    
    cout<<"Minimum Length="<<min_length<<"\n";
    cout<<"Ans="<<ans.first<<","<<ans.second<<endl;

    // cout<<"Minimum Length="<<min_length<<" left="<<leftPointer<<"right="<<rightPointer<<endl;

    return 0;
}
