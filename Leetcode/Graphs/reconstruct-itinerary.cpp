/*

https://leetcode.com/problems/reconstruct-itinerary/

*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
                
        // map<string, set<string>> sourceToDestination;
        map<string, multiset<string>> sourceToDestination;
        
        for(vector<string> path:tickets){            
            // sourceToDestination[path[0]].push(path[1]);                        
            sourceToDestination[path[0]].insert(path[1]);                        
        }
        
        stack<string> itineraryStack;        
        vector<string> answer;
        
        itineraryStack.push("JFK");        
        
        while(!itineraryStack.empty()){
            
            string source = itineraryStack.top();
                        
            //Check Neighbours
            if(sourceToDestination[source].size()==0){
                answer.push_back(source);
                itineraryStack.pop();
            }
            else{
                
                auto it = sourceToDestination[source].begin();                
                itineraryStack.push(*it);
                sourceToDestination[source].erase(it);
                
            }
                                    
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
