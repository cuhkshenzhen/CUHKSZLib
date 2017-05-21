#ifndef CUHKSZ_GRAPH_SEGMENT_TREE
#define CUHKSZ_GRAPH_SEGMENT_TREE

#include <vector>
#include <algorithm>

namespace cuhksz {

template <typename ValueType>
class SegmentTree {
public:
    SegmentTree(std::vector<ValueType>& v);

    void init(std::vector<ValueType>& v, int l, int r, int o);
    ValueType queryMax(int lv, int rv);
    ValueType queryMax(int lv, int rv, int l, int r, int o);
    ValueType queryMin(int lv, int rv);
    ValueType queryMin(int lv, int rv, int l, int r, int o);
    ValueType querySum(int lv, int rv);
    ValueType querySum(int lv, int rv, int l, int r, int o);
    void addInterval(int lv, int rv, ValueType x);
    void addInterval(int lv, int rv, ValueType x, int l, int r, int o);
    void mulInterval(int lv, int rv, ValueType x);
    void mulInterval(int lv, int rv, ValueType x, int l, int r, int o);

// private:
    std::vector<ValueType> minVal;
    std::vector<ValueType> maxVal;
    std::vector<ValueType> sumVal;
    std::vector<ValueType> addFlag;
    std::vector<ValueType> mulFlag;
    std::vector<bool> hasAddFlag;
    std::vector<bool> hasMulFlag;
    int size;

