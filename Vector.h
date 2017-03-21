#ifndef CUHKSZ_CONTAINERS_VECTOR
#define CUHKSZ_CONTAINERS_VECTOR

#include <vector>

template <typename ValueType>
class vector {
public:
	vector();  //constructor
    explicit vector(int n, ValueType value = ValueType());
    

     
    virtual ~vector();

     
    void add(const ValueType& value);

     
    vector<ValueType>& addAll(const vector<ValueType>& v);

     
    void clear();
    
     
    bool equals(const vector<ValueType>& v) const;
    
     
    const ValueType& get(int index) const;
    
     
    void insert(int index, const ValueType& value);

     
    bool isEmpty() const;
    
     
    void mapAll(void (*fn)(ValueType)) const;
    void mapAll(void (*fn)(const ValueType&)) const;

    template <typename FunctorType>
    void mapAll(FunctorType fn) const;
    
     
    void push_back(const ValueType& value);

     
    void remove(int index);
    
     
    void set(int index, const ValueType& value);
    
     
    int size() const;
    
     
    vector<ValueType> subList(int start, int length) const;

     
    std::vector<ValueType> toStlVector() const;

     
    std::string toString() const;

     
    ValueType& operator [](int index);
    const ValueType& operator [](int index) const;

     
    vector operator +(const vector& v2) const;

     
    vector& operator +=(const vector& v2);
    vector& operator +=(const ValueType& value);


     
    bool operator ==(const vector& v2) const;

     
    bool operator !=(const vector& v2) const;

     
    bool operator <(const vector& v2) const;
    bool operator <=(const vector& v2) const;
    bool operator >(const vector& v2) const;
    bool operator >=(const vector& v2) const;
}
