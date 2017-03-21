#include <vector>
template <typename ValueType>
vector<ValueType>::vector() {
	count = capacity = 0;
    elements = NULL;
}

template <typename ValueType>
vector<ValueType>::vector(int n, ValueType value) {
    count = capacity = n;
    elements = (n == 0) ? NULL : new ValueType[n];
    for (int i = 0; i < n; i++) {
        elements[i] = value;
    }
}

