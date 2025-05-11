from typing import List
import heapq

class Solution:
    def kthLargest(self, arr, k) -> int:
        n = len(arr)
        min_heap = []  # will contain at most k largest sums, min-heap

        # Enumerate all subarrays by start i and end j
        for i in range(n):
            curr = 0
            for j in range(i, n):
                curr += arr[j]
                if len(min_heap) < k:
                    # still room, just push
                    heapq.heappush(min_heap, curr)
                else:
                    # if this sum is larger than the smallest in the heap, replace it
                    if curr > min_heap[0]:
                        heapq.heapreplace(min_heap, curr)

        # the root of the min-heap is the k-th largest sum
        return min_heap[0]


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import heapq

# Position this line where user code will be pasted.

#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        k = int(input())
        ob = Solution()
        res = ob.kthLargest(arr, k)
        print(res)
        print("~")
        t -= 1

# } Driver Code Ends