class Solution(object):
    def myAtoi(self, s):
       
        INT_MIN = -2**31
        INT_MAX = 2**31 - 1
        
        n = len(s)
        i = 0
        
       
        while i < n and s[i] == ' ':
            i += 1
            
        
        if i == n:
            return 0
            
       
        sign = 1
        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1
            
       
        result = 0
        while i < n and s[i].isdigit():
            
            digit = int(s[i])
            
           
            if sign == 1 and (result > INT_MAX // 10 or (result == INT_MAX // 10 and digit > 7)):
                return INT_MAX
            if sign == -1 and (result > abs(INT_MIN) // 10 or (result == abs(INT_MIN) // 10 and digit > 8)):
                return INT_MIN
                
            result = result * 10 + digit
            i += 1
            
        return sign * result
