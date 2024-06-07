# 648. Replace Words
# In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".
#
# Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.
#
# Return the sentence after the replacement.


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        s = sentence.split()
        print(s)

        for i in range(len(s)):
            for word in dictionary:
                if s[i].find(word) != -1:
                    print(s[i].find(word))
                    print(s[i])
                    print(word)

                    s[i] = word

                    print(s[i].index(word))
            ++i

        print(s)
        print("s check: " + ''.join(s))

        ans = []

        for j in range(len(s)):
            ans.append(s[j])

        ans.append(s[])
        ans = ''.join(s)

        return ans
    
    
class SolutionWorks:
def replaceWords(self, dict: List[str], sentence: str) -> str:
    roots = set(dict)
    words = sentence.split()
    result = []

    for word in words:
        for i in range(len(word) + 1):
            prefix = word[:i]
            if prefix in roots:
                result.append(prefix)
                break
        else:
            result.append(word)

    return ' '.join(result)