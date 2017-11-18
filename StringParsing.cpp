#include "StringParsing.h"

//nnn dd.dd *#

int chr_digit (char x) // transforms char into digit
{
    return (int)x - '0';
}

bool isValid (char *x) //tests validity of string
{
    return x[10] == '#' && x[11] == '*';
}

void parsing (char *x, int &id, double &temp) //parses string into id and temp
{
    id = chr_digit(x[0]) * 100 + chr_digit(x[1]) * 10 + chr_digit(x[2]);
    temp = chr_digit(x[4]) * 10 + chr_digit(x[5]) + chr_digit(x[7])/10.0 + chr_digit(x[8])/100.0;
}
