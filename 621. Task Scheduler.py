class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        task_need_complete = [0] * 26
        for task in tasks:
            idx = ord(task) - ord('A')
            task_need_complete[idx] += 1
        task_need_complete.sort(reverse = True)
        # count the number of maximum frequency
        count_of_max_freq = task_need_complete.count(task_need_complete[0])
        # assume n >= amount of distint tasks, we complete it in maximum frequency cycles.
        cycles = task_need_complete[0] - 1
        # in each cycle, there are n + 1 tasks, because we need to account for the idle
        # in the last cycle, only the largest frequency tasks has not been finished yet, so plus the amount of largest frequency
        count = cycles * (n + 1) + count_of_max_freq
        # now the other case show up: the wait time that is smaller than the number of different tasks.
        return max(count, len(tasks))
