#ifndef CUHKSZ_CONTAINERS_MAP
#define CUHKSZ_CONTAINERS_MAP

#include <map>
#include <utility>

namespace cuhksz {

template <typename KeyType, typename ValueType>
class Map {
public:
	typedef std::pair<const KeyType, ValueType> StdValueType;
	Map();
	Map(const Map& other);
	Map( std::initializer_list<StdValueType> init );

	~Map();

	Map& operator =(Map& map2);

	ValueType& get(const KeyType& key);
	const ValueType& get(const KeyType& key) const;

	ValueType& operator [](const KeyType& key);

	bool isEmpty() const;

	int size() const;

	void clear();

	void erase(const KeyType& key);

	bool contains(const KeyType& key);

	typedef typename std::map<KeyType, ValueType>::iterator iterator;
	typedef typename std::map<KeyType, ValueType>::const_iterator const_iterator;

	iterator begin() {
		return privateMap.begin();
	}
	const_iterator begin() const {
		return privateMap.begin();
	}

	iterator end() {
		return privateMap.end();
	}
	const_iterator end() const {
		return privateMap.end();
	}

	std::map<KeyType, ValueType> toStlMap(const Map& originMap);

	bool operator ==(const Map& map2);
    bool operator !=(const Map& map2);
    bool operator <(const Map& map2);
    bool operator <=(const Map& map2);
    bool operator >(const Map& map2);
    bool operator >=(const Map& map2);

private:
	std::map<KeyType, ValueType> privateMap;

};

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map(){
	//do nothing
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map(const Map& other) {
	privateMap = other.privateMap;
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map( std::initializer_list<StdValueType> init ) {
	privateMap = init;
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::~Map() {
	//do nothing
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>&
Map<KeyType, ValueType>::operator =(Map& map2) {
	privateMap = map2.privateMap;
	return *this;
}

template <typename KeyType, typename ValueType>
ValueType& Map<KeyType, ValueType>::get(const KeyType& key) {
	return privateMap.at(key);
}

template <typename KeyType, typename ValueType>
const ValueType& Map<KeyType, ValueType>::get(const KeyType& key) const {
	return privateMap.at(key);
}

template <typename KeyType, typename ValueType>
ValueType& Map<KeyType, ValueType>::operator [](const KeyType& key) {
	return privateMap.at(key);
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::isEmpty() const {
	return privateMap.empty();
}

template <typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::size() const {
	return privateMap.size();
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::clear() {
	privateMap.clear();
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::erase(const KeyType& key) {
	privateMap.erase(key);
}

template <typename KeyType, typename ValueType>
std::map<KeyType, ValueType>
Map<KeyType, ValueType>::toStlMap(const Map& originMap) {
	return originMap.privateMap;
}


template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::contains(const KeyType& key) {
	return (privateMap.find(key) != privateMap.end())? true : false;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator ==(const Map& map2) {
    return privateMap == map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator !=(const Map& map2) {
  return privateMap != map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator <(const Map& map2) {
  return privateMap < map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator <=(const Map& map2) {
  return privateMap <= map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator >(const Map& map2) {
  return privateMap > map2.privateMap;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::operator >=(const Map& map2) {
  return privateMap >= map2.privateMap;
}

} //end namespace

#endif //CUHKSZ_CONTAINERS_MAP
