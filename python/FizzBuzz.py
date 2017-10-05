#!/usr/bin/env python3

for number in range(1, 101):
    s = ''
    if (number % 3 == 0):
        s += 'Fizz'
    if (number % 5 == 0):
        s += 'Buzz'
    if not s:
        s += str(number)
    print(s)   


