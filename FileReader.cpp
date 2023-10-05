//
// Created by Ethan Wong on 3/23/23.
//

#ifndef CS008MIDTERMPROJECT_FILEREADER_CPP
#define CS008MIDTERMPROJECT_FILEREADER_CPP

#include "FileReader.h"

template<typename T>
FileReader<T>::FileReader() : FileReader("") {

}

template<typename T>
FileReader<T>::FileReader(std::string filename) {
    T info;
    std::fstream file(filename.c_str());
    if (file.is_open()) {
        while (file >> info)
        {
            data.push_back(info);
        }
        file.close();
    }
}

template<typename T>
typename std::vector<T, std::allocator<T>>::iterator FileReader<T>::begin() {
    return data.begin();
}

template<typename T>
typename std::vector<T, std::allocator<T>>::iterator FileReader<T>::end() {
    return data.end();
}

template<typename T>
int FileReader<T>::size() {
    return data.size();
}

template<typename T>
const T &FileReader<T>::at(int pos) {
    return data.at(pos);
}

#endif //CS008MIDTERMPROJECT_FILEREADER_CPP