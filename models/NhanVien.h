//
//  NhanVien.h
//  QuanLyVatTu_CTDL
//
//  Created by Thanh Tu Nguyen on 04/07/2022.
//

#ifndef NhanVien_h
#define NhanVien_h

#include <stdio.h>
#include <string>

#define MA_NHAN_VIEN_SIZE 10
#define MA_NHAN_VIEN "Ma Nhan Vien"
#define HO "Ho"
#define TEN "Ten"
#define PHAI "Phai"

using namespace std;

class NhanVien{
    
public:
    string maNV;
    string ho;
    string ten;
    string phai;
    
    NhanVien(){}
    
    string toString(){
        return "Ma Nhan Vien: " + this->maNV + "\n" +
                "Ho: " + this->ho + "\n" +
                "Ten: " + this->ten + "\n" +
                "Phai: " + this->phai + "\n";
    }
};


#endif /* NhanVien_h */
