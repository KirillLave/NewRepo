#include <iostream>

class DynamicIntArray {
private:
    int size;
    int buffer;
    int* array;
public:
    // rule of 6
    DynamicIntArray();

    explicit DynamicIntArray(int);

    DynamicIntArray(int, int);

    DynamicIntArray(const DynamicIntArray&);

    DynamicIntArray& operator=(const DynamicIntArray&);

    DynamicIntArray(DynamicIntArray&&);

    DynamicIntArray& operator=(DynamicIntArray&&);

    ~DynamicIntArray();

    int getSize() const;

    int& operator[](int);

    int operator[](int) const;

    void resize(int);

    bool operator==(const DynamicIntArray&) const;

    bool operator!=(const DynamicIntArray&) const;

    bool operator<(const DynamicIntArray&) const;

    bool operator<=(const DynamicIntArray&) const;

    bool operator>(const DynamicIntArray&) const;

    bool operator>=(const DynamicIntArray&) const;

    friend DynamicIntArray operator+(const DynamicIntArray&, const DynamicIntArray&);

    friend std::ostream& operator<<(std::ostream&, const DynamicIntArray&);

    friend std::istream& operator>>(std::istream&, DynamicIntArray&);

    void reserve(int);

    int capacity() const;

    void pushBack(int);

    int popBack();

    DynamicIntArray(int, int, int);
};

