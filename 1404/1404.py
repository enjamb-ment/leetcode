# 1404. Number of Steps to Reduce a Number in Binary Representation to One
#   yeah.  dead easy when there's no int overflow

class Solution:
    def numSteps(self, s: str) -> int:
        sint = int(s,2)
        count = 0
        while sint != 1:
            if sint % 2 == 0:
                sint //=2   # this needs to be "//" not "/" to use "floor" division... which is...
                            # division operation that rounds the result down to the nearest whole number or integer, which is less than or equal to the normal division result
                count += 1
            else:
                sint += 1
                count += 1
            # print(sint, count)
        return count


solution = Solution()

print("enter a binary number (e.g. 101101): ")
binary_num = input()

print("Number of steps to reduce a binary number to one: " + str(solution.numSteps(binary_num)))