class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        n = len(points)
        if n == 1:
            return 1
        points.sort()
        ll = points[0][0]
        rl = points[0][1]
        arr = 1
        for i in range(1 , n):
            if points[i][0] <= rl:
                rl = min(rl , points[i][1])
                ll = max(ll , points[i][0])
            else:
                l = points[i][0]
                rl = points[i][1]
                arr += 1
        return arr