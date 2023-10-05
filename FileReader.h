//
// Created by Ethan Wong on 3/23/23.
//

#ifndef CS008MIDTERMPROJECT_FILEREADER_H
#define CS008MIDTERMPROJECT_FILEREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Word.h"

template <typename T>
class FileReader {
private:
    std::vector<T> data;
public:
    FileReader();
    FileReader(std::string filename);

    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    int size();
    const T& at(int pos);
};

#include "FileReader.cpp"

#endif //CS008MIDTERMPROJECT_FILEREADER_H
