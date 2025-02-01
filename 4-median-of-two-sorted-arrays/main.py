from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l1 = len(nums1)
        l2 = len(nums2)

        s = []

        i = 0
        j = 0
        while i < l1 and j < l2:
            if nums1[i] < nums2[j]:
                s.append(nums1[i])
                i += 1
            else:
                s.append(nums2[j])
                j += 1

        while i < l1:
            s.append(nums1[i])
            i += 1

        while j < l2:
            s.append(nums2[j])
            j += 1

        # nums1.extend(nums2)
        # s = sorted(nums1)

        n = l1+l2
        if n % 2 == 0:
            a = int((n-1)/2)
            t = int((n+1)/2)
            return float((s[a] + s[t])/2)
        else:
            t = int(n/2)
            return float(s[t])

