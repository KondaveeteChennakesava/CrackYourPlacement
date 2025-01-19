# Your task is to complete this function

'''

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''


class Solution:
    
    #Function to rotate a linked list.
    def reverse(self, head, x):
        if not head:return None
        curr = head
        prev = None
        while curr and x:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
            x -= 1
        return prev
    def rotate(self, head, k):
        if not head:return None
        if not head.next:return head
        l = 0
        curr = head
        while curr:
            l += 1
            curr = curr.next
        
        k %= l
        if not k:return head
        temp = k
        curr = head
        newHead = curr
        
        while temp and curr:
            curr = curr.next
            newHead =  curr
            temp -= 1
        
        tail = self.reverse(head, k)
        tala = self.reverse(newHead, l-k)
        curr = tail
        
        while curr.next:
            curr = curr.next
        curr.next = tala
        head = self.reverse(tail, l)
        return head
        



#{ 
 # Driver Code Starts
#Initial Template for Python 3


# Define the Node class for the linked list
class Node:

    def __init__(self, x):
        self.data = x
        self.next = None


# Function to print the linked list
def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


#Position this line where user code will be pasted.

# Main function
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    t = int(data[0].strip())
    idx = 1

    while t > 0:
        arr = list(map(int, data[idx].strip().split()))

        head = None
        if arr:
            head = Node(arr[0])
            tail = head
            for num in arr[1:]:
                tail.next = Node(num)
                tail = tail.next

        k = int(data[idx + 1].strip())
        idx += 2
        head = Solution().rotate(head, k)
        printList(head)
        print("~")
        t -= 1

# } Driver Code Ends