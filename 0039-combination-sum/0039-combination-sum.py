class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        index = 0
        sum = 0
        result = []
        curr = []
        def back(index , sum , curr):
            if sum > target:
                return 
            if sum == target:
                result.append(list(curr))
            if index == len(candidates):
                return
            for i in range(index , len(candidates)):
                sum += candidates[i]
                curr.append(candidates[i])
                back(i , sum , curr)
                curr.pop()
                sum -= candidates[i]
        back(index , sum , curr)
        return result
        