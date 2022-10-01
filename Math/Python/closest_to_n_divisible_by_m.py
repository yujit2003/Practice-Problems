# Given non-zero two integers N and M.
# The problem is to find the number closest to N and divisible by M. 
# If there are more than one such number, then output the one having maximum absolute value.

m = int(input())
n = int(input())
q = int(n / m)
n1 = m * q # 1st
if((n * m) > 0): # 2nd
    n2 = (m * (q + 1))
else:
    n2 = (m * (q - 1))

if (abs(n - n1) < abs(n - n2)): #f ind which is bigger
    print(n1)
print(n2)
