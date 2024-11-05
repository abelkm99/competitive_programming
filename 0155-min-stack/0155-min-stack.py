class MinStack:

    def __init__(self):
        self.stack : list[int] = []
        self.min : list[int] = []
        

    def push(self, val: int) -> None:
        self.stack.append(val) # append the value
        if not self.min:
            self.min.append(len(self.stack) - 1) # just add the first value
        else:
            if val < self.stack[self.min[-1]]:
                self.min.append(len(self.stack) - 1)
            else:
                self.min.append(self.min[-1])

    def pop(self) -> None:
        self.stack.pop()
        self.min.pop()
        

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.stack[self.min[-1]]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()