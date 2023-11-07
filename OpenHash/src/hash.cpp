/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-11-06 11:34:11
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-11-06 18:32:06
 * @FilePath: /data-structures-and-algorithms/DataStruct/hash.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "hash.h"

std::pair<std::string, std::string> splitString(const std::string& str, char delimiter) {
    std::size_t pos = str.find(delimiter);
    if (pos == std::string::npos) {
        // 如果找不到分隔符，返回原始字符串和一个空字符串
        return std::make_pair(str, "");
    }

    std::string first = str.substr(0, pos);  // 第一个子串
    std::string second = str.substr(pos + 1);  // 第二个子串

    return std::make_pair(first, second);
}

int addFromFile(OpenHashTable<std::string, std::string> *hash) {
    std::ifstream file("../resource/word.csv"); // 替换为你的CSV文件路径

    if (!file.is_open()) {
        std::cout << "无法打开文件\n";
        return 1;
    }
    std::cout << "打开成功!\n";

    std::vector<std::string> words;
    std::vector<std::string> trans;

    std::string line;
    while (std::getline(file,line)) {

        std::pair<std::string, std::string>word_trans;
        word_trans = splitString(line, ',');
        
        words.push_back(word_trans.first);
        trans.push_back(word_trans.second);

    }

    file.close();

    for(int i=0; i<words.size(); i++) {
        hash->Insert(words.at(i), trans.at(i));
    }

    return 0;
}

#if 0
int main() {
    OpenHashTable<std::string, std::string> dictionary(10000);

    addFromFile(&dictionary);

    // 向字典插入词汇
    dictionary.Insert("apple", "苹果");
    dictionary.Insert("banana", "香蕉");
    dictionary.Insert("car", "汽车");
    // ...

    // 搜索词汇
    std::string value;
    if (dictionary.Search("about", value)) {
        std::cout << "中文翻译：" << value << std::endl;
    } else {
        std::cout << "未找到该词汇" << std::endl;
    }
    if (dictionary.Search("abstract", value)) {
        std::cout << "中文翻译：" << value << std::endl;
    } else {
        std::cout << "未找到该词汇" << std::endl;
    }
    if (dictionary.Search("thaw", value)) {
        std::cout << "中文翻译：" << value << std::endl;
    } else {
        std::cout << "未找到该词汇" << std::endl;
    }
    if (dictionary.Search("apple", value)) {
        std::cout << "中文翻译：" << value << std::endl;
    } else {
        std::cout << "未找到该词汇" << std::endl;
    }


    // 删除词汇
    if (dictionary.Remove("active")) {
        std::cout << "删除成功" << std::endl;
    } else {
        std::cout << "删除失败" << std::endl;
    }

    // 输出字典大小
    std::cout << "字典大小：" << dictionary.Size() << std::endl;

    return 0;
}
#endif