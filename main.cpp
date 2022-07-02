//
//  main.cpp
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 02/07/2022.
//

#include <iostream>
#include "models/VatTu.cpp"
using namespace std;
int main(int argc, const char * argv[]) {
    VatTu vatu = VatTu();
    string input;
    cout << "Nhap so luong ton: ";
    cin >> input;
    cout << vatu.setSoLuongTon(input);
}
