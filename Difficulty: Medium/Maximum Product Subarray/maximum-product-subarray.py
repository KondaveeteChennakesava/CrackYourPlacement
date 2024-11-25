#User function Template for python3
class Solution:

	# Function to find maximum
	# product subarray
	def maxProduct(self,arr):
		# code here
		n = len(arr)
		curr = 1
		ans = float('-inf')
		for i in range(n):
		    if curr == 0: curr = 1
		    
		    curr *= arr[i]
		    ans = max(ans, curr)
        
        curr = 1
        for i in range(n-1, -1, -1):
            if curr == 0: curr = 1
            
            curr *= arr[i]
            ans = max(ans, curr)
            
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProduct(arr)
        print(ans)
        tc -= 1

# } Driver Code Ends