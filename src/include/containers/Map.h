#ifndef CUHKSZ_CONTAINERS_MAP
#define CUHKSZ_CONTAINERS_MAP

#include <map>
#include <utility>
#include <set>

using std::set

namespace cuhksz {

template <typename KeyType, typename ValueType>
class Map {
public:
	typedef std::pair<const KeyType, ValueType> StdValueType;
	Map();
	Map(const std::map<KeyType, ValueType>& other);
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

	typedef typename std::map<KeyType, ValueType>::iterator iterator;
	typedef typename std::map<KeyType, ValueType>::const_iterator const_iterator;

	iterator begin();
	const_iterator begin() const;

	iterator end();
	const_iterator end() const;

	set<ValueType>& find(const KeyType& key);

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
Map<KeyType, ValueType>::Map(const std::map<KeyType, ValueType>& other) {
	privateMap = other;
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
iterator Map<KeyType, ValueType>::begin() {
	return privateMap.begin();
}

template <typename KeyType, typename ValueType>
const_iterator Map<KeyType, ValueType>::begin() const {
	return privateMap.begin();
}

template <typename KeyType, typename ValueType>
iterator Map<KeyType, ValueType>::end() {
	return privateMap.end();
}

template <typename KeyType, typename ValueType>
const_iterator Map<KeyType, ValueType>::end() const {
	return privateMap.end();
}

template <typename KeyType, typename ValueType>
set<ValueType>& Map<KeyType, ValueType>::find(const KeyType& key) {
	static set<ValueType> valueSet;
	auto pairFound = privateMap.find(key);
	if (pariFound != privateMap.end()) {
		valueSet.insert(pariFound->second);
		return valueSet;
	}
	return valueSet;
}  

template <typename ValueType>
bool Map<ValueType>::operator ==(const Map& map2) {
    return privateMap == map2.privateMap;
}

template <typename ValueType>
bool Map<ValueType>::operator !=(const Map& map2) {
  return privateMap != map2.privateMap;
}

template <typename ValueType>
bool Map<ValueType>::operator <(const Map& map2) {
  return privateMap < map2.privateMap;
}

template <typename ValueType>
bool Map<ValueType>::operator <=(const Map& map2) {
  return privateMap <= map2.privateMap;
}

template <typename ValueType>
bool Map<ValueType>::operator >(const Map& map2) {
  return privateMap > map2.privateMap;
}

template <typename ValueType>
bool Map<ValueType>::operator >=(const Map& map2) {
  return privateMap >= map2.privateMap;
}

} //end namespace

#endif //CUHKSZ_CONTAINERS_MAP
