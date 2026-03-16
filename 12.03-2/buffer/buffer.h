#include <algorithm>    //std::copy из задания
#include <utility>      //std::move из задания
using namespace std;

class Buffer {
private:
    char* data;
    size_t capacity;      

public:
    //Конструкторы которые уже были
    Buffer(size_t cap) : capacity(cap), data(new char[cap]) {}

    ~Buffer() { delete[] data; }

    Buffer(const Buffer& other) : capacity(other.capacity), data(new char[other.capacity]) {
        std::copy(other.data, other.data + other.capacity, data);
    }

    
    //Конструктор перемещения
    Buffer(Buffer&& other) noexcept : data(other.data), capacity(other.capacity) {
        other.data = nullptr;
        other.capacity = 0;
    }

    //Оператор присваивания перемещением
    Buffer& operator=(Buffer&& other) noexcept {
  
        if (this != &other) {
            delete[] data;            

            data = other.data;
            capacity = other.capacity;

            other.data = nullptr;
            other.capacity = 0;
        }
        return *this;
    }
};