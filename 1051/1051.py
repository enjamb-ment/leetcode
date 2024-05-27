# 1051. Height Checker

from typing import List     # needs this for defining the List[int] piece.  Found that out on Stackoverflow.

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = sorted(heights)
        temp = []
        
        for i in range(len(heights)):
            if expected[i] != heights[i]:
                temp.append(i)
        
        return len(temp)
    


solution = Solution()
nums = []
n = int(input("Enter number of elements : "))

for n in range(0,n):
    elem = int(input())
    nums.append(elem)
    
print("Here's the list you made: " + str(nums))

print("This checks to see if they're in ascending order and reports how many aren't: " + str(solution.heightChecker(nums)))