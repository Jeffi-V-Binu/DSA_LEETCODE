class Solution:
    def candy(self, ratings: List[int]) -> int:
        candy = [1]*len(ratings)
        for i in range(1 , len(ratings)):
            if ratings[i - 1] < ratings[i]:
                candy[i] = candy[i - 1] + 1
        for i in range(len(ratings) - 2 , -1 , -1):
            if ratings[i + 1] < ratings[i] and candy[i] <= candy[i + 1]:
                candy[i] = candy[i + 1] + 1
        sum = 0
        for i in candy:
            sum += i
        return sum