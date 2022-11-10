#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct lưu thông tin 1 đại lý, là 1 node trong danh sách đại lý
typedef struct DaiLy {
    char tenDaiLy[25];
    char soDienThoai[15];
    double doanhThu;
    struct DaiLy *next;
} DaiLy;

// Cấp phát bộ nhớ và nhập dữ liệu cho 1 con trỏ đại lý
DaiLy *khoiTaoDaiLy() {
    DaiLy *daiLy = (DaiLy *)malloc(sizeof(DaiLy));

    printf("Nhap ten dai ly: ");
    fflush(stdin);
    gets(daiLy->tenDaiLy);

    printf("Nhap so dien thoai: ");
    fflush(stdin);
    scanf("%s", daiLy->soDienThoai);

    printf("Nhap doanh thu: ");
    scanf("%lf", &daiLy->doanhThu);
    daiLy->next = NULL;
    return daiLy;
}

// In thông tin 1 đại lý
void inDaiLy(DaiLy *daiLy) {
    printf("%-25s\t%-15s\t%10.2lf\n", daiLy->tenDaiLy, daiLy->soDienThoai, daiLy->doanhThu);
}

// Danh sách liên kết chứa các đại lý
typedef struct {
    DaiLy *head;
    DaiLy *tail;
} ListDaiLy;

// Khởi tạo danh sách đại lý
ListDaiLy *khoiTaoListDaiLy() {
    ListDaiLy *listDaiLy = (ListDaiLy *)malloc(sizeof(ListDaiLy));
    listDaiLy->head = NULL;
    listDaiLy->tail = NULL;
    return listDaiLy;
}

// Thêm 1 đại lý vào danh sách
void themDaiLy(ListDaiLy *listDaiLy, DaiLy *daiLy) {
    if (listDaiLy->head == NULL) {
        listDaiLy->head = daiLy;
        listDaiLy->tail = daiLy;
    } else {
        listDaiLy->tail->next = daiLy;
        listDaiLy->tail = daiLy;
    }
}

// In danh sách đại lý
void inDanhSachDaiLy(ListDaiLy *listDaiLy) {
    if (listDaiLy->head == NULL) {
        printf("Danh dai ly sach rong\n");
    } else {
        printf("%-25s\t%-15s\t%10s\n", "Ten dai ly", "So dien thoai", "Doanh thu");
        DaiLy *daiLy = listDaiLy->head;
        while (daiLy != NULL) {
            inDaiLy(daiLy);
            daiLy = daiLy->next;
        }
    }
    printf("\n");
}

// Struct lưu thông tin 1 thành phố, là 1 node trong danh sách thành phố
typedef struct ThanhPho {
    char tenThanhPho[25];
    // Danh sách đại lý của thành phố
    ListDaiLy *listDaiLy;
    // Con trỏ trỏ đến thành phố tiếp theo
    struct ThanhPho *next;
} ThanhPho;

// Cấp phát bộ nhớ và nhập dữ liệu cho 1 con trỏ thành phố
ThanhPho *khoiTaoThanhPho(char *tenThanhPho) {
    ThanhPho *thanhPho = (ThanhPho *)malloc(sizeof(ThanhPho));
    strcpy(thanhPho->tenThanhPho, tenThanhPho);
    thanhPho->listDaiLy = khoiTaoListDaiLy();
    thanhPho->next = NULL;
    return thanhPho;
}

// In thông tin 1 thành phố
void inThanhPho(ThanhPho *thanhPho) {
    printf("Thanh pho: %s\n", thanhPho->tenThanhPho);
    inDanhSachDaiLy(thanhPho->listDaiLy);
}

// Danh sách liên kết Công Ty chứa các thành phố
typedef struct {
    char tenCongTy[25];
    ThanhPho *head;
    ThanhPho *tail;
} CongTy;

// Khởi tạo danh sách thành phố
CongTy *khoiTaoCongTy(char *tenCongTy) {
    CongTy *congTy = (CongTy *)malloc(sizeof(CongTy));
    strcpy(congTy->tenCongTy, tenCongTy);
    congTy->head = NULL;
    congTy->tail = NULL;
    return congTy;
}

// Thêm 1 thành phố vào danh sách
void themThanhPho(CongTy *congTy, ThanhPho *thanhPho) {
    if (congTy->head == NULL) {
        congTy->head = thanhPho;
        congTy->tail = thanhPho;
    } else {
        congTy->tail->next = thanhPho;
        congTy->tail = thanhPho;
    }
}

