class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operators = {}
        operators["+"] = lambda x,y: x + y
        operators["-"] = lambda x,y: x - y
        operators["*"] = lambda x,y: x * y
        operators["/"] = lambda x,y: int(x / y)


        stack: list[str] = []
        for c in tokens:
            # print(stack)
            if c not in operators:
                stack.append(int(c))
                continue
            b, a = stack.pop(), stack.pop()


            stack.append(operators[c](a, b))
        print(stack[0])
        return stack[0] 