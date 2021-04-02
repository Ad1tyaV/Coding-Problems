'''
https://leetcode.com/problems/find-the-town-judge/
'''
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        mp={}
        if len(trust)==0 and N==1:
            return 1
        elif len(trust)==0 and N>1:
            return -1
        if len(trust)==1:
            return trust[0][1]
        
        for i in range(0,len(trust)):
            if trust[i][0] in mp:
                mp[trust[i][0]]["outdegree"]=mp[trust[i][0]]["outdegree"]+1                
            else:
                mp[trust[i][0]] = {"indegree":0,"outdegree":1}
                
            if trust[i][1] in mp:
                mp[trust[i][1]]["indegree"]=mp[trust[i][1]]["indegree"]+1
            else:
                mp[trust[i][1]] = {"indegree":1,"outdegree":0}
        
        for element in mp.keys():
            if mp[element]['outdegree'] == 0:
                if mp[element]['indegree'] == N-1:
                    return element
            
        return -1        
