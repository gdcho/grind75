class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        ans = [[1]]
        for i in range(2, numRows + 1):
            cur_ans = [1]
            for j in range(i - 2):
                cur_ans.append(ans[-1][j] + ans[-1][j + 1])
            cur_ans.append(1)
            ans.append(cur_ans)
        return ans