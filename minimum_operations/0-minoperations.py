#!/usr/bin/python3

def minOperations(number):
    res = 0
    i = 2
    while i <= number:
        while number % i == 0:
            res += 1
            number = number // i
        i += 1
    return res