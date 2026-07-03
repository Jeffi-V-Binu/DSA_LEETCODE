class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordset = set(wordList)
        if endWord not in wordset:
            return 0
            
        L = len(beginWord)
        all_combos = defaultdict(list)
        for word in wordset:
            for i in range(L):
                combination = word[:i] + "*" + word[i+1:]
                all_combos[combination].append(word)
        queue = [(beginWord, 1)]
        head = 0
        visited = {beginWord}
        while head < len(queue):
            current_word, level = queue[head]
            head += 1
            for i in range(L):
                combination = current_word[:i] + "*" + current_word[i+1:]
                if combination in all_combos:
                    for word in all_combos[combination]:
                        if word == endWord:
                            return level + 1
                        if word not in visited:
                            visited.add(word)
                            queue.append((word, level + 1))
                            
        return 0