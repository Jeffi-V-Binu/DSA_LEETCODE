class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        c = []
        for i in range(n):
            c.append(1)
        for j in range(m - 1):
            for i in range(1 , n):
                c[i] = c[i - 1] + c[i]
        return c[n - 1]