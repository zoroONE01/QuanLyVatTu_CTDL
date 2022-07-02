//
//  VatTu.cpp
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 02/07/2022.
//

#include <stdio.h>
#include <string>

using namespace std;

class VatTu{
    
public:
    string maVT;
    string tenVT;
    string donViTinh;
    unsigned int soLuongTon;
    
    string validateMaVT(string input){
        if (input.empty()) {
            return "Ma_Vat_Tu khong duoc rong";
        }
        if (input.length()>10) {
            return "Ma_Vat_Tu khong duoc qua 10 ky tu";
        }
        if (input.empty()){
            return "Ma_Vat_Tu khong duoc chua ky tu dac biet";
        }
        return "";
    }
    string validateTenVT(string input){
        if (input.empty()) {
            return "Ten_Vat_Tu khong duoc rong";
        }
        if (input.empty()){
            return "Ten_Vat_Tu khong duoc chua ky tu dac biet";
        }
        return "";
    }
    
    string validateDonViTinh(string input){
        if (input.empty()) {
            return "Don_Vi_Tinh khong duoc rong";
        }
        if (input.empty()){
            return "Don_Vi_Tinh khong duoc chua ky tu dac biet";
        }
        return "";
    }
    
    string validateSoLuongTon(string input){
        if (input.empty()) {
            return "So_Luong_Ton khong duoc rong";
        }
        char c[input.length()];
        strcpy(c, input.c_str());
        for (int i = 0; i< sizeof(c); i++) {
            if (!isdigit(c[i])) {
                return "So_Luong_Ton khong duoc nhap chu";
            }
        }
        return "";
    }
    
    VatTu(){};
};
