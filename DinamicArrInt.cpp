#include "DinamicArr.h"

#include <iostream>

DynamicIntArray::DynamicIntArray() : size(10), buffer(0) {
    array = new int[size];
}

DynamicIntArray::DynamicIntArray(int size) : size(size), buffer(0) {
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

DynamicIntArray::DynamicIntArray(int size, int n) : size(size), buffer(0) {
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = n;
    }
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& dynamicIntArray)
    : size(dynamicIntArray.size), buffer(dynamicIntArray.buffer) {
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = dynamicIntArray[i];
    }
}

DynamicIntArray::DynamicIntArray(DynamicIntArray&& dynamicIntArray)
    : size(dynamicIntArray.size), buffer(dynamicIntArray.buffer),
    array(dynamicIntArray.array) {
    dynamicIntArray.array = nullptr;
    dynamicIntArray.size = 0;
    dynamicIntArray.buffer = 0;
}

DynamicIntArray::~DynamicIntArray() {
    delete[] array;
    size = 0;
    buffer = 0;
}

int DynamicIntArray::getSize() const { return size; }

int& DynamicIntArray::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::exception();
    }
    return array[index];
}

int DynamicIntArray::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::exception();
    }
    return array[index];
}

void DynamicIntArray::resize(int newSize) {
    if (newSize <= size + buffer) {
        buffer -= newSize - size;
        size = newSize;
    }
    else {
        int* newArray = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            if (i < size) {
                newArray[i] = array[i];
            }
            else {
                newArray[i] = 0;
            }
        }
        delete[] array;
        size = newSize;
        buffer = 0;
        array = newArray;
    }
}

DynamicIntArray&
DynamicIntArray::operator=(const DynamicIntArray& dynamicIntArray) {
    size = dynamicIntArray.size;
    buffer = dynamicIntArray.buffer;
    delete[] array;
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = dynamicIntArray[i];
    }
    return *this;
}

DynamicIntArray& DynamicIntArray::operator=(DynamicIntArray&& dynamicIntArray) {
    if (this == &dynamicIntArray) {
        return *this;
    }
    std::swap(size, dynamicIntArray.size);
    std::swap(buffer, dynamicIntArray.buffer);
    std::swap(array, dynamicIntArray.array);
    return *this;
}

bool DynamicIntArray::operator==(const DynamicIntArray& dynamicIntArray) const {
    if (this == &dynamicIntArray) {
        return true;
    }
    if (size == dynamicIntArray.size) {
        for (int i = 0; i < size; i++) {
            if (array[i] != dynamicIntArray[i]) {
                return false;
            }
        }
    }
    return true;
}

bool DynamicIntArray::operator!=(const DynamicIntArray& dynamicIntArray) const {
    if (this == &dynamicIntArray) {
        return true;
    }
    if (size == dynamicIntArray.size) {
        for (int i = 0; i < size; i++) {
            if (array[i] == dynamicIntArray[i]) {
                return false;
            }
        }
    }
    return true;
}

bool DynamicIntArray::operator<(const DynamicIntArray& dynamicIntArray) const {
    if (this == &dynamicIntArray) {
        return false;
    }
    if (size <= dynamicIntArray.size) {
        for (int i = 0; i < size; i++) {
            if (array[i] >= dynamicIntArray[i]) {
                return false;
            }
        }
    }
    else if (size > dynamicIntArray.size) {
        for (int i = 0; i < dynamicIntArray.size; i++) {
            if (array[i] >= dynamicIntArray[i]) {
                return false;
            }
        }
    }
    return true;
}

bool DynamicIntArray::operator<=(const DynamicIntArray& dynamicIntArray) const {
    if (this == &dynamicIntArray) {
        return false;
    }
    if (size <= dynamicIntArray.size) {
        for (int i = 0; i < size; i++) {
            if (array[i] > dynamicIntArray[i]) {
                return false;
            }
        }
    }
    else if (size > dynamicIntArray.size) {
        for (int i = 0; i < size; i++) {
            if (array[i] > dynamicIntArray[i]) {
                return false;
            }
        }
    }
    return true;
}

bool DynamicIntArray::operator>(const DynamicIntArray& dynamicIntArray) const {
    if (this == &dynamicIntArray) {
        return false;
    }
    if (size <= dynamicIntArray.size) {
        for (int i = 0; i < size; i++) {
            if (array[i] <= dynamicIntArray[i]) {
                return false;
            }
        }
    }
    else if (size < dynamicIntArray.size) {
        for (int i = 0; i < size; i++) {
            if (array[i] <= dynamicIntArray[i]) {
                return false;
            }
        }
    }
    return true;
}

bool DynamicIntArray::operator>=(const DynamicIntArray& dynamicIntArray) const {
    if (this == &dynamicIntArray) {
        return false;
    }
    if (size <= dynamicIntArray.size) {
        for (int i = 0; i < size; i++) {
            if (array[i] < dynamicIntArray[i]) {
                return false;
            }
        }
    }
    else if (size < dynamicIntArray.size) {
        for (int i = 0; i < size; i++) {
            if (array[i] < dynamicIntArray[i]) {
                return false;
            }
        }
    }
    return true;
}

DynamicIntArray operator+(const DynamicIntArray& arr0,
    const DynamicIntArray& arr1) {
    auto* result = new DynamicIntArray(arr0.size + arr1.size);
    for (int i = 0; i < arr0.size; i++) {
        (*result)[i] = arr0[i];
    }
    for (int i = arr0.size; i < (arr0.size + arr1.size); i++) {
        (*result)[i] = arr1[i - arr0.size];
    }
    return *result;
}

std::ostream& operator<<(std::ostream& out,
    const DynamicIntArray& dynamicIntArray) {
    for (int i = 0; i < dynamicIntArray.size; i++) {
        out << dynamicIntArray[i];
        if (i < dynamicIntArray.size - 1) {
            out << " ";
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, DynamicIntArray& dynamicIntArray) {
    int size;
    int num;
    std::cout << "Size: ";
    in >> size;
    if (size <= 0) {
        throw std::exception();
    }
    else {
        int* tmp = new int[size];
        for (int i = 0; i < size; i++) {
            in >> num;
            tmp[i] = num;
        }
        delete[] dynamicIntArray.array;
        dynamicIntArray.array = tmp;
    }
    return in;
}

void DynamicIntArray::reserve(int buffer) {
    buffer = buffer;
    int* tmp = new int[size + buffer];
    for (int i = 0; i < size; i++) {
        tmp[i] = array[i];
    }
    delete[] array;
    array = tmp;
}

int DynamicIntArray::capacity() const { return buffer; }

void DynamicIntArray::pushBack(int element) {
    if (buffer < 1) {
        throw std::exception();
    }
    array[size++] = element;
    buffer--;
}

int DynamicIntArray::popBack() {
    if (size < 1) {
        throw std::exception();
    }
    buffer++;
    return array[--size];
}

DynamicIntArray::DynamicIntArray(int size, int buffer, int n)
    : size(size), buffer(buffer) {
    array = new int[size + buffer];
    for (int i = 0; i < size; ++i) {
           array[i] = n;
    }
}