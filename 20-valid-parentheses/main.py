class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c in ["(", "{", "["]:
                stack.append(c)
                continue

            if len(stack) == 0:
                return False

            if c == ")":
                t = stack.pop()
                if t == "(":
                    continue
                else:
                    return False

            elif c == "}":
                t = stack.pop()
                if t == "{":
                    continue
                else:
                    return False

            elif c == "]":
                t = stack.pop()
                if t == "[":
                    continue
                else:
                    return False

        if len(stack) > 0:
            return False
        else:
            return True
