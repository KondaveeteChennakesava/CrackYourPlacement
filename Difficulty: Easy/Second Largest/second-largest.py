#User function Template for python3
class Solution:

    def getSecondLargest(self,arr):
        # code here
        arr = set(arr)
        if len(arr)>=2:
            arr.remove(max(arr))
            return max(arr)
        else:
            return -1





#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.getSecondLargest(arr)
        print(ans)
        print("~")
# } Driver Code Ends