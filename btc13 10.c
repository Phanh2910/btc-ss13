#include <stdio.h>

void addAllItem(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("phan tu thu arr[%d]: \n", i);
        scanf("%d", &arr[i]);
    }
}

void showItems(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("phan tu arr[%d] co gia tri %d \n", i, arr[i]);
    }
}

void updateItem(int arr[], int index, int value) {
    arr[index - 1] = value;
}

void deleteItem(int arr[], int *size, int index) {
    for (int i=index-1; i<*size-1; i++) {
        arr[i]=arr[i+1];
    }
    (*size)--;
}

void sortArray(int arr[], int size, int a) {
    for (int i=0; i<size-1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((a && arr[i] > arr[j]) || (!a && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int value) {
    int low=0, high=size-1;
    while (low<=high) {
        int mid=(low+high) / 2;
        if (arr[mid]==value) {
            return mid;
        } else if (arr[mid] < value) {
            low= mid+1;
        } else {
            high =mid-1;
        }
    }
    return -1;
}

int main() {
    int arr[100];
    int size = 0;
    int choose;
    
    do {
        printf("\tMENU\n");
        printf("1. them so luong phan tu vao va nhap gia tri \n");
        printf("2. in ra cac gia tri cac phan tu dang quan ly\n");
        printf("3. chen them phan tu vao vi tri chi ding\n");
        printf("4. sua mot phan tu\n");
        printf("5. xoa mot phan tu o vi tri chi dinh\n");
        printf("6. sap xep cac phan tu\n");
        printf("7. tim kiem phan tu nhap vao\n");
        printf("8. thoat\n");
        printf("moi ban chon case: \n");
        scanf("%d", &choose);
        
        switch(choose) {
            case 1:
                printf("moi ban nhap so luong phan tu: \n");
                scanf("%d", &size);
                addAllItem(arr, size);
                break;
            case 2:
                showItems(arr, size);
                break;
            case 3:
                {
                    int index, value;
                    printf("Nhap vao vi tri muon them: \n");
                    scanf("%d", &index);
                    if (index < 1 || index > size + 1) {
                        printf("Khong co vi tri nay\n");
                    } else {
                        printf("Nhap gia tri muon them: \n");
                        scanf("%d", &value);
                        for (int i = size; i >= index; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[index - 1] = value;
                        size++;
                    }
                }
                break;
            case 4:
                {
                    int index, value;
                    printf("Nhap vi tri can sua (bat dau tu 1): ");
                    scanf("%d", &index);
                    if (index >= 1 && index <= size) {
                        printf("Nhap gia tri moi: ");
                        scanf("%d", &value);
                        updateItem(arr, index, value);
                    } else {
                        printf("Vi tri khong hop le.\n");
                    }
                }
                break;
            case 5:
                {
                    int index;
                    printf("Nhap vi tri can xoa (bat dau tu 1): ");
                    scanf("%d", &index);
                    if (index >= 1 && index <= size) {
                        deleteItem(arr, &size, index);
                    } else {
                        printf("Vi tri khong hop le.\n");
                    }
                }
                break;
            case 6:
                {
                    printf("Chon kieu sap xep:\n");
                    printf("a. Giam dan\n");
                    printf("b. Tang dan\n");
                    char answer;
                    getchar();
                    scanf("%c", &answer);
                    if (answer == 'a') {
                        sortArray(arr, size, 0);
                    } else if (answer == 'b') {
                        sortArray(arr, size, 1);
                    }
                }
                break;
            case 7:
                {
                    int value, index;
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &value);
                    printf("Chon phuong phap tim kiem:\n");
                    printf("a. Tim kiem tuyen tinh\n");
                    printf("b. Tim kiem nhi phan\n");
                    char answer;
                    getchar();
                    scanf("%c", &answer);
                    if (answer == 'a') {
                        index = linearSearch(arr, size, value);
                    } else if (answer == 'b') {
                        sortArray(arr, size, 1);
                        index = binarySearch(arr, size, value);
                    }
                    if (index != -1) {
                        printf("Tim thay phan tu tai vi tri %d\n", index);
                    } else {
                        printf("Khong tim thay phan tu\n");
                    }
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, moi ban chon lai!\n");
                break;
        }
    } while(choose != 8);
    
    return 0;
}
