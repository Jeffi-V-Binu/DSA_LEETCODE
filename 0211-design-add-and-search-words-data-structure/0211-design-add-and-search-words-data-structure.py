class TrieNode:
    def __init__(self):
        self.children = {}
        self.word_end = False
class WordDictionary:

    def __init__(self):
        self.root = TrieNode()
        
    def addWord(self, word: str) -> None:
        current = self.root
        for ch in word:
            if ch not in current.children:
                current.children[ch] = TrieNode()
            current = current.children[ch]
        current.word_end = True

    def search(self, word: str) -> bool:
        def dfs(index , node):
            current = node
            for i in range(index , len(word)):
                ch = word[i]
                if ch == ".":
                    for child in current.children.values():
                        if dfs(i + 1 , child):
                            return True
                    return False
                else:
                    if ch not in current.children:
                        return False
                    current = current.children[ch]
            return current.word_end
        return dfs(0 , self.root)
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)