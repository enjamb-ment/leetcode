# 2418. Sort the People
#   
#   Probably overcomplicated this.  Could've written a lambda function to pull two values when sorting instead of putting everything into a tuple.
#   

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        people = []
        for i in range(len(names)):
            people.append((names[i],heights[i]))

        people.sort(key=lambda tup: tup[1], reverse=True)  
        peopleList = [item for tup in people for item in tup]
                    #[item for t in lt for item in t]           <-- Need to dissect that one. :\
        print(peopleList)

        ans = peopleList[0::2]
        
        return ans
    


# Better solution from LeetCode (honestly looks like what I did just more efficiently... kinda.):
class Solution2:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        
        people = list(zip(heights, names))               # Pair names with heights
        
        people.sort(reverse=True, key=lambda x: x[0])    # Sort the pairs by heights in descending order
        
        sorted_names = [person[1] for person in people]  # Extract the sorted names; this bit is cool.
        
        return sorted_names