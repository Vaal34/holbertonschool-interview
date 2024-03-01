#include "palindrome.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * n: list int
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
**/

int is_palindrome(unsigned long n) 
{
    int len_ul = 0;
    unsigned long tmp = n;
    while(tmp != 0)
    { 
        len_ul++;
        tmp/=10; 
    }
    printf("string is: %i \n", len_ul); 

    char str[len_ul]; 
    sprintf(str, "%ld", n); 
    printf("---%s---\n", str);


    int i = 0;
    while(i < (len_ul / 2)){
        if(str[i] != str[len_ul - 1]){
            return 0;
        }
        i++;
        len_ul--;
    }
    return 1;
}