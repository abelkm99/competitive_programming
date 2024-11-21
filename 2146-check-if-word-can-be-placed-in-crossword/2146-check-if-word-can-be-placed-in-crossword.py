class Node:
    def __init__(self):
        self.is_final = False
        self.children = {}

class Trie:

    def __init__(self):
        self.root = Node()
    
    def add(self, s: str) -> None:
        curr = self.root
        for c in s:
            if c not in curr.children:
                curr.children[c] = Node()
            curr = curr.children[c]
        curr.is_final = True
    
    def check(self, s: str) -> bool:
        curr = self.root

        def dfs(node: Node, s: str, i: int) -> bool:
            if i == len(s):
                return node.is_final
            
            case_1, case_2 = False, False
            if ' ' in node.children:
                case_1 = dfs(node.children[' '], s, i + 1)
            if s[i] in node.children:
                case_2 = dfs(node.children[s[i]], s, i + 1)

            return case_1 or case_2
        
        return dfs(self.root, s, 0)

class Solution:
    def placeWordInCrossword(self, board: List[List[str]], word: str) -> bool:
        strs = []
        n, m = len(board), len(board[0])

        T = Trie()

        for r in range(n):
            c = 0
            while c < m:
                while c < m and board[r][c] == '#':
                    c += 1
                j = c
                tmp = []
                while j < m and board[r][j] != '#':
                    tmp.append(board[r][j])
                    j += 1
                st = "".join(tmp)
                if st:
                    T.add(st)
                    # print(c, j, tmp)
                c = j

        for c in range(m):
            r = 0
            while r < n:
                while r < n and board[r][c] == '#':
                    r += 1
                i = r
                tmp = []
                while i < n and board[i][c] != '#':
                    tmp.append(board[i][c])
                    i += 1
                st = "".join(tmp)
                if st:
                    T.add(st)
                    # print(r, i, tmp)
                r = i
        word2 = "".join(list(word)[::-1])
        return T.check(word) or T.check(word2)