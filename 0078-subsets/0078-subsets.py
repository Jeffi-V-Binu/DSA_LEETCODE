class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        seen = [0] * len(nums)
        tim = 0
        result = []
        curr = []
        def back(tim , curr):
            if tim == len(nums):
                result.append(list(curr))
                return
            curr.append(nums[tim])
            back(tim + 1 , curr)
            curr.pop()
            back(tim + 1 , curr)
        back(0 , curr)
        return result
        