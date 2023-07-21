#pragma once
#include <initializer_list>
#include <algorithm>
#include <iterator>


// Konfigurasi struktur data
// Ubah berapa banyak data yang akan di realokasikan sesuai nilai threshold mid bila kapasitas habis
#define _MinCapacityThreshold_ 0.35
#define _MidCapacityThreshold_ 0.5
#define _CapacityAllocationThreshold_ 0.75

namespace dvd
{
    /**
     * @brief Dynamic Array, digunakan untuk membuat array dinamis yang tak terbatas
     * 
     * @tparam T Tipe data array
     */
    template<class T>
    class DArray
    {
    private:
        /* data */
        T* data;
        size_t size;
        size_t capacity;

    public: // Constructor & Destructor
        /**
         * @brief Membuat object DArray baru
         * 
         */
        DArray()
        {
            // Init
            this->size = 0;
            this->capacity = 0;
            this->data = nullptr;
        }

        /**
         * @brief Membuat object DArray dengan initializer list
         * 
         * @param InitList Initializer list untuk mengisi data
         */
        DArray(const std::initializer_list<T>& InitList)
        {
            // Alokasi data
            this->size = InitList.size();
            // alokasi 10 memory untuk penyimpanan awal 
            this->capacity = this->size + 10;
            this->data = new T[this->capacity];

            // Copy data ke array data
            std::copy(InitList.begin(),InitList.end(),this->data);
        }

        /**
         * @brief Destroy object DArray
         * 
         */
        ~DArray()
        {
            if (this->data != nullptr)
                delete[] this->data;
        }
    
    public: // iterator
        struct iterator{
            using iterator_category = std::random_access_iterator_tag;
            
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using reference = T&;
            using pointer = T*;

            // constructor
            iterator(pointer ptr) : m_ptr(ptr){}

            // Accessor
            reference operator*(){return *m_ptr;}
            pointer operator->(){return m_ptr;}

            // prefix
            iterator& operator++(){m_ptr++; return* this;}
            //postfix
            iterator operator++(int){iterator temp = *this; ++(*this); return temp;}

            // Self addition
            iterator& operator+=(const size_t it){m_ptr+=it; return *this;}

            // Equality operator
            friend bool operator==(const iterator& a, const iterator& b){return (a.m_ptr == b.m_ptr);}
            friend bool operator!=(const iterator& a, const iterator& b){return (a.m_ptr != b.m_ptr);}

            private:
            pointer m_ptr;
        };

        iterator begin(){return iterator(this->data);}
        iterator end(){return iterator((this->data + this->size));}
    
    public: // Method
        /**
         * @brief Masukan data kedalam array
         * 
         * @param _data Data yang akan dimasukan
         */
        void push_back(const T& _data)
        {
            // Cek jika kapasitas masih kosong maka alokasi data
            if (this->capacity == 0)
            {
                this->capacity = 10;
                this->data = new T[this->capacity];
                this->data[this->size++] = _data;
                return;
            }

            // Jika kapasitas masih dibawah threshold
            double CapacityThreshold = (static_cast<double>(this->size) / this->capacity);
            if (CapacityThreshold < _CapacityAllocationThreshold_)
            {
                // Masukan data ke array
                this->data[this->size++] = _data;
            }
            else
            {
                // this->capacity = this->size + _ReallocateCount_;
                this->capacity += this->capacity * (CapacityThreshold / _MidCapacityThreshold_) - this->capacity;
                T* tempArr = new T[this->capacity];
                std::copy(this->data,(this->data + this->size),tempArr);
                delete[] this->data;
                this->data = tempArr;
                this->data[this->size++] = _data;
            }

            return;
        }

        T pop_back()
        {
            T temp = T{};
            // Cek jika kapasitas masih kosong maka abaikan
            if (this->capacity == 0 || this->size == 0 || this->data == nullptr)
                return temp;

            double CapacityThreshold = (static_cast<double>(this->size) / this->capacity);

            if (CapacityThreshold <= _MinCapacityThreshold_)
            {
                this->capacity += this->capacity * (CapacityThreshold / _MidCapacityThreshold_) - this->capacity;
                T* tempArr = new T[this->capacity];
                std::copy(this->data,(this->data + this->size),tempArr);
                delete[] this->data;
                this->data = tempArr;
                return this->data[(this->size--) -1];
            }
            else return this->data[(this->size--) -1];
        }

