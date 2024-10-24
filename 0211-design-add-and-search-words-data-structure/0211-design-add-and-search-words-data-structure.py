class Node:
    def __init__(self):
        self.children = {}
        self.is_word = False
    
    def __repr__(self):
        return f"{self.children} , {self.is_word}"

class WordDictionary:

    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = Node()
            curr = curr.children[c]
        curr.is_word = True

    def search(self, word: str, i: int = 0, curr : Node | None = None) -> bool:
        if not curr:
            curr = self.root
        if i == len(word):
            return curr.is_word

        ans = self.search(word, i + 1, curr.children[word[i]]) if word[i] in curr.children else False

        if word[i] == ".":
            for k in curr.children.keys():
                ans = ans or self.search(word, i + 1, curr.children[k])
        return ans


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)