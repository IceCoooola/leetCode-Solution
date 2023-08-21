class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s.strip()
        arr = s.split()
        return len(arr[len(arr)-1])
