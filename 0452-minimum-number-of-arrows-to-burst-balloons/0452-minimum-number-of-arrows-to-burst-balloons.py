class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x:x[1])
        rl = points[0][1]
        arr = 1
        for i in points:
            if i[0] > rl:
                arr += 1
                rl = i[1]
        return arr