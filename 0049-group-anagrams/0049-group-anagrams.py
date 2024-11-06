class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dct = defaultdict(list)
        for s in strs:
            dct["".join(sorted(s))].append(s)
        
        return [v for v in dct.values()]