// Thêm 1 đại lý vào danh sách đại lý của thành phố
void themDaiLyVaoThanhPho(CongTy *congTy, char *tenThanhPho, DaiLy *daiLy) {
    ThanhPho *thanhPho = congTy->head;
    while (thanhPho != NULL) {
        if (strcmp(thanhPho->tenThanhPho, tenThanhPho) == 0) {
            themDaiLy(thanhPho->listDaiLy, daiLy);
            return;
        }
        thanhPho = thanhPho->next;
    }
}

// Cập nhật thông tin đại lý ở 1 thành phố
void capNhatDaiLy(CongTy *congTy, char *tenThanhPho, char *tenDaiLy, char *soDienThoai, double doanhThu) {
    ThanhPho *thanhPho = congTy->head;
    while (thanhPho != NULL) {
        if (strcmp(thanhPho->tenThanhPho, tenThanhPho) == 0) {
            DaiLy *daiLy = thanhPho->listDaiLy->head;
            while (daiLy != NULL) {
                if (strcmp(daiLy->tenDaiLy, tenDaiLy) == 0) {
                    strcpy(daiLy->soDienThoai, soDienThoai);
                    daiLy->doanhThu = doanhThu;
                    return;
                }
                daiLy = daiLy->next;
            }
        }
        thanhPho = thanhPho->next;
    }
}

// Xóa đại lý ở 1 thành phố
void xoaDaiLy(CongTy *congTy, char *tenThanhPho, char *tenDaiLy) {
    ThanhPho *thanhPho = congTy->head;
    while (thanhPho != NULL) {
        if (strcmp(thanhPho->tenThanhPho, tenThanhPho) == 0) {
            DaiLy *daiLy = thanhPho->listDaiLy->head;
            DaiLy *daiLyTruoc = NULL;
            while (daiLy != NULL) {
                if (strcmp(daiLy->tenDaiLy, tenDaiLy) == 0) {
                    if (daiLyTruoc == NULL) {
                        thanhPho->listDaiLy->head = daiLy->next;
                    } else {
                        daiLyTruoc->next = daiLy->next;
                    }
                    free(daiLy);
                    return;
                }
                daiLyTruoc = daiLy;
                daiLy = daiLy->next;
            }
        }
        thanhPho = thanhPho->next;
    }
}

// Tìm thành phố theo tên
ThanhPho *timThanhPho(CongTy *congTy, char *tenThanhPho) {
    ThanhPho *thanhPho = congTy->head;
    while (thanhPho != NULL) {
        if (strcmp(thanhPho->tenThanhPho, tenThanhPho) == 0) {
            return thanhPho;
        }
        thanhPho = thanhPho->next;
    }
    return NULL;
}

// Kiểm tra thành phố có tồn tại hay không
int kiemTraThanhPho(CongTy *congTy, char *tenThanhPho) {
    return timThanhPho(congTy, tenThanhPho) != NULL;
}

// Tìm đại lý theo tên ở 1 thành phố
DaiLy *timDaiLy(CongTy *congTy, char *tenThanhPho, char *tenDaiLy) {
    ThanhPho *thanhPho = congTy->head;
    while (thanhPho != NULL) {
        if (strcmp(thanhPho->tenThanhPho, tenThanhPho) == 0) {
            DaiLy *daiLy = thanhPho->listDaiLy->head;
            while (daiLy != NULL) {
                if (strcmp(daiLy->tenDaiLy, tenDaiLy) == 0) {
                    return daiLy;
                }
                daiLy = daiLy->next;
            }
        }
        thanhPho = thanhPho->next;
    }
    return NULL;
}

// Kiểm tra đại lý có tồn tại hay không
int kiemTraDaiLy(CongTy *congTy, char *tenThanhPho, char *tenDaiLy) {
    return timDaiLy(congTy, tenThanhPho, tenDaiLy) != NULL;
}

// In thông tin công ty
void inThongTinCongTy(CongTy *congTy) {
    printf("Ten cong ty: %s\n", congTy->tenCongTy);
    ThanhPho *thanhPho = congTy->head;
    while (thanhPho != NULL) {
        inThanhPho(thanhPho);
        thanhPho = thanhPho->next;
    }
}

// Menu chính
void menu() {
    printf("1. Them thanh pho\n");
    printf("2. Them dai ly vao thanh pho\n");
    printf("3. Cap nhat thong tin dai ly\n");
    printf("4. Xoa dai ly\n");
    printf("5. In thong tin cong ty\n");
    printf("6. Tim dai ly\n");
    printf("7. Tim thanh pho\n");
    printf("0. Thoat\n");
}

