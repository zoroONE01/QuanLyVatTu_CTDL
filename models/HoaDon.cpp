//
//  HoaDon.cpp
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 02/07/2022.
//

#include <stdio.h>
#include <string>

using namespace std;

class HoaDon{
    
public:
    string maHD;
    string ngayLapHD;
    string loai;
    
    string validateMaHD(string input){
        if (input.empty()) {
            return "Ma_Hoa_Don khong duoc rong";
        }
        if (input.length()>20) {
            return "Ma_Hoa_Don khong duoc qua 10 ky tu";
        }
        if (input.empty()){
            return "Ma_Hoa_Don khong duoc chua ky tu dac biet";
        }
        return "";
    }
    string validateNgayLapHD(string input){
        if (input.empty()) {
            return "Ngay_Lap_Hoa_Don khong duoc rong";
        }
        
        //check ky tu dac biet
        if (input.empty()){
            return "Ngay_Lap_Hoa_Don khong duoc chua ky tu dac biet";
        }
        return "";
    }
    string validateLoai(string input){
        if (input.empty()) {
            return "Loai khong duoc rong";
        }
        return "";
    }
};
