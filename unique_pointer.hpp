#pragma once

template <typename T>
class unique_pointer {
    T* data;

    public:
        unique_pointer(T data = nullptr){
            this->data = new T;
            *this->data = data; //Take the dereference this, get the member data, and then dereference data to set the incoming value
        }

        unique_pointer(T* data = nullptr) : data(data){}

        ~unique_pointer() {
            delete data;
        }

        unique_pointer(unique_pointer& pointer) = delete;

        unique_pointer& operator=(unique_pointer& pointer) = delete;


        unique_pointer(unique_pointer&& pointer) {
            data = pointer.data;
            pointer.data = nullptr;
        }

        unique_pointer& operator=(unique_pointer&& pointer) {
            if(this != &pointer) {
                delete data;
                data = pointer.data;
                pointer.data = nullptr;
            }
            return *this;
        }

        unique_pointer* operator*() {
            return &this;
        }

        unique_pointer& operator->() {
            return *this;
        }

        bool operator==(unique_pointer& pointer) {
            return this == pointer;
        }
        
        bool operator!=(unique_pointer& pointer) {
            return this != pointer;
        }

        T* get() const{
            return this->data;
        }

        unique_pointer& make_unique_ptr(T data) {
            return unique_pointer(new T(data));
        }

        //void release(){}

        //swap(){}



};

template <typename T>
class unique_pointer<T[]> {
    T* data;

    public:
        unique_pointer(int size) {
            *(this->data) = new T[size];
        }

        unique_pointer(T* data = nullptr) : data(data){}

        ~unique_pointer() {
            delete[] data;
        }

        //Need to make the copy and move operator 

        unique_pointer(unique_pointer& pointer) = delete;

        unique_pointer& operator=(unique_pointer& pointer) = delete;


        unique_pointer(unique_pointer&& pointer) {
            data = pointer.data;
            pointer.data = nullptr;
        }

        unique_pointer& operator=(unique_pointer&& pointer) {
            if(this != &pointer) {
                delete data;
                data = pointer.data;
                pointer.data = nullptr;
            }
            return *this;
        }

        unique_pointer* operator*() {
            return &this;
        }

        unique_pointer& operator->() {
            return *this;
        }

        bool operator==(unique_pointer& pointer) {
            return this == pointer;
        }
        
        bool operator!=(unique_pointer& pointer) {
            return this != pointer;
        }

        T* get() const{
            return this->data;
        }

        unique_pointer& make_unique_ptr(int size) {
            return unique_pointer(new T[size]);
        }

        //void release(){}

        //swap(){}



};