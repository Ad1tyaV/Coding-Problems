class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [sys.maxsize for x in range(0, amount+2)]
        dp[0] = 0
        
        for i in range(1, amount+1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i - coin]+1, dp[i])
        
        
        return -1 if dp[amount] == sys.maxsize else dp[amount]
