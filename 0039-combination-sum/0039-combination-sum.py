class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        def back(index , sum , curr):
            if sum > target:
                return 
            if sum == target:
                result.append(list(curr))
            if index == len(candidates):
                return
            for i in range(index , len(candidates)):
                curr.append(candidates[i])
                back(i , sum + candidates[i] , curr)
                curr.pop()
        back(0 , 0 , [])
        return result
        