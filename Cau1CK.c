#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct {
    float x;
    float y;
    float z;
} KG3C;

typedef struct{ 
    int id;
    double timestamp;  
    double temperature;
    KG3C location;
    } SensorData;

// ý b) Thuật toán sắp xếp nhiệt độ Giảm dần.  
// Bổ sung IPO
// * ============================================================
//    IPO (Input - Process - Output):
//    * Input  : arr[] (Mảng dữ liệu cảm biến ban đầu), n (Số lượng phần tử).
//    * Process: Duyệt từ phần tử thứ 2, chọn nó làm 'key'. So sánh 'key' với 
//               các phần tử đứng trước nó, nếu phần tử trước nhỏ hơn 'key' thì
//               đẩy lùi ra sau. Chèn 'key' vào vị trí trống tìm được.
//    * Output : Mảng arr[] được sắp xếp lại theo thứ tự nhiệt độ giảm dần.
//    ============================================================ */

void SortTemperature(SensorData arr[], int n){  
    for(int i = 1; i < n ; i++){
        SensorData key = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j].temperature < key.temperature){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}
// Ý c) Viết hàm tính nhiệt độ trung bình toàn bộ lò tại thời điểm t
// Kiểm tra có xem nhiệt độ trung bình có quá giới hạn an toàn không?

/* ============================================================
// Bổ sung thêm chú thích, lời giải thích, giải thích IPO.
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
    if (n==0) return 0;
    double avg = sum_tmp/n;
    if(avg > t_safe){
        return 1;           // Quá nhiệt
    } return 0;             // An toàn
}

//Ý d) Viết một Hàm tìm thời điểm đạt nhiệt độ đạt (nhiệt độ cao nhất) và (thấp nhất) và (ID của cảm biến)
//  đạt giá trị tương ứng trên toàn bộ mảng dữ liệu cảm biến đầu vào tương tự ở câu b.
// Vẽ FLOWCHART
//    ============================================================
//    IPO (Input - Process - Output):
//    * Input  : arr[] (Mảng dữ liệu), n (Số lượng).
//    * Process: 1. Khởi tạo result bằng giá trị của phần tử đầu tiên arr[0].
//               2. Duyệt các phần tử còn lại (i=1 -> n).
//               3. Nếu tìm thấy arr[i] > T_max hiện tại -> Cập nhật bộ Max.
//               4. Nếu tìm thấy arr[i] < T_min hiện tại -> Cập nhật bộ Min.
//    * Output : Cấu trúc min_max chứa đầy đủ thông tin về cực trị tìm được.
//    ============================================================

typedef struct min_max{
    double T_min;
    double T_max;
    int max_ID;
    double max_timestamp;  
    int min_ID;
    double min_timestamp;  
} min_max;

min_max find_min_max(SensorData arr[], int n){ 
    // Gán giá trị ban đầu cho các biến Max, Min
    min_max result;
    result.T_max = arr[0].temperature;
    result.T_min = arr[0].temperature;
    result.max_timestamp = arr[0].timestamp;
    result.min_timestamp = arr[0].timestamp;
    result.max_ID = arr[0].id;
    result.min_ID = arr[0].id;

    // Thuật toán tìm thời điểm T_max, T_min
    for(int i = 1; i < n; i++){
        if(arr[i].temperature > result.T_max){
            result.T_max = arr[i].temperature;
            result.max_ID = arr[i].id;
            result.max_timestamp = arr[i].timestamp;
        } 
          if(arr[i].temperature < result.T_min){
            result.T_min = arr[i].temperature;
            result.min_ID = arr[i].id;
            result.min_timestamp = arr[i].timestamp;
        }
    }
    return result;  
}

// Ý e) Hãy định nghĩa lại cấu trúc dữ liệu cảm biến cho phù hợp và viết hàm xoá dữ liệu cảm biến có ID đã cho
//  với khai báo hàm như sau: void remove_sensor_data_by_id(list* sensor_list, int id);
// ============================================================
//    IPO (Input - Process - Output):
//    * Input  : sensor_list (Con trỏ quản lý danh sách), id (Mã số cần xóa).
//    * Process: 1. Kiểm tra danh sách rỗng.
//               2. Nếu node đầu (Head) trùng ID -> Cập nhật Head -> Free node cũ.
//               3. Nếu node nằm giữa/cuối -> Dùng 2 con trỏ (prev, cur) để duyệt.
//                  Khi tìm thấy, nối prev->next qua cur->next -> Free cur.
//    * Output : Danh sách liên kết đã được loại bỏ node có ID tương ứng.
//    ============================================================ */

typedef struct {
    float x;
    float y;
    float z;
} KG3C;

typedef struct node{
    int id;
    double timestamp;  
    double temperature;
    KG3C location; 
    struct node *next;
} node;

// Tạo con trỏ head cho list
typedef struct list{    
    struct node *head ;
} list;

void remove_sensordate_by_id(list* sensor_list, int id){
    // 1. Kiểm tra Danh sách có rỗng đầu không?
    if (sensor_list->head == NULL) return;

    node *cur = sensor_list->head;
    node *prev = NULL;

    // TH1. Node cần xoá ở đầu danh sách
    if(cur->id == id){
        sensor_list->head = cur->next; // Cập nhật head mới 
        free(cur);                     // Giải phóng node cũ
        return;
    }

    //TH2. Node ở giữa hoặc cuối danh sách
    // Quy trình để xoá node ở giữa danh sách là: Ta sử dụng hai biến con trỏ,
    //  biến cur để duyệt và biến prev để lưu vị trí node ngay phía trước. 
    // Biến cur sẽ duyệt từng node, và prev luôn bám theo ngay sau lưng cur.
    // Khi cur gặp node có ID cần xoá, biến prev lúc này đang đứng đúng tại node phía trước đó.
    // Ta xử lý 'cánh tay' (next) của prev bằng cách trỏ nó thẳng đến node phía sau của cur
    // (tức là gán prev->next = cur->next). Cuối cùng, ta giải phóng bộ nhớ của cur."
    while(cur != NULL && cur->id != id){
        prev = cur; 
        cur = cur->next;
    }
    if(cur == NULL){
        return;
    }
    prev->next = cur->next;
    free(cur);
}


