#include <stdio.h>
#include <string.h>
char XOR(char a, char b, char c, char d) {
    int x;
    x = (a - '0') ^ (b - '0') ^ (c - '0') ^ (d - '0');
    return (x + '0');
}

int main() {
    char data[10], r[4], syn[4], code[10];
    printf("This works for message of 4 bits in size\n");
    scanf("%s", data);
    r[2] = XOR(data[1], data[2], data[3], '0'); 
    r[1] = XOR(data[0], data[1], data[2], '0'); 
    r[0] = XOR(data[0], data[2], data[3], '0'); 
    r[3] = '\0';
    printf("\nRedundant bits are: ");
    puts(r);
    char codeword[10];
    strcpy(codeword, data);
    strcat(codeword, r);
    printf("Code word to send: %s\n", codeword);
    printf("\nEnter receiver's 7-bit code word: ");
    scanf("%s", code);
    syn[2] = XOR(code[1], code[2], code[3], code[6]);
    syn[1] = XOR(code[0], code[1], code[2], code[5]);
    syn[0] = XOR(code[0], code[2], code[3], code[4]);
    syn[3] = '\0';
    printf("Syndrome bits: %s\n", syn);
    if (syn[0] == '0' && syn[1] == '0' && syn[2] == '0')
        printf("No error\n");
    else if (syn[0] == '0' && syn[1] == '0' && syn[2] == '1')
        printf("Error is in code[4] by Q0\n");
    else if (syn[0] == '0' && syn[1] == '1' && syn[2] == '0')
        printf("Error is in code[5] or Q1\n");
    else if (syn[0] == '0' && syn[1] == '1' && syn[2] == '1')
        printf("Error is in code[1] or B2\n");
    else if (syn[0] == '1' && syn[1] == '0' && syn[2] == '0')
        printf("Error is in code[6] or Q2\n");
    else if (syn[0] == '1' && syn[1] == '0' && syn[2] == '1')
        printf("Error is in code[3] or B0\n");
    else if (syn[0] == '1' && syn[1] == '1' && syn[2] == '0')
        printf("Error is in code[0] or B3\n");
    else
        printf("Error is in code[2] or B1\n");
    return 0;
}
