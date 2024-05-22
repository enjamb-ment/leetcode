#1108. Defanging an IP Address

class Solution:
    def defangIPaddr(self, address: str) -> str:
        #return address.replace(".","[.]")
        return address.replace(".","[.]")

solution = Solution()

print("Enter an IP address: ")
ip_address = input()
print(solution.defangIPaddr(ip_address))