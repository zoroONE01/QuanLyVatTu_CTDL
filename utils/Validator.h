//
//  Validator.h
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 04/07/2022.
//

#ifndef Validator_h
#define Validator_h

#include <string>
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <conio.h>

#define ESCAPE 27
#define SPACE 32

using namespace std;



string inputText(string fieldName, string &content, string input, int size){
    if (input.empty()) {
        return fieldName + " khong duoc rong\n";
        
    }
    if (input.length() > size) {
        return fieldName + " khong duoc vuot qua " + to_string(size) + " ky tu";
    }
    content = input;
    return NULL;
}

string inputNumber(int &content){
    char key_press;
    int ascii_value;
    while(1) {
        key_press=getch();
        ascii_value=key_press;
        if(ascii_value==ESCAPE) // For ESC
                break;
        cout<<"Ban nhap phim-> \" "<<key_press<<" \" Gia tri ASCII =  "<<ascii_value<<"\n";
        }
    
    if (input.empty()) {
        return "Khong duoc rong\n";
    }
    char c[input.length()];
    strcpy(c, input.c_str());
    for (int i = 0; i< sizeof(c); i++) {
        if (!isdigit(c[i])) {
            return "Chi duoc nhap so nguyen\n";
        }
    }
    return NULL;
}
#endif /* Validator_h */