    void update(int o, int l, int r);
};

template <typename ValueType>
SegmentTree<ValueType>::SegmentTree(std::vector<ValueType>& v) {
    size = v.size();
    for (int i = 0; i < size * 3; i ++) {
        minVal.push_back(v[0]);
        maxVal.push_back(v[0]);
        sumVal.push_back(v[0]);
        hasAddFlag.push_back(false);
        hasMulFlag.push_back(false);
    }
    init(v, 0, size - 1, 1);
}

template <typename ValueType>
void SegmentTree<ValueType>::init(std::vector<ValueType>& v, int l, int r, int o) {
    if (l == r) {
        minVal[o] = v[l];
        maxVal[o] = v[l];
        sumVal[o] = v[l];
        hasAddFlag[o] = hasMulFlag[o] = false;
        return;
    }
    int mid = (l + r) >> 1;
    int ls = o << 1, rs = (o << 1) | 1;
    init(v, l, mid, ls);
    init(v, mid + 1, r, rs);
    minVal[o] = std::min(minVal[ls], minVal[rs]);
    maxVal[o] = std::max(maxVal[ls], maxVal[rs]);
    sumVal[o] = sumVal[ls] + sumVal[rs];
}

template <typename ValueType>
void SegmentTree<ValueType>::update(int o, int l, int r) {
    int ls = o << 1, rs = (o << 1) | 1;
    if (hasMulFlag[o]) {
        hasMulFlag[o] = false;
        minVal[o] *= mulFlag[o];
        maxVal[o] *= mulFlag[o];
        sumVal[o] *= mulFlag[o];
        if (hasMulFlag[ls])
            mulFlag[ls] *= mulFlag[o];
        else {
            hasMulFlag[ls] = true;
            mulFlag[ls] = mulFlag[o];
        }
        if (hasAddFlag[ls])
            addFlag[ls] *= mulFlag[o];

        if (hasMulFlag[rs])
            mulFlag[rs] *= mulFlag[o];
        else {
            hasMulFlag[rs] = true;
            mulFlag[rs] = mulFlag[o];
        }
        if (hasAddFlag[rs])
            addFlag[rs] *= mulFlag[o];
    }

    if (hasAddFlag[o]) {
        hasAddFlag[o] = false;
        minVal[o] += addFlag[o];
        maxVal[o] += addFlag[o];
        sumVal[o] += addFlag[o] * (r - l + 1);
        if (hasAddFlag[ls])
            addFlag[ls] += addFlag[o];
        else {
            hasAddFlag[ls] = true;
            addFlag[ls] = addFlag[o];
        }
        if (hasAddFlag[rs])
            addFlag[rs] += addFlag[o];
        else {
            hasAddFlag[rs] = true;
            addFlag[rs] = addFlag[o];
        }
    }

}


template <typename ValueType>
ValueType SegmentTree<ValueType>::queryMax(int lv, int rv) {
    return queryMax(lv, rv, 0, size - 1, 1);
}


template <typename ValueType>
ValueType SegmentTree<ValueType>::queryMax(int lv, int rv, int l, int r, int o) {
    update(o, l, r);
    if (lv <= l && rv >= r)
        return maxVal[o];
    int mid = (l + r) >> 1;
    int ls = o << 1, rs = (o << 1) | 1;
    if (rv <= mid) return queryMax(lv, rv, l, mid, ls);
    if (lv > mid) return queryMax(lv, rv, mid + 1, r, rs);
    return std::max(queryMax(lv, rv, l, mid, ls), queryMax(lv, rv, mid + 1, r, rs));
}

template <typename ValueType>
ValueType SegmentTree<ValueType>::queryMin(int lv, int rv) {
    return queryMin(lv, rv, 0, size - 1, 1);
}

template <typename ValueType>
ValueType SegmentTree<ValueType>::queryMin(int lv, int rv, int l, int r, int o) {
    update(o, l, r);
    if (lv <= l && rv >= r)
        return minVal[o];
    int mid = (l + r) >> 1;
    int ls = o << 1, rs = (o << 1) | 1;
    if (rv <= mid) return queryMin(lv, rv, l, mid, ls);
    if (lv > mid) return queryMin(lv, rv, mid + 1, r, rs);
    return std::min(queryMin(lv, rv, l, mid, ls), queryMin(lv, rv, mid + 1, r, rs));
}

template <typename ValueType>
ValueType SegmentTree<ValueType>::querySum(int lv, int rv) {
    return querySum(lv, rv, 0, size - 1, 1);
}

template <typename ValueType>
ValueType SegmentTree<ValueType>::querySum(int lv, int rv, int l, int r, int o) {
    update(o, l, r);
    if (lv <= l && rv >= r)
        return sumVal[o];
    int mid = (l + r) >> 1;
    int ls = o << 1, rs = (o << 1) | 1;
    if (rv <= mid) return querySum(lv, rv, l, mid, ls);
    if (lv > mid) return querySum(lv, rv, mid + 1, r, rs);
    return querySum(lv, rv, l, mid, ls) + querySum(lv, rv, mid + 1, r, rs);
}

template <typename ValueType>
void SegmentTree<ValueType>::addInterval(int lv, int rv, ValueType x) {
    addInterval(lv, rv, x, 0, size - 1, 1);
}

template <typename ValueType>
void SegmentTree<ValueType>::addInterval(int lv, int rv, ValueType x, int l, int r, int o) {
    update(o, l, r);
    if (lv <= l && rv >= r) {
        addFlag[o] = x;
        hasAddFlag[o] = true;
        return;
    }
    int mid = (l + r) >> 1;
    int ls = o << 1, rs = (o << 1) | 1;
    if (lv <= mid) addInterval(lv, rv, x, l, mid, ls);
    if (rv > mid) addInterval(lv, rv, x, mid + 1, r, rs);
}


template <typename ValueType>
void SegmentTree<ValueType>::mulInterval(int lv, int rv, ValueType x) {
    mulInterval(lv, rv, x, 0, size - 1, 1);
}


template <typename ValueType>
void SegmentTree<ValueType>::mulInterval(int lv, int rv, ValueType x, int l, int r, int o) {
    update(o, l, r);
    if (lv <= l && rv >= r) {
        mulFlag[o] = x;
        hasMulFlag[o] = true;
        return;
    }
    int mid = (l + r) >> 1;
    int ls = o << 1, rs = (o << 1) | 1;
    if (lv <= mid) mulInterval(lv, rv, x, l, mid, ls);
    if (rv > mid) mulInterval(lv, rv, x, mid + 1, r, rs);
}

}

#endif // CUHKSZ_GRAPH_SEGMENT_TREE
