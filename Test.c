#include <stdio.h>
#include <stdlib.h>

// Định nghĩa số lượng chữ số tối đa có thể xử lý.
// F(47849) có khoảng 10,000 chữ số. Nếu cần lớn hơn, hãy tăng số này.
#define MAX_DIGITS 20000 

void print_big_number(int *num, int digits) {
    int i, start = 0;
    // Bỏ qua các số 0 ở đầu
    for (i = digits - 1; i >= 0; i--) {
        if (num[i] != 0) {
            start = i;
            break;
        }
    }
    
    // In từ hàng cao nhất xuống hàng đơn vị
    for (i = start; i >= 0; i--) {
        printf("%d", num[i]);
    }
}

int main() {
    unsigned long long n, i; // Sử dụng long long để chứa số n lớn
    int j;
    
    do {
        printf("Nhap n: ");
        // %llu dùng cho unsigned long long
        scanf("%llu", &n); 
    } while (n <= 0);

    // Cấp phát bộ nhớ động cho 3 biến số lớn để tránh tràn Stack
    // a: F(i-2), b: F(i-1), c: F(i)
    // Lưu trữ theo thứ tự ngược: index 0 là hàng đơn vị
    int *a = (int *)calloc(MAX_DIGITS, sizeof(int));
    int *b = (int *)calloc(MAX_DIGITS, sizeof(int));
    int *sum = (int *)calloc(MAX_DIGITS, sizeof(int));

    if (a == NULL || b == NULL || sum == NULL) {
        printf("Khong du bo nho!");
        return 1;
    }

    // Khởi tạo F(1) = 0, F(2) = 1 (hoặc F(1)=1, F(2)=1 tùy định nghĩa, ở đây làm theo code cũ của bạn)
    // Code cũ: 1 -> 0, 2 -> 1
    a[0] = 0; // F(1)
    b[0] = 1; // F(2)

    printf("Thu tu\tGia tri\n");
    
    if (n >= 1) {
        printf("1 -\t0\n");
    }
    if (n >= 2) {
        printf("2 -\t1\n");
    }

    // Số chữ số hiện tại (để tối ưu vòng lặp cộng)
    int current_digits = 1; 

    for (i = 3; i <= n; i++) {
        int carry = 0; // Số nhớ
        
        // Cộng a và b lưu vào sum (Cộng từ hàng đơn vị lên)
        for (j = 0; j < current_digits || carry; j++) {
            int temp = a[j] + b[j] + carry;
            sum[j] = temp % 10;
            carry = temp / 10;
            
            // Nếu vượt quá số chữ số hiện tại, tăng biến đếm
            if (j >= current_digits && sum[j] > 0) {
                current_digits = j + 1;
            }
        }
        
        // In kết quả
        printf("%llu -\t", i);
        print_big_number(sum, MAX_DIGITS);
        printf("\n");

        // Hoán đổi: a = b, b = sum cho vòng lặp tiếp theo
        for (j = 0; j <= current_digits; j++) {
            a[j] = b[j];
            b[j] = sum[j];
        }
    }

    // Giải phóng bộ nhớ
    free(a);
    free(b);
    free(sum);

    return 0;
}