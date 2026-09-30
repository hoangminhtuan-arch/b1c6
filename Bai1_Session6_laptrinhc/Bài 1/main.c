#include <stdio.h>
#include <string.h>

int main() {
    const int MAX_PHIEU = 50;
    char maPhieu[50][20];
    int ngayQuaHan[50];
    int soLuong = 3;

    strcpy(maPhieu[0], "PM101");
    ngayQuaHan[0] = 0;
    strcpy(maPhieu[1], "PM102");
    ngayQuaHan[1] = 3;
    strcpy(maPhieu[2], "PM103");
    ngayQuaHan[2] = 5;

    int choice;
    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    printf("%d | %s | %d ngày | %d VNĐ\n", i + 1, maPhieu[i], ngayQuaHan[i], ngayQuaHan[i] * 5000);
                }
                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;

            case 2:
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                } else {
                    printf("Nhap ma phieu muon moi: ");
                    scanf("%s", maPhieu[soLuong]);
                    while (getchar() != '\n');
                    
                    ngayQuaHan[soLuong] = 0;
                    soLuong++;
                    printf("Them phieu muon thanh cong!\n");
                }
                break;

            case 3:
                {
                    char maCanTim[20];
                    printf("Nhap ma phieu muon can cap nhat: ");
                    scanf("%s", maCanTim);
                    while (getchar() != '\n');

                    int foundIndex = -1;
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maCanTim) == 0) {
                            foundIndex = i;
                            break;
                        }
                    }

                    if (foundIndex != -1) {
                        printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maCanTim, foundIndex);
                        int ngayMoi;
                        do {
                            printf("Nhap so ngay qua han moi: ");
                            scanf("%d", &ngayMoi);
                            while (getchar() != '\n');

                            if (ngayMoi < 0) {
                                printf("Loi: So ngay qua han phai >= 0. Vui long nhap lai!\n");
                            }
                        } while (ngayMoi < 0);

                        ngayQuaHan[foundIndex] = ngayMoi;
                        printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", maCanTim, ngayMoi);
                    } else {
                        printf("Khong tim thay phieu muon co ma '%s'.\n", maCanTim);
                    }
                }
                break;

            case 0:
                printf("Thoat chuong trinh. Chuc ban mot ngay tot lanh!\n");
                break;

            default:
                printf("Loi: Chuc nang khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
