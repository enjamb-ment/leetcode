# 409. Longest Palindrome
#   Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
#   palindrome that can be built with those letters.
#
#   Letters are case sensitive, for example, "Aa" is not considered a palindrome.


class Solution:
    def longestPalindrome(self, s: str) -> int:
        length = 0
        key = set(s)
        
        slen = len(s)
        #print(slen)

        for c in key:
            length += s.count(c) // 2
        
        length *= 2
        if slen > length:
            length += 1

        return length
    

solution = Solution()

print("Enter a string and the program will identify how long the longest palindrome could be: ")
input = input()

print(solution.longestPalindrome(input))
