class Solution:
    def simplifyPath(self, path: str) -> str:
        arr = path.split('/')
        ret = []
        simplified_path = "/"
        for p in arr:
            if p == "..":
                ret = ret[0: len(ret) - 1]
            elif p != '' and p != '.':
                ret.append(p)
        
        for p in ret:
            simplified_path += p
            simplified_path += '/'
        if len(simplified_path) > 1:
            simplified_path = simplified_path[0:len(simplified_path) - 1]
        return simplified_path
