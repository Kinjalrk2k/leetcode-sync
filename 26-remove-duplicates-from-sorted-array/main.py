class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = len(nums)
        i = 1
        prev = nums[0]

        while i < l:
            if nums[i] == prev:
                del nums[i]
                l -= 1
            else:
                prev = nums[i]
                i += 1
        
        return l