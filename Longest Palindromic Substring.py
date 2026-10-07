class Solution(object):
    def longestPalindrome(self, s):
        if not s:
            return ""
        
        # Track the starting index and total length of the longest palindrome
        self.start = 0
        self.max_len = 0
        
        def expand_around_center(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            
            current_len = right - left - 1
            if current_len > self.max_len:
                self.max_len = current_len
                self.start = left + 1

        for i in range(len(s)):
            expand_around_center(i, i)     
            expand_around_center(i, i + 1) 
                
        return s[self.start : self.start + self.max_len]
