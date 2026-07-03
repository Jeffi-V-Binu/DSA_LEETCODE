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
            if index == len(word):
                return node.word_end
            ch = word[index]
            if ch == ".":
                for child_node in node.children.values():
                    if dfs(index + 1, child_node):
                        return True
                return False
            else:
                if ch in node.children:
                    return dfs(index + 1, node.children[ch])
                return False
        return dfs(0 , self.root)
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)