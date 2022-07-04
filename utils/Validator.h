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
using namespace std;


bool validateText(string fieldName, string &content, string input, int size){
    string text = input;
    if (text.empty()) {
        cout << fieldName << " khong duoc rong" << endl;
        return false;
    }
    if (text.length() > size) {
        cout << fieldName << " khong duoc vuot qua " << size << " ky tu"<< endl;
        return false;
    }
    content = input;
    return true;
}

bool validateIntNumber(string fieldName, int &content, string input){
    string text = input;
    if (text.empty()) {
        cout << fieldName << " khong duoc rong" << endl;
        return false;
    }
    char c[input.length()];
    strcpy(c, input.c_str());
    for (int i = 0; i< sizeof(c); i++) {
        if (!isdigit(c[i])) {
            cout << fieldName << " chi duoc nhap so nguyen"<< endl;
            return false;
        }
    }
    content = stoi(input);
    return true;
}

#endif /* Validator_h */
