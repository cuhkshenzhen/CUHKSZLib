#ifndef CUHKSZ_CONTAINERS_VECTOR
#define CUHKSZ_CONTAINERS_VECTOR

#include <vector>

namespace cuhksz {

template <typename ValueType>
class vector {
public:

    vector();
    explicit vector(int n, ValueType value = ValueType());

    
    virtual ~vector();


    const ValueType& get(int index) const;


    ValueType& operator [](int index);
    const ValueType& operator [](int index) const;


    bool isEmpty() const;


    int size() const;

    void clear();

    void insert(int index, const ValueType& value);

    void erase(int index);

    void set(int index, const ValueType& value);

    void push(const ValueType& value);

    ValueType& pop();

    bool operator ==(const vector& v2);
    bool operator !=(const vector& v2);
    bool operator <(const vector& v2);
    bool operator <=(const vector& v2);
    bool operator >(const vector& v2);
    bool operator >=(const vector& v2);


    //Also has << and >> operator, will be defined at last.

    
private:
    std::vector<ValueType> vec;
};

//constructor
template <typename ValueType>
vector<ValueType>::vector() {

}

template <typename ValueType>
vector<ValueType>::vector(int n, ValueType value) {
    if (n == 0) {
        vec.clear();
    } else {
        for (int i = 0; i < n; i++) {
            vec.push_back(value);
        }
    }
}

template <typename ValueType>
const ValueType& vector<ValueType>::get(int index) const {
    return vec.at(index);
}

template <typename ValueType>
ValueType& vector<Valuetype>::operator [](int index) {
    return vec.at(index);
}

template <typename ValueType>
const ValueType& vector<Valuetype>::operator [](int index) const {
    return vec.at(index);
}

template <typename ValueType>
bool vector<Valuetype>::isEmpty() const {
    return vec.empty();
}

template <typename ValueType>
int vector<Valuetype>::size() const {
    return vec.size();
}

template <typename ValueType>
void vector<Valuetype>::clear() {
    vec.clear();
}

template <typename ValueType>
void vector<Valuetype>::insert(int index, const ValueType& value) {
    std::iterator begin = vec.begin();
    vec.insert(begin + index, value);
}

template <typename ValueType>
void vector<Valuetype>::erase(int index) {
    std::iterator begin = vec.begin();
    vec.erase(begin + index);
}

template <typename ValueType>
void vector<Valuetype>::set(int index, const ValueType& value) {
    std::iterator begin = vec.begin();
    std::iterator followingElement;
    followingElement = vec.erase(begin + index);
    vec.insert(followingElement, value);
}

template <typename ValueType>   
void vector<Valuetype>::push(const ValueType& value) {
    vec.push_back(value);
}

template <typename ValueType>
ValueType& vector<Valuetype>::pop() {
    Valuetype lastElement = vec.back();
    vec.pop_back();
    return lastElement;
}

template <typename ValueType>
bool vector<Valuetype>::operator ==(const vector& v2) {
    return 
}

template <typename ValueType>
bool operator !=(const vector& v2);

template <typename ValueType>
bool operator <(const vector& v2);

template <typename ValueType>
bool operator <=(const vector& v2);

template <typename ValueType>
bool operator >(const vector& v2);

template <typename ValueType>
bool operator >=(const vector& v2);

} // end namespace cuhksz

#endif
