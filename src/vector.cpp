#include "vector.h"
#include <cstddef>
#include <stdexcept>

using std::size_t;

// Constructor
template <typename T>
Vector<T>::Vector(){
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

// Destructor
template <typename T>
Vector<T>::~Vector(){
    delete[] data_;
}

// Sort elements from begin to end indices
template <typename T>
void Vector<T>::sort(size_t begin, size_t end){
    // TODO: Implement sorting algorithm
}

// Insert element at index
template <typename T>
void Vector<T>::insert(size_t index, const T& val){
    // TODO: Implement insert
}

// Add element to end
template <typename T>
void Vector<T>::push_back(const T& val){
    // TODO: Implement push_back
}

// Remove element at index
template <typename T>
void Vector<T>::erase(size_t index){
    // TODO: Implement erase
}

// Remove last element
template <typename T>
void Vector<T>::pop_back(){
    // TODO: Implement pop_back
}

// Clear all elements
template <typename T>
void Vector<T>::clear(){
    // TODO: Implement clear
}

// Return number of elements
template <typename T>
size_t Vector<T>::size() const{
    return size_;
}

// Return capacity
template <typename T>
size_t Vector<T>::capacity() const{
    return capacity_;
}

// Check if empty
template <typename T>
bool Vector<T>::empty() const{
    return size_ == 0;
}

// Reserve capacity
template <typename T>
void Vector<T>::reserve(size_t n){
    // TODO: Implement reserve
}

// Resize vector
template <typename T>
void Vector<T>::resize(size_t n){
    // TODO: Implement resize
}

// Access operator (no bounds checking)
template <typename T>
T& Vector<T>::operator[](size_t index){
    return data_[index];
}

// Const access operator (no bounds checking)
template <typename T>
const T& Vector<T>::operator[](size_t index) const{
    return data_[index];
}

// Access with bounds checking
template <typename T>
T& Vector<T>::at(size_t index){
    if (index >= size_){
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

// Const access with bounds checking
template <typename T>
const T& Vector<T>::at(size_t index) const{
    if (index >= size_){
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

// Return first element
template <typename T>
T& Vector<T>::front(){
    return data_[0];
}

// Const return first element
template <typename T>
const T& Vector<T>::front() const{
    return data_[0];
}

// Return last element
template <typename T>
T& Vector<T>::back(){
    return data_[size_ - 1];
}

// Const return last element
template <typename T>
const T& Vector<T>::back() const{
    return data_[size_ - 1];
}

// Return pointer to data
template <typename T>
T* Vector<T>::data(){
    return data_;
}

// Const return pointer to data
template <typename T>
const T* Vector<T>::data() const{
    return data_;
}

// Return iterator to beginning
template <typename T>
T* Vector<T>::begin(){
    return data_;
}

// Const return iterator to beginning
template <typename T>
const T* Vector<T>::begin() const{
    return data_;
}

// Return iterator to end
template <typename T>
T* Vector<T>::end(){
    return data_ + size_;
}

// Const return iterator to end
template <typename T>
const T* Vector<T>::end() const{
    return data_ + size_;
}
