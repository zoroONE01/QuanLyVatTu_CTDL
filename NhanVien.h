//
//  NhanVien.h
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 04/07/2022.
//

#ifndef NhanVien_h
#define NhanVien_h

#include "BaseHeader.h"

using namespace std;

typedef struct {

    string maNV;
    string ho;
    string ten;
    string phai;
 // ListHoaDon listHoaDon;

    string toString(){
        return "Ma Nhan Vien: " + this->maNV + "\n" +
                "Ho: " + this->ho + "\n" +
                "Ten: " + this->ten + "\n" +
                "Phai: " + this->phai + "\n";
    }
} NhanVien;


typedef struct {

    NhanVien* listNhanVien[SO_LUONG_NHAN_VIEN_MAX];
    int currentAmount = 0;

} ListNhanVien;

#endif /* NhanVien_h */
