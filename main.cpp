//
//  main.cpp
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 02/07/2022.
//

#include "utils/Validator.h"
#include "models/VatTu.h"


int main(int argc, const char * argv[]) {
    VatTu vatu = VatTu();
    string input;
    inputNumber(vatu.soLuongTon);
//    do{
//        cout << "Nhap ten vat tu: ";
//        cin >> input;
//    }while(!validateText(MA_VAT_TU, vatu.tenVT, input, MA_VAT_TU_SIZE));
    
    cout << vatu.toString();
}
