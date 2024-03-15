class Solution:
    def lengthOfLIS(self, A: List[int]) -> int:
        ret = 1
        n = len(A)
        M = [float(math.inf)] * (n+1)
        A = [0] + A
        M[1] = A[1]
        for i in range(2, n + 1):
            if A[i] > M[i-1]:
                M[i] = A[i]
            else:
                left, right = 1, i-1
                while left <= right:
                    mid = (left + right) // 2
                    if M[mid] < A[i]:
                        left = mid + 1
                    elif M[mid] > A[i]:
                        right = mid - 1
                    else:
                        left = mid
                        break
                M[left] = A[i]        
        print(M)
        print(A)
        for i in range(n, 0, -1):
            if M[i] != float(math.inf):
                return i
        return 1
