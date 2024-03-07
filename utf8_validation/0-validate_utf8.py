#!/usr/bin/python3
"""
valide utf8
"""


def validUTF8(data):
    """ check if UTF-8 """
    try:
        data.decode('utf-8')
        return True
    except UnicodeError:
        return False
