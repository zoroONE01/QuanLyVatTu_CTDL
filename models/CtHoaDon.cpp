//
//  CtHoaDon.cpp
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 02/07/2022.
//
#include <stdio.h>
#include <string>

using namespace std;
class CtHoaDon{
    
public:
    string maVT;
    unsigned int soLuong;
    float donGia;
    unsigned short int vat;
    
    string validateMaVT(string input){
        if (input.empty()) {
            return "Ma_Vat_Tu khong duoc rong";
        }
        if (input.length()>20) {
            return "Ma_Vat_Tu khong duoc qua 10 ky tu";
        }
        if (input.empty()){
            return "Ma_Vat_Tu khong duoc chua ky tu dac biet";
        }
        return "";
    }
    string validateSoLuong(string input){
        if (input.empty()) {
            return "So_Luong khong duoc rong";
        }
        
        //check ky tu dac biet
        if (input.empty()){
            return "So_Luong khong duoc chua ky tu dac biet";
        }
        return "";
    }
    string validateDonGia(string input){
        if (input.empty()) {
            return "Don_Gia khong duoc rong";
        }
        
        //check ky tu dac biet
        if (input.empty()){
            return "Don_Gia khong duoc chua ky tu dac biet";
        }
        return "";
    }
    string validateVAT(string input){
        if (input.empty()) {
            return "VAT khong duoc rong";
        }
        return "";
    }
};

