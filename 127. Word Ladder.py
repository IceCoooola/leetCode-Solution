import queue
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        q = queue.Queue()
        q.put(beginWord)
        depth = 0
        n = len(beginWord)
        visited = []

        while not q.empty():
            depth += 1
            for _ in range(q.qsize()):
                curWord = q.get()
                if curWord == endWord:
                    return depth
                for i in range(n):
                    for x in ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']:
                        word = curWord[:i] + x + curWord[i+1:]
                        if word in wordList and word not in visited:
                            q.put(word)
                            visited.append(word)
        return 0      
            
        
