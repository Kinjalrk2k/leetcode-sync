from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        i = 0
        flag = False
        r = ""

        while i < 200:
            try:
                target = strs[0][i]
                flag = all(s[i] == target for s in strs)

                if flag:
                    r += target
                else:
                    break
            except:
                break

            i += 1

        return r

