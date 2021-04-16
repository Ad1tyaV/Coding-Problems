class Solution:
    
    #Linear Search
    
#     def findNearestGreaterElement(self, days, target):
#         for index, value in enumerate(days):
#             if value > target:
#                 return index
#         #print("Never here!")    
#         return -1    
            
    #BinSearch
    
    def binSearch(self, days, target):
        l = 0
        r = len(days) - 1
        current = math.inf
        currentIndex = -1
        
        while l<=r:
            mid = (l+r) // 2
            
            if days[mid] == target:
                l = mid+1
            elif days[mid] > target:
                r = mid - 1
                if current == math.inf:
                    current = days[mid]
                    currentIndex = mid
                elif days[mid] < current:
                    current = days[mid]
                    currentIndex = mid
            else:
                l = mid+1
            
        return currentIndex   
        
    
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        
        dp = [math.inf for _ in range(0, len(days)+1)]
        
        
        dp[0] = min(costs)
        #print(dp)[1,inf,inf,inf]
        for index, day in enumerate(days):
            if index==0:
                continue
            #print("Index={}".format(index))
            a = costs[0] + dp[index-1]
            #print("a={}".format(a))
            b = None
            if day - 7 <=0:
                #b = costs[1]
                dp[index] = min(costs[1], a)
                #print(dp[index])
            else:
                #_index = self.findNearestGreaterElement(days, day - 7)
                _index = self.binSearch(days, day - 7)
                #print("Index from 7 is:{}".format(_index))
                
                if _index>0:
                    dp[index] = min(dp[_index-1] + costs[1], a)
                else:
                    dp[index] = min(costs[1], a)
            
            if day - 30 < 0:
                dp[index] = min(dp[index], costs[2])
            else:
                #_index = self.findNearestGreaterElement(days, day - 30)
                _index = self.binSearch(days, day - 30)
                #print("Index from 30 is :{}".format(_index))
                
                if _index < 0:
                    dp[index] = min(dp[index], costs[2])
                else:
                    dp[index] = min(dp[_index-1] + costs[2], dp[index])
        #print(dp)        
        return dp[len(days)-1]
