class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        tmp = [list(x)[::-1] for x in zip(*matrix)]
        print(tmp)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrix[i][j] = tmp[i][j]