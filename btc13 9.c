#include <stdio.h>
void inputArr(int n, int m, int arr[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap gia tri cho phan tu arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void outputArr(int n, int m, int arr[n][m]) {
    printf("Ma tran la:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void inGoc(int n, int m, int arr[n][m]) {
    printf("Cac phan tu o goc la: %d, %d, %d, %d\n", arr[0][0], arr[0][m-1], arr[n-1][0], arr[n-1][m-1]);
}

void lineArr(int n, int m, int arr[n][m]) {
    printf("Cac phan tu tren duong bien la:\n");
    for (int j = 0; j < m; j++) printf("%d ", arr[0][j]);
    for (int i = 1; i < n-1; i++) printf("%d ", arr[i][m-1]);
    for (int j = m-1; j >= 0; j--) printf("%d ", arr[n-1][j]);
    for (int i = n-2; i > 0; i--) printf("%d ", arr[i][0]);
    printf("\n");
}

void outputLine(int n, int m, int arr[n][m]) {
    printf("Cac phan tu tren duong cheo chinh la:\n");
    for (int i = 0; i < n && i < m; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\nCac phan tu tren duong cheo phu la:\n");
    for (int i = 0; i < n && i < m; i++) {
        printf("%d ", arr[i][m-i-1]);
    }
    printf("\n");
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void primeNum(int n, int m, int arr[n][m]) {
    printf("Cac phan tu la so nguyen to la:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPrime(arr[i][j])) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, m, choose;
    printf("Nhap so hang: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);

    int arr[n][m];

    do {
        printf("MENU:\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");

        printf("Moi ban chon chuc nang: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                inputArr(n, m, arr);
                break;
            case 2:
                outputArr(n, m, arr);
                break;
            case 3:
                inGoc(n, m, arr);
                break;
            case 4:
                lineArr(n, m, arr);
                break;
            case 5:
                outputLine(n, m, arr);
                break;
            case 6:
                primeNum(n, m, arr);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, moi ban chon lai!\n");
                break;
        }
    } while (choose != 7);

    return 0;
}