int main() {
    CongTy *congTy = khoiTaoCongTy("Cong ty IUH Software");
    int chon;
    do {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &chon);
        printf("\n");
        switch (chon) {
            // Thêm thành phố
            case 1: {
                char tenThanhPho[100];
                printf("Nhap ten thanh pho: ");
                fflush(stdin);
                gets(tenThanhPho);
                if (kiemTraThanhPho(congTy, tenThanhPho)) {
                    printf("Thanh pho da ton tai\n");
                } else {
                    themThanhPho(congTy, khoiTaoThanhPho(tenThanhPho));
                    printf("Them thanh pho thanh cong\n");
                }
                break;
            }
            // Thêm đại lý vào thành phố
            case 2: {
                char tenThanhPho[100];
                printf("Nhap ten thanh pho: ");
                fflush(stdin);
                gets(tenThanhPho);
                if (kiemTraThanhPho(congTy, tenThanhPho)) {
                    DaiLy *daiLy = khoiTaoDaiLy();
                    if (kiemTraDaiLy(congTy, tenThanhPho, daiLy->tenDaiLy)) {
                        printf("Dai ly da ton tai\n");
                    } else {
                        themDaiLyVaoThanhPho(congTy, tenThanhPho, daiLy);
                    }
                } else {
                    printf("Thanh pho khong ton tai\n");
                }
                break;
            }
            // Cập nhật thông tin đại lý
            case 3: {
                char tenThanhPho[100];
                printf("Nhap ten thanh pho: ");
                fflush(stdin);
                gets(tenThanhPho);
                if (kiemTraThanhPho(congTy, tenThanhPho)) {
                    char tenDaiLy[100];
                    char soDienThoai[100];
                    double doanhThu;
                    printf("Nhap ten dai ly: ");
                    fflush(stdin);
                    gets(tenDaiLy);
                    if (kiemTraDaiLy(congTy, tenThanhPho, tenDaiLy)) {
                        printf("Nhap so dien thoai: ");
                        scanf("%s", soDienThoai);
                        printf("Nhap doanh thu: ");
                        scanf("%lf", &doanhThu);
                        capNhatDaiLy(congTy, tenThanhPho, tenDaiLy, soDienThoai, doanhThu);
                    } else {
                        printf("Dai ly khong ton tai\n");
                    }
                } else {
                    printf("Thanh pho khong ton tai\n");
                }

                break;
            }
            // Xóa đại lý
            case 4: {
                char tenThanhPho[100];
                printf("Nhap ten thanh pho: ");
                fflush(stdin);
                gets(tenThanhPho);
                if (kiemTraThanhPho(congTy, tenThanhPho)) {
                    char tenDaiLy[100];
                    printf("Nhap ten dai ly: ");
                    fflush(stdin);
                    gets(tenDaiLy);
                    if (kiemTraDaiLy(congTy, tenThanhPho, tenDaiLy)) {
                        xoaDaiLy(congTy, tenThanhPho, tenDaiLy);
                    } else {
                        printf("Dai ly khong ton tai\n");
                    }
                } else {
                    printf("Thanh pho khong ton tai\n");
                }
                break;
            }
            // In thông tin công ty
            case 5: {
                inThongTinCongTy(congTy);
                break;
            }
            // Tìm đại lý
            case 6: {
                char tenThanhPho[100];
                printf("Nhap ten thanh pho: ");
                fflush(stdin);
                gets(tenThanhPho);
                if (kiemTraThanhPho(congTy, tenThanhPho)) {
                    char tenDaiLy[100];
                    printf("Nhap ten dai ly: ");
                    fflush(stdin);
                    gets(tenDaiLy);
                    DaiLy *daiLy = timDaiLy(congTy, tenThanhPho, tenDaiLy);
                    if (daiLy != NULL) {
                        inDaiLy(daiLy);
                    } else {
                        printf("Dai ly khong ton tai\n");
                    }
                } else {
                    printf("Thanh pho khong ton tai\n");
                }
                break;
            }
            // Tìm thành phố
            case 7: {
                char tenThanhPho[100];
                printf("Nhap ten thanh pho: ");
                fflush(stdin);
                gets(tenThanhPho);
                ThanhPho *thanhPho = timThanhPho(congTy, tenThanhPho);
                if (thanhPho != NULL) {
                    inThanhPho(thanhPho);
                } else {
                    printf("Thanh pho khong ton tai\n");
                }
                break;
            }
            case 0: {
                printf("Tam biet\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le\n");
                break;
            }
        }
        printf("\n");
    } while (chon != 0);

    return 0;
}