        /**
         * @brief Meng-extend elemen dari array
         * 
         * @param aObj Object DArray
         */
        void extend_element(const DArray<T>& aObj)
        {
            // Extend dan tambahkan elemen dari aObj ke intance ini
            T* tempArr = nullptr;
            size_t oldSize = this->size;
            this->size += aObj.size;

            // cek array kosong atau tidak
            if (this->capacity == 0 && this->data == nullptr)
            {
                this->capacity = aObj.Capacity();
                tempArr = new T[this->capacity];
                // Masukan data dari aObj ke tempArr dimulai dari index 0
                for (size_t i = 0; i < aObj.Size(); i++)
                    tempArr[i] = aObj[i];
                
                this->data = tempArr;
                return;
            }

            // cek threshold
            double CapacityThreshold = (static_cast<double>(this->size) / this->capacity);
            if (CapacityThreshold < _CapacityAllocationThreshold_)
            {
                tempArr = new T[this->capacity];
                // Copy isi data dari array saat ini
                std::copy(this->data,(this->data + this->size),tempArr);
                // Masukan data dari aObj ke tempArr dimulai dari index oldSize
                for (size_t i = 0; i < aObj.Size();i++)
                    tempArr[oldSize++] = aObj[i];

                delete[] this->data;
                this->data = tempArr;
            }
            else {
                // Tambahkan memory lagi
                this->capacity += this->capacity * (CapacityThreshold / _MidCapacityThreshold_) - this->capacity;
                tempArr = new T[this->capacity];

                // Copy isi data dari array saat ini
                std::copy(this->data,(this->data + this->size),tempArr);
                // Masukan data dari aObj ke tempArr dimulai dari index oldSize
                for (size_t i = 0; i < aObj.Size();i++)
                    tempArr[oldSize++] = aObj[i];

                delete[] this->data;
                this->data = tempArr;
            }
        }

        /**
         * @brief Meng-extend elemen dari array
         * 
         * @tparam T Type array
         * @tparam _size Size array
         * @param array Array standard
         */
        template<size_t _size> 
        void extend_element(const T(&array)[_size])
        {
            // Extend dan tambahkan elemen dari array ke intance ini
            T* tempArr = nullptr;
            size_t oldSize = this->size;
            this->size += _size;
            
            double CapacityThreshold = (static_cast<double>(this->size) / _size);
            // cek array kosong atau tidak
            if (this->capacity == 0 && this->data == nullptr)
            {
                // Alokasikan agar thresholdnya rendah
                this->capacity += _size * (CapacityThreshold / _MidCapacityThreshold_);
                tempArr = new T[this->capacity];
                // Masukan data dari array ke tempArr dimulai dari index 0
                for (size_t i = 0; i < _size; i++)
                    tempArr[i] = array[i];
                
                this->data = tempArr;
                return;
            }

            // cek threshold
            CapacityThreshold = (static_cast<double>(this->size) / this->capacity);
            if (CapacityThreshold < _CapacityAllocationThreshold_)
            {
                tempArr = new T[this->capacity];
                // Copy isi data dari array saat ini
                std::copy(this->data,(this->data + this->size),tempArr);
                // Masukan data dari aObj ke tempArr dimulai dari index oldSize
                for (size_t i = 0; i < _size;i++)
                    tempArr[oldSize++] = array[i];

                delete[] this->data;
                this->data = tempArr;
            }
            else {
                // Tambahkan memory lagi
                this->capacity += this->capacity * (CapacityThreshold / _MidCapacityThreshold_) - this->capacity;
                tempArr = new T[this->capacity];

                // Copy isi data dari array saat ini
                std::copy(this->data,(this->data + this->size),tempArr);
                // Masukan data dari aObj ke tempArr dimulai dari index oldSize
                for (size_t i = 0; i < _size;i++)
                    tempArr[oldSize++] = array[i];

                delete[] this->data;
                this->data = tempArr;
            }
        }

        /**
         * @brief Hapuskan data array
         * 
         */
        void empty()
        {
            if (this->data != nullptr)
                delete[] this->data;

            this->size = 0;
            this->capacity = 0;
            this->data = nullptr;
        }
        
    public: // Accessor
        T& operator[](const size_t& index)
        {
            if (index < this->size)
                return *(this->data + index);
            else return *this->data;
        }

        const T& operator[](const size_t& index) const
        {
            if (index < this->size)
                return *(this->data + index);
            else return *this->data;
        }

        T& at(const size_t& index)
        {
            if (index < this->size)
                return *(this->data + index);
            else return *this->data;
        }

        const T& at(const size_t& index) const
        {
            if (index < this->size)
                return *(this->data + index);
            else return *this->data;
        }
        /**
         * @brief Ambil jumlah data yang ada di dalam array
         * 
         * @return size_t Jumlah data
         */
        size_t Size() const
        {
            return this->size;
        }
        /**
         * @brief Ambil threshold object DArray
         * 
         * @return double Threshold array
         */
        double getThreshold() const
        {
            return this->size / this->capacity;
        }

        size_t Capacity() const
        {
            return this->capacity;
        }
    };
}