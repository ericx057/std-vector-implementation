#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

template <typename T>
class Vector{
  public:
    //constructor destructor
    Vector();
    ~Vector();

    //main functions
    void sort(size_t begin, size_t end);
    void insert(size_t index, const T& val);
    void push_back(const T& val);
    void erase(size_t index);
    void pop_back();
    void clear();
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void reserve(size_t n);
    void resize(size_t n);

    //access functions
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t index);
    const T& at(size_t index) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T* data();
    const T* data() const;

    //iterator functions
    T* begin();
    const T* begin() const;
    T* end();
    const T* end() const;
    
  private: 
    T* data_;
    size_t size_;
    size_t capacity_;
};

#include "vector.cpp"
#endif