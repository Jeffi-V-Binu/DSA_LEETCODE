class Solution:
    def sortVowels(self, s: str) -> str:
        v = "AEIOUaeiou"
        a = []
        b = ""
        for i in s:
            if i in v:
                a.append(i)
        a.sort()
        j = 0
        for i in s:
            if i in v:
                b += a[j]
                j += 1
            else:
                b += i
        return b
        