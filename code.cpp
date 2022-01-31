#include <iostream>
#include <unistd.h>
#include <clocale>

int main() // Шифрование
{ 
    char abc[] = " abcdefghigklmnopqrstuvwxyz";
    int textNumb[200], codeNumb[50], k = 0, codeTextNumb[200], codeSize = 0, textSize = 0;
    int size = sizeof(abc)-1;
    char text[200] = "";
    char codeword[50] = "";
    char codeText[200] = "";

    std::cout << "Enter text (max 200 char ONLY ENG):\n";
    std::cin.getline(text,200);
    std::cout << "Enter codeword :\n";
    std::cin.getline(codeword,50);

    for (int i=0; i<50; i++)
    {
        if (codeword[i] == '\0')
        {
            break;
        }
        for (int j=0; j<size; j++)
        {
            if (codeword[i] == abc[j])
            {
                codeNumb[i] = j;
                codeSize++;
                break;
            }
        }
    }

    for (int i=0; i<200; i++)
    {
        if (text[i] == '\0')
        {
            break;
        }        
        for (int j=0; j<size; j++)
        {            
            if (text[i] == abc[j])
            {
                textNumb[i] = j;  
                textSize++;              
                break;
            }                       
        }       
    }

    for (int i=0; i<textSize; i++)
    {
        if (k < codeSize)
        {
            codeTextNumb[i] = codeNumb[k] + textNumb[i];
            if (codeTextNumb[i] > 27)
            {
                codeTextNumb[i] -= 27;
            }
        }
        if (k == codeSize)
        {
            codeTextNumb[i] = codeNumb[k] + textNumb[i];
            if (codeTextNumb[i] > 27)
            {
                codeTextNumb[i] -= 27;
            }
            k == 0;
        }               
    }

    std::cout << "Coded text:\n";
    for (int i=0; i<textSize; i++)
    {
        codeText[i] = abc[codeTextNumb[i]];
        std::cout << codeText[i];
    }

    std::cout << "\n";

    return 0;
}