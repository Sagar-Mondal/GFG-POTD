class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        hmap = dict()
        hmap1 = dict()
        for i in range(len(s)):
            hmap[s[i]] = i
            hmap1[t[i]] = i
        if list(hmap.values()) == list(hmap1.values()):
            return True
        return False                   