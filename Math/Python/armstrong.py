num = input() # input
sum = 0
temp = num
while temp > 0:
  digit = temp % 10
  sum += digit ** 3
  temp //= 10
print(num == sum) # true if input is an armstrong number, false if not
