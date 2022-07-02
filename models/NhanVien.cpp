//
//  NhanVien.cpp
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 02/07/2022.
//

#include <stdio.h>
#include <string>

using namespace std;

class NhanVien{
    
public:
    string maNV;
    string ho;
    string ten;
    string phai;
    
    string validateMNV(string input){
        if (input.empty()) {
            return "Ma_Nhan_Vien khong duoc rong";
        }
        if (input.length()>10) {
            return "Ma_Nhan_Vien khong duoc qua 10 ky tu";
        }
        if (input.empty()){
            return "Ma_Nhan_Vien khong duoc chua ky tu dac biet";
        }
        return "";
    }
    string validateHo(string input){
        if (input.empty()) {
            return "Ho khong duoc rong";
        }
        if (input.empty()){
            return "Ho khong duoc chua ky tu dac biet";
        }
        return "";
    }
    string validateTen(string input){
        if (input.empty()) {
            return "Ten khong duoc rong";
        }
        return "";
    }
    string validatePhai(string input){
        if (input.empty()) {
            return "Phai khong duoc rong";
        }
        if (input.length()>1) {
            return "Phai: Nam = 1, Nu = 0";
        }
        return "";
    }
    NhanVien(){}
};
