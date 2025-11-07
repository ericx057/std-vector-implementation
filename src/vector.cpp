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
    if(begin>= end || end > size_) return;
    T p = data_[end-1];
    size_t i = begin;
    for(size_t j = begin; j< end-1; j++){
        if(data_[j]<p){
            T temp = data_[i];
            data_[i] = data_[j];
            data_[j] = temp;
            i++;
        }
    }
    
    T temp = data_[i];
    data_[i] = data_[end -1];
    data_[end -1] = temp;

    if(i>begin) sort(begin, i);
    if(i+1 < end) sort(i+1, end);
}

// Insert element at index
template <typename T>
void Vector<T>::insert(size_t index, const T& val){
    if(index>size_ || index<0) return;
    capacity_++;
    size_++;
    T* new_data = new T[capacity_];
    for(int i = 0; i<index; i++){
        new_data[i]=data_[i];
    }
    new_data[index] = val;
    for(int i = index+1; i<size_; i++){
        new_data[i] = data_[i-1];
    }
    delete[] data_;
    data_= new_data;
}

// Add element to end
template <typename T>
void Vector<T>::push_back(const T& val){
    if(capacity_ == 0){
        capacity_ = 1;
        data_ = new T[capacity_];
    } else if (size_ == capacity_){
        capacity_*=2;
        T* new_data = new T[capacity_];
        for(int i = 0; i<size_; i++){
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
    }

    data_[size_] = val;
    size_++;
}

// Remove element at index
template <typename T>
void Vector<T>::erase(size_t index){
    T* new_data = new T[size_-1];
    for(int i = 0; i<index; i++){
        new_data[i] = data_[i];
    }
    for(int i = index; i<size_-1; i++){
        new_data[i] = data_[i+1];
    }

    delete [] data_;
    data_=new_data;
    size_-=1;
}

// Remove last element
template <typename T>
void Vector<T>::pop_back(){
    if(size_ == 0) return;
    else {
        T* new_data = new T[capacity_];

        for(int i = 0; i<size_-1; i++){
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        size_--;
    }
}

// Clear all elements
template <typename T>
void Vector<T>::clear(){
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
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
    if(n<=capacity_) return;
    T* new_data = new T[n];
    for (size_t i = 0; i<size_; i++){
        new_data[i] = data_[i];
    }
    delete [] data_;
    data_ = new_data;
    capacity_ = n;
}

// Resize vector
template <typename T>
void Vector<T>::resize(size_t n){
    if(n<size_) size_ = n;
    else if (n>size_){
        if(n>capacity_) reserve(n);
        for(size_t i = 0; i<n; i++){
            data_[i]=T();
        }
        size_ = n;
    } else return;
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
    if(index>=size_) throw std::out_of_range("Index out of range");
    return data_[index];
}

// Const access with bounds checking
template <typename T>
const T& Vector<T>::at(size_t index) const{
    if(index>=size_) throw std::out_of_range("Index out of range");
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
