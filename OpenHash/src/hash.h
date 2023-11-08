#ifndef __HASH_H__
#define __HASH_H__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// 类模板声明和定义要写在一起
template<typename KeyType, typename ValueType>
class OpenHashTable {
private:
    struct Entry {
        KeyType key;
        ValueType value;
        bool occupied;

        Entry() : occupied(false) {}
    };

public:
    std::vector<Entry> table;
    size_t capacity;
    size_t size;

    size_t HashFunction(const KeyType& key) const {
        // 哈希函数示例，可以根据需要进行修改
        return std::hash<KeyType>{}(key) % capacity;
    }

public:
    OpenHashTable(size_t initialCapacity = 100) : capacity(initialCapacity), size(0) {
        table.resize(capacity);
    }

    bool Insert(const KeyType& key, const ValueType& value) {
        if(size == capacity - 1) {      // 避免插满，否则在search函数会造成无限查询
            return false;
        }
        size_t index = HashFunction(key);

        while (table[index].occupied) {
            if (table[index].key == key) {
                // 键已存在，更新值
                table[index].value = value;
                return true;
            }

            index = (index + 1) % capacity; // 线性探测寻找下一个空槽
            
        }

        // 找到空槽，插入新的键值对
        table[index].key = key;
        table[index].value = value;
        table[index].occupied = true;
        size++;
        
        return true;        
    }

    bool Search(const KeyType& key, ValueType& value) const {
        size_t index = HashFunction(key);

        while (table[index].occupied) {
            if (table[index].key == key) {
                value = table[index].value;
                return true; // 键找到
            }
            index = (index + 1) % capacity; // 线性探测寻找下一个槽

        }
        return false; // 键不存在
    }

    bool Remove(const KeyType& key) {
        size_t index = HashFunction(key);

        while (table[index].occupied) {
            if (table[index].key == key) {
                table[index].occupied = false;
                size--;
                return true; // 键删除成功
            }

            index = (index + 1) % capacity; // 线性探测寻找下一个槽
        }

        return false; // 键不存在
    }

    size_t Size() const {
        return size;
    }
};


std::pair<std::string, std::string> splitString(const std::string& str, char delimiter);

int addFromFile(OpenHashTable<std::string, std::string> *hash);


#endif