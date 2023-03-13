#include <vector>
// Fungsi untuk mencari elemen maksimum pada tipe generik (minimal Kartu, Combo, dan Player)
template <class T>
T max(vector<T> objects){
    // objects Tidak kosong 
    T maxElmt = objects[0];

    for(auto obj : objects){
        if(obj > maxElmt){
            maxElmt = obj;
        }
    }

    return maxElmt;
};