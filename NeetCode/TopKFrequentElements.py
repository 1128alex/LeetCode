class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # cnt each number and put it in array
        cnt = {}
        for num in nums:
            cnt[num] = 1 + cnt.get(num, 0)

        # put the num, cnt in array and sort it in ascending order
        arr = []
        for num, cnt in cnt.items():
            arr.append([cnt, num])
        arr.sort()

        # pop from the back (which is the most frequent num in the list)
        result = []
        while len(result) < k:
            result.append(arr.pop()[1])
        return result
