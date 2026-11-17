class Solution:
    def minSessions(self, tasks: list[int], sessionTime: int) -> int:
        def popFromList(tasks: list[int], indexes):
            indexes = set(indexes)
            tasks[:] = [x for i, x in enumerate(tasks) if i not in indexes]

        tasks.sort()
        sessions = 0
        left = 0
        right = len(tasks) - 1
        ac = 0
        pac = right
        lastState = 0
        popList = []

        while len(tasks) > 0:
            if len(tasks) == 1:
                sessions += 1
                return sessions

            if right <= left:
                popList.append(right)
                popFromList(tasks, popList)
                left = 0
                right = len(tasks) - 1
                sessions += 1
                lastState = 0
                ac = 0
                pac = right
                popList = []
                continue

            total = tasks[left] + tasks[right] + ac

            if total == sessionTime:
                popList.append(left)
                popList.append(right)
                popFromList(tasks, popList)
                left = 0
                right = len(tasks) - 1
                sessions += 1
                lastState = 0
                ac = 0
                pac = right
                popList = []

            elif total < sessionTime:
                if left == pac - 1:
                    ac += tasks[left]
                    popList.append(left)
                    pac = left
                    left = 0
                else:
                    left += 1
                lastState = -1

            else:
                if lastState == -1:
                    if left > 0:
                        popList.append(left - 1)


                    popList.append(right)
                    popFromList(tasks, popList)
                    lastState = 0
                    sessions += 1
                    right = len(tasks) - 1
                    left = 0
                    ac = 0
                    pac = right
                    popList = []
                else:
                    right -= 1
                    pac = right

        return sessions


def main():
    test_cases = [([2, 3, 3, 4, 4, 4, 5, 6, 7, 10], 12)]

    solution = Solution()

    for i, (tasks, sessionTime) in enumerate(test_cases, 1):
        print(f"\n{'=' * 50}")
        print(f"TEST CASE {i}")
        print(f"Input: tasks={tasks}, sessionTime={sessionTime}")

        try:
            result = solution.minSessions(tasks.copy(), sessionTime)
            print(f"\nResult: {result}")
        except (IndexError, ValueError) as e:
            print(f"\nERROR: {type(e).__name__}: {e}")


main()
