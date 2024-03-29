#include <vector>
// Fungsi untuk mencari elemen maksimum pada tipe generik (minimal Kartu, Combo, dan Player)
using namespace std;
template <class T>
 // Preconditional: objects Tidak kosong 
T& max(vector<T> &objects){

    if(objects.size() != 1){
        T *maxElmt = &objects[0];

        for(auto& obj : objects){
            if(obj > *maxElmt){
                maxElmt = &obj;
            }
        }
        return *maxElmt;
    }
    else{
        return objects.at(0);
    }
    // T *max = &objects.at(0);

    // for(T& obj : objects){
    //     if(obj > *max){
    //         max = &obj;
    //     }
    // }

    // return *max;
};

// Fungsi untuk melakukan sorting list dengan element tipe generik (minimal Kartu, Combo, dan Player)
// Mengembalikan salinan vector of T

template<class T> // ASCENDINGSSS
vector<T> sort(vector<T> list){
    vector<T> copyList;
    if (!list.empty()){ // Jika list tidak kosong
        int size = list.size();
        for (int i=1; i<size; i++){
            int j = i;
            while (j>0 && (list[j-1] > list[j])){
                // Swap
                T temp = list[j-1];
                list[j-1] = list[j];
                list[j] = temp;
                // Decrement
                j--;
            }
            // j<=0 || list[j-1] <= list[j]
        }
    }
    
    return list;
};

template<class T> // Descending
vector<T> sortDsc(vector<T> list){
    vector<T> copyList;
    if (!list.empty()){ // Jika list tidak kosong
        int size = list.size();
        for (int i=1; i<size; i++){
            int j = i;
            while (j>0 && (list[j-1] < list[j])){
                T temp = list[j-1];
                list[j-1] = list[j];
                list[j] = temp;
                j--;
            }
            // j<=0 || list[j-1] <= list[j]
        }
    }
    
    return list;
};
