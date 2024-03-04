class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        score = 0
        right_idx = len(tokens) - 1
        left_idx = 0
        while left_idx <= right_idx:
            # when i still have some power to exchange to score, exchange it.
            while left_idx < len(tokens) and power >= tokens[left_idx]:
                score += 1
                power -= tokens[left_idx]
                left_idx += 1
            
            # when i didn't reach the end, and i sell current score still can get some profit.
            if left_idx < right_idx - 1 and score > 0:
                score -= 1
                power += tokens[right_idx]
                right_idx -= 1
            else: 
                return score
        return score
