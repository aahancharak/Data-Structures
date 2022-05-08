# Given two strings text1 and tex2, return the length of their longest common subsequence
# If there is no common subsequence, return 0.

# Example:
# input: "abcde", "abce"
# output: 4
# Explanation: The longest common subsequence of the two strings is "abce" which has a length of 4.

# Approach 1: A recursive solution
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        return self.subsequence(text1, text2, 0, 0)

    def subsequence(self, text1, text2, i, j):
        # Edge check where strings are empty
        if i == len(text1) or j == len(text2):
            return 0

        if text1[i] == text2[j]:
            return 1 + self.subsequence(text1, text2, i + 1, j + 1)
        else:
            return max(self.subsequence(text1, text2, i + 1, j), self.subsequence(text1, text2, i, j + 1))

# Approach 2: Recursive Solution with Memoization
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m = len(text1)
        n = len(text2)
        memo = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]
        return self.helper(text1, text2, 0, 0, memo)

    def helper(self, text1, text2, i, j, memo):
        if memo[i][j] < 0:
            if i == len(text1) or j == len(text2):
                memo[i][j] = 0
            elif text1[i] == text2[j]:
                memo[i][j] = 1 + self.helper(text1, text2, i + 1, j + 1, memo)
            else:
                memo[i][j] = max(
                    self.helper(text1, text2, i + 1, j, memo),
                    self.helper(text1, text2, i, j + 1, memo),
                )
        return memo[i][j]