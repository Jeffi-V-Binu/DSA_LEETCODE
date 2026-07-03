class Solution:
    def jump(self, nums: List[int]) -> int:
        numj = 0
        currw = 0
        furtheste = 0
        for i in range(len(nums) - 1):
            if furtheste >= len(nums) - 1:
                numj += 1
                break
            furtheste = max(furtheste , i + nums[i])
            if i == currw:
                numj += 1
                currw = furtheste
            if currw >= len(nums) - 1:
                break
        return numj


        