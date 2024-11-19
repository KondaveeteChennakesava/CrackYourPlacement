#User function Template for python3

class Solution:
    def nextPermutation(self, arr):
        # code here
        n = len(arr)
        perPos = n - 2
        while perPos >= 0:
            if arr[perPos] < arr[perPos + 1]:
                break
            perPos -= 1
            
        if perPos >= 0:
            nextMax = float('+inf')
            nextPos = -1
            
            for i in range(perPos + 1, n):
                if arr[i] > arr[perPos] and arr[i] < nextMax:
                    nextMax = arr[i]
                    nextPos = i
            
            arr[perPos], arr[nextPos] = arr[nextPos], arr[perPos]
            
            arr[perPos+1:n] = reversed(arr[perPos+1:n])
        else:
            arr[0:n] = reversed(arr[0:n])

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = input().split()
        N = len(arr)
        for i in range(N):
            arr[i] = int(arr[i])

        ob = Solution()
        ob.nextPermutation(arr)
        for i in range(N):
            print(arr[i], end=" ")
        print()

# } Driver Code Ends