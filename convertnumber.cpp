#include "convertnumber.h"

//convert function
void convertNumberToBin(int in, char *out)
{
    int tmp;
    int count = 0;
    char ctmp;
    while(in)
    {
        tmp = in % 2;

        if(tmp)
        {
            ctmp = '1';
        }
        else
        {
            ctmp = '0';
        }

        out[count] = ctmp;
        count++;
        in = in / 2;
    }
}

void convertNumberToHex(int in, char *out)
{
    int tmp;
    int count = 0;
    char ctmp;

    while(in)
    {
        tmp = in % 16;

        switch(tmp)
        {
            case 0: ctmp = '0';
                break;
            case 1: ctmp = '1';
                break;
            case 2: ctmp = '2';
                break;
            case 3: ctmp = '3';
                break;
            case 4: ctmp = '4';
                break;
            case 5: ctmp = '5';
                break;
            case 6: ctmp = '6';
                break;
            case 7: ctmp = '7';
                break;
            case 8: ctmp = '8';
                break;
            case 9: ctmp = '9';
                break;
            case 10: ctmp = 'A';
                 break;
            case 11: ctmp = 'B';
                 break;
            case 12: ctmp = 'C';
                 break;
            case 13: ctmp = 'D';
                 break;
            case 14: ctmp = 'E';
                 break;
            default:
                ctmp = 'F';
            break;
        }
        out[count] = ctmp;
        count++;
        in = in / 16;
    }

}

