#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"
#include "time.h"
#include "conio.h"
#include "iostream"

struct DOVAT {
    char ten[50];
    float trongLuong;
    float giaTri;
    int soLuong;
    float donGia;
    int phuongAn;
};

void xoaKyTuXuongDong(char* str) {
    int len = strlen(str);
    if (str[len - 1] = '\n') {
        str[len - 1] = '\0';
    }
}

DOVAT nhapDoVat() {
    DOVAT dv;
    getchar();
    printf("\nNhap ten do vat: ");
    fgets(dv.ten, sizeof(dv.ten), stdin);
    xoaKyTuXuongDong(dv.ten);
    printf("\nNhap trong luong cua do vat: ");
    scanf("%f", &dv.trongLuong);
    printf("\nNhap gia tri cua do vat: ");
    scanf("%f", &dv.giaTri);
    printf("\nNhap so luong cua do vat: ");
    scanf("%d", &dv.soLuong);
    return dv;
}

void nhapDanhSachDoVat(DOVAT* dv, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap do vat thu %d: ", i + 1);
        dv[i] = nhapDoVat();
    }
}

void xuatDoVat(DOVAT dv) {
    printf("\n%-15s %-10.2f %-10.2f %-10.2f %-10d", dv.ten, dv.trongLuong, dv.giaTri, dv.donGia, dv.soLuong);
}

void xuatDanhSachDoVat(DOVAT* dv, int n) {
    printf("\n%-15s %-10s %-10s %-10s %-10s", "Ten do vat", "Trong luong", "Gia tri", "Don gia", "So luong");
    for (int i = 0; i < n; i++) {
        xuatDoVat(dv[i]);
    }
}

void tinhDonGia(DOVAT* dv, int n) {
    for (int i = 0; i < n; i++) {
        dv[i].donGia = dv[i].giaTri / dv[i].trongLuong;
    }
}

void sapXepGiamTheoDonGia(DOVAT* dv, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dv[i].donGia < dv[j].donGia) {
                DOVAT tmp = dv[i];
                dv[i] = dv[j];
                dv[j] = tmp;
            }
        }
    }
}

void chonDoVat(DOVAT* dv, int n, float w) {
    for (int i = 0; i < n; i++) {
        dv[i].phuongAn = w / dv[i].trongLuong;
        if (dv[i].phuongAn > dv[i].soLuong) {
            dv[i].phuongAn = dv[i].soLuong;
        }
        w -= dv[i].phuongAn * dv[i].trongLuong;
    }
}

void xuatCachLuachonDoVat(DOVAT* dv, int n) {
    float giaTri = 0;
    for (int i = 0; i < n; i++) {
        if (dv[i].phuongAn != 0) {
            printf("\nLay %d do vat %s.", dv[i].phuongAn, dv[i].ten);
            giaTri += dv[i].phuongAn * dv[i].giaTri;
        }
    }
    printf("\nTong gia tri: %0.2f", giaTri);
}

int main() {
    int n;
    float w;
    printf("\nNhap so luong do vat: ");
    scanf("%d", &n);
    printf("\nNhap trong luong cua ba lo: ");
    scanf("%f", &w);
    DOVAT* dv = new DOVAT[n];
    printf("\n========== NHAP DACH SACH DO VAT ==========");
    nhapDanhSachDoVat(dv, n);
    tinhDonGia(dv, n);
    printf("\n========== XUAT DANH SACH DO VAT ==========");
    xuatDanhSachDoVat(dv, n);
    tinhDonGia(dv, n);
    sapXepGiamTheoDonGia(dv, n);
    printf("\n========== XUAT DANH SACH DO VAT DA SAP XEP GIAM THEO DON GIA ==========");
    xuatDanhSachDoVat(dv, n);
    chonDoVat(dv, n, w);
    printf("\n========== XUAT CACH LUA CHON DO VAT VA TONG GIA TRI LAY DUOC ==========");
    xuatCachLuachonDoVat(dv, n);
}
