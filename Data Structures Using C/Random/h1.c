/*Problem Description

Given a series of integer pairs  and , output the sum of  and .

Input Format

Each line contains two integers,  and . One input file may contain several pairs  where .

Output Format

Output a single integer per line - The sum of  and .

Constraints

SAMPLE INPUT
1 2
2 5
10 14
SAMPLE OUTPUT
3
7
24
Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB*/
// Write your code here
#include <stdio.h>
#include <conio.h>
#include <string.h>

char *bigadd(char *c, const char *a, const char *b) {
    size_t alen = strlen(a);
    size_t blen = strlen(b);
    size_t clen = (alen > blen) ? alen : blen;
    size_t i = clen;
    int digit, carry = 0;
    c[i] = '\0';
    while (i > 0) {
        digit = ((alen ? a[--alen] - '0' : 0) +
            (blen ? b[--blen] - '0' : 0) +
            carry);
        carry = digit >= 10;
        c[--i] = (char)('0' + (digit - carry * 10));
    }
    if (carry) {
        memmove(c + 1, c, clen + 1);
        c[0] = '1';
    }
    return c;
}

int main() {
    char a[100], b[100], c[101];

    while (scanf("%99s%99s", a, b) > 0) {
        printf("%s\n", bigadd(c, a, b));
    }
    getch();
    return 0;
}