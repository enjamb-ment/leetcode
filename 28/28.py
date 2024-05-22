#28. Find the Index of the First Occurrence in a String

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        try:
            return haystack.index(needle)
        except ValueError:
            return -1

solution = Solution()
print("enter a word for \"haystack\"")
haystack = input()

print("enter a word-part for \"needle\"")
needle = input()

print("The index of the first occurrence is " + str(solution.strStr(haystack, needle)))
