class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = set()

        for i in range(len(board)):
            for j, v in enumerate(board[i]):
                if v != '.':
                    if (i, v) in seen or (v, j) in seen or (i // 3, j // 3, v) in seen:

                        # print(seen)
                        # print(i, j, v)
                        return False
                    seen.add((i, v))
                    seen.add((v, j))
                    seen.add((i // 3, j // 3, v))
        

        return True
