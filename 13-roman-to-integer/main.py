class Solution:
    def romanToInt(self, s: str) -> int:
        store = {
            "M": 1000,
            "D": 500,
            "C": 100,
            "L": 50,
            "X": 10,
            "V": 5,
            "I": 1,
        }

        l = len(s)
        i = 0
        sum = 0
        while i < l:
            v1 = store[s[i]]

            if (i < l-1):
                v2 = store[s[i+1]]

                if v2 > v1:
                    sum += (v2 - v1)
                    i += 1
                else:
                    sum += v1
            else:
                sum += v1

            i += 1

        return sum
