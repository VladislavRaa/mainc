#!/usr/bin/env python3

def is_palindrome(number):
    str_number = str(number)
    return str_number == str_number[::-1]
       
max_palindrome = 0
   
for a in range (999, 100, -1):
    for b in range(999, 100, -1):
        multiple = a * b
        if multiple > max_palindrome and is_palindrome(multiple):
            max_palindrome = multiple
    
print(max_palindrome)

