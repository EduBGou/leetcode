class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest = s[0]
        n = len(s)

        for i in range(n):
            if n - i <= len(longest):
                break

            sub_str = s[i::]
            while True:
                last_idx = sub_str.rfind(s[i]) + i + 1
                if i == last_idx - 1 or last_idx == i:
                    break

                sub_str = s[i:last_idx]

                if self.isPalindrome(sub_str) and len(sub_str) > len(longest):
                    longest = sub_str
                    i = last_idx
                    break

                sub_str = sub_str[:-1]

        return longest

    def isPalindrome(self, string: str):
        for j in range(int(len(string) / 2)):
            if string[j] != string[len(string) - 1 - j]:
                return False
        return True