# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
#   A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. 
#   For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
#
#   Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.
#
#   This was a medium problem...  Boiled down to whatever the highest digit in the string was. Could've turned it into a list if I wanted to I guess, 
#   but figured a set would make finding a value easier.


class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(set(n)))
        