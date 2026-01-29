#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

// --- ĐỊNH NGHĨA CẤU TRÚC DỮ LIỆU ---

typedef struct {
    float x;
    float y;
    float z;
} KG3C;

// Cấu trúc cho mảng (Bài a, b, c, d)
typedef struct{ 
    int id;
    double timestamp;  
    double temperature;
    KG3C location;
} SensorData;

// Cấu trúc trả về cho hàm tìm Min/Max (Bài d)
typedef struct min_max{
    double T_min;
    double T_max;
    int max_ID;
    double max_timestamp;  
    int min_ID;
    double min_timestamp;  
} min_max;

// Cấu trúc Node cho Danh sách liên kết (Bài e)
typedef struct node{
    int id;
    double timestamp;  
    double temperature;
    KG3C location; 
    struct node *next;
} node;

// Cấu trúc quản lý List (Bài e)
typedef struct list{    
    struct node *head;
} list;


// --- CÁC HÀM XỬ LÝ ---

/* ============================================================
   Ý b) Thuật toán sắp xếp nhiệt độ Giảm dần (Insertion Sort)
   ============================================================
   IPO (Input - Process - Output):
   * Input  : arr[] (Mảng dữ liệu cảm biến ban đầu), n (Số lượng phần tử).
   * Process: Duyệt từ phần tử thứ 2, chọn nó làm 'key'. So sánh 'key' với 
              các phần tử đứng trước nó, nếu phần tử trước nhỏ hơn 'key' thì
              đẩy lùi ra sau. Chèn 'key' vào vị trí trống tìm được.
   * Output : Mảng arr[] được sắp xếp lại theo thứ tự nhiệt độ giảm dần.
   ============================================================ */
void SortTemperature(SensorData arr[], int n){  
    for(int i = 1; i < n ; i++){
        SensorData key = arr[i];
        int j = i - 1;
        // Sắp xếp giảm dần: arr[j].temperature < key.temperature
        while (j >= 0 && arr[j].temperature < key.temperature){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

/* ============================================================
   Ý c) Kiểm tra nhiệt độ trung bình có quá giới hạn an toàn không
   ============================================================
   IPO (Input - Process - Output):
   * Input  : arr[] (Mảng dữ liệu), n (Số lượng), t_safe (Ngưỡng an toàn).
   * Process: 1. Duyệt mảng cộng dồn nhiệt độ vào biến sum_tmp.
              2. Tính trung bình cộng (avg).
              3. So sánh avg với t_safe.
   * Output : Trả về 1 (True) nếu quá nhiệt, trả về 0 (False) nếu an toàn.
   ============================================================ */
int CheckOverHeat(SensorData arr[], int n, double t_safe){
    double sum_tmp = 0.0;
    // 1. Tính tổng nhiệt độ
    for(int i = 0; i < n; i++){
        sum_tmp += arr[i].temperature;
    }
    
    // 2. Tính trung bình và so sánh
    if (n == 0) return 0; // Tránh lỗi chia cho 0
    
    double avg = sum_tmp / n;
    
    if(avg > t_safe){
        return 1;           // Quá nhiệt
    } 
    return 0;               // An toàn
}

/* ============================================================
   Ý d) Tìm thời điểm và ID đạt nhiệt độ cao nhất và thấp nhất
   ============================================================
   IPO (Input - Process - Output):
   * Input  : arr[] (Mảng dữ liệu), n (Số lượng).
   * Process: 1. Khởi tạo result bằng giá trị của phần tử đầu tiên arr[0].
              2. Duyệt các phần tử còn lại (i=1 -> n).
              3. Nếu tìm thấy arr[i] > T_max hiện tại -> Cập nhật bộ Max.
              4. Nếu tìm thấy arr[i] < T_min hiện tại -> Cập nhật bộ Min.
   * Output : Cấu trúc min_max chứa đầy đủ thông tin về cực trị tìm được.
   ============================================================ */
min_max find_min_max(SensorData arr[], int n){ 
    // Gán giá trị ban đầu
    min_max result;
    result.T_max = arr[0].temperature;
    result.T_min = arr[0].temperature;
    result.max_timestamp = arr[0].timestamp;
    result.min_timestamp = arr[0].timestamp;
    result.max_ID = arr[0].id;
    result.min_ID = arr[0].id;

    // Thuật toán tìm kiếm
    for(int i = 1; i < n; i++){
        // Kiểm tra Max
        if(arr[i].temperature > result.T_max){
            result.T_max = arr[i].temperature;
            result.max_ID = arr[i].id;
            result.max_timestamp = arr[i].timestamp;
        } 
        // Kiểm tra Min
        if(arr[i].temperature < result.T_min){
            result.T_min = arr[i].temperature;
            result.min_ID = arr[i].id;
            result.min_timestamp = arr[i].timestamp;
        }
    }
    return result;  
}

/* ============================================================
   Ý e) Xoá dữ liệu cảm biến có ID đã cho trong Danh sách liên kết
   ============================================================
   IPO (Input - Process - Output):
   * Input  : sensor_list (Con trỏ quản lý danh sách), id (Mã số cần xóa).
   * Process: 1. Kiểm tra danh sách rỗng.
              2. Nếu node đầu (Head) trùng ID -> Cập nhật Head -> Free node cũ.
              3. Nếu node nằm giữa/cuối -> Dùng 2 con trỏ (prev, cur) để duyệt.
                 Khi tìm thấy, nối prev->next qua cur->next -> Free cur.
   * Output : Danh sách liên kết đã được loại bỏ node có ID tương ứng.
   ============================================================ */
void remove_sensordata_by_id(list* sensor_list, int id){ 
    // 1. Kiểm tra Danh sách có rỗng đầu không?
    if (sensor_list->head == NULL) return;

    node *cur = sensor_list->head;
    node *prev = NULL;

    // TH1: Node cần xoá ở đầu danh sách (Head)
    if(cur->id == id){
        sensor_list->head = cur->next; // Cập nhật head mới 
        free(cur);                     // Giải phóng node cũ
        return;
    }

    // TH2: Node ở giữa hoặc cuối danh sách
    // Duyệt tìm node
    while(cur != NULL && cur->id != id){
        prev = cur; 
        cur = cur->next;
    }
    
    // Nếu chạy hết danh sách mà không thấy (cur == NULL)
    if(cur == NULL){
        return;
    }
    
    // Tìm thấy: Nối dây và xóa
    prev->next = cur->next;
    free(cur);
}