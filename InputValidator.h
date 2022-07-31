#ifndef ValidationInput_h
#define ValidationInput_h

#include "BaseHeader.h"
//1.	Nhập số : chỉ nhận các ký số, quá trình nhập sẽ dừng lại khi ta ấn Enter
void inputNumber(int& number) {
    int input, i = 0;
    char *result = new char[5];
    do
    {
        input = getchar();
        if ((i == 0 && input == ZERO ) && input < ZERO && input > NINE) {
            
            continue;
        }
        result[i] = input;
        i++;   
    } while (input != '\n' && i < 5);
    if (i == 4) {
        //gioi han toi da 29999 vi int toi da 32767
        if (result[0] > 2)
        {
            cout << "nhap qua gioi han cho phep";
            return;
        }
    }
    number = atoi(result);
    delete[] result;
}


#endif /* ValidationInput_h */

