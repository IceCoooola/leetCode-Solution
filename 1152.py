# You are given two string arrays username and website and an integer array timestamp. All the given arrays are of the same length and the tuple [username[i], website[i], timestamp[i]] indicates that the user username[i] visited the website website[i] at time timestamp[i].

# A pattern is a list of three websites (not necessarily distinct).

# For example, ["home", "away", "love"], ["leetcode", "love", "leetcode"], and ["luffy", "luffy", "luffy"] are all patterns.
# The score of a pattern is the number of users that visited all the websites in the pattern in the same order they appeared in the pattern.

# For example, if the pattern is ["home", "away", "love"], the score is the number of users x such that x visited "home" then visited "away" and visited "love" after that.
# Similarly, if the pattern is ["leetcode", "love", "leetcode"], the score is the number of users x such that x visited "leetcode" then visited "love" and visited "leetcode" one more time after that.
# Also, if the pattern is ["luffy", "luffy", "luffy"], the score is the number of users x such that x visited "luffy" three different times at different timestamps.
# Return the pattern with the largest score. If there is more than one pattern with the same largest score, return the lexicographically smallest such pattern.

# [username[i], website[i], timestamp[i]]

username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"]
timestamp = [1,2,3,4,5,6,7,8,9,10]
website = ["home","about","career","home","cart","maps","home","home","about","career"]


UserName_Ts_Web = {}
for i in range(len(username)):
    if username[i] in UserName_Ts_Web:
        UserName_Ts_Web[username[i]] += [(timestamp[i], website[i])]
    else:
        UserName_Ts_Web[username[i]] = [(timestamp[i], website[i])]
        # [(timestamps, websites) ,...]

pattern = {}


for Ts_Web in UserName_Ts_Web.values():
    times_sorted = sorted(Ts_Web, key=lambda x: x[0])
    # sorted tuple [(ts, website),...]
    for i in range(len(times_sorted)):
        for j in range(i+1, len(times_sorted)):
            for k in range(j + 1, len(times_sorted)):
                t = (times_sorted[i][1], times_sorted[j][1], times_sorted[k][1])
                if t not in pattern:
                    pattern[t] = 1
                else:
                    pattern[t] += 1


max_parttern = list(pattern.keys())[0]

max_count = pattern[max_parttern]

for pt ,count in pattern.items():
    if count > max_count:
        max_count = count
        max_parttern = pt

    elif max_count == count:
        if pt < max_parttern:
            max_count = count
            max_parttern = pt

print(max_parttern)

1152


user_time_web = {}
      n = len(username)
      for i in range(n):
        if username[i] not in user_time_web:
          user_time_web[username[i]] = [[timestamp[i], website[i]]]
        else:
          user_time_web[username[i]].append([timestamp[i], website[i]])
      
      def dfs(curind, data, tmp, res):
        if len(tmp) == 3:
          res.add(tuple(tmp))
          return
        for i in range(curind, len(data)):
          tmp.append(data[i][1])
          dfs(i+1, data, tmp, res)
          tmp.pop()
          
      pattern_count = collections.defaultdict(int)
      for k, v in user_time_web.items():
        v.sort(key=lambda x: (x[0], x[1]))
        patterns = set()
        dfs(0, v, [], patterns)
        for pattern in patterns:
          pattern_count[pattern] += 1
      print(pattern_count)
      count = 0
      res = None
      for pattern, tmpcount in pattern_count.items():
        if tmpcount > count:
          count = tmpcount
          res = list(pattern)
        elif tmpcount == count and res is not None and pattern < tuple(res):
          res = list(pattern)
      return res

# Example 1:

# Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]

# {name1: joe's timestamp:website, name2: james timestamp:website, name3: mary:website}
#    joe:
# {1: "home", 2: "about", 3: "career", 4: "cart", 5: "maps"} -> 10 patterns
# {} 
# {} 
# 

# Output: ["home","about","career"]
# Explanation: The tuples in this example are:
# ["joe","home",1],["joe","about",2],["joe","career",3],["james","home",4],["james","cart",5],["james","maps",6],["james","home",7],["mary","home",8],["mary","about",9], and ["mary","career",10].
# The pattern ("home", "about", "career") has score 2 (joe and mary).
# The pattern ("home", "cart", "maps") has score 1 (james).
# The pattern ("home", "cart", "home") has score 1 (james).
# The pattern ("home", "maps", "home") has score 1 (james).
# The pattern ("cart", "maps", "home") has score 1 (james).
# The pattern ("home", "home", "home") has score 0 (no user visited home 3 times).
# Example 2:

# Input: username = ["ua","ua","ua","ub","ub","ub"], timestamp = [1,2,3,4,5,6], website = ["a","b","a","a","b","c"]
# Output: ["a","b","a"]

# 3 <= username.length <= 50
# 1 <= username[i].length <= 10
# timestamp.length == username.length
# 1 <= timestamp[i] <= 10^9
# website.length == username.length
# 1 <= website[i].length <= 10
# username[i] and website[i] consist of lowercase English letters.
# It is guaranteed that there is at least one user who visited at least three websites.
# All the tuples [username[i], timestamp[i], website[i]] are unique.

