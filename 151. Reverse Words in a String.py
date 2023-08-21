class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s.strip()
        arr = s.split()
        string = ""
        reversedARR = arr[::-1]
        for s in reversedARR:
            string += s + " "
        return string.strip()
