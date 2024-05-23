# I feel like this should be pretty easy... if it's already a list, you just need to + it with itself.

# yup.

from typing import List     # needs this for defining the List[int] piece.  Found that out on Stackoverflow.

class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        return nums + nums                                      #I keep forgetting to "return" the value
    

#tricky part is building the code to test it...
solution = Solution()
nums = []
n = int(input("Enter number of elements : "))

for n in range(0,n):
    elem = int(input())
    nums.append(elem)

print("Here's the list you made: " + str(nums))

print("Here's the concatenated list: " + str(solution.getConcatenation(nums)))