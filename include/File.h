//File: File.h
//Author: Catherine Evans 

#ifndef FILE_H
#define FILE_H

template<class T>
struct File{
    std::string name;
    long unsigned int size;
    T data;

    //Default Constructor 
    File(): name(), size(), data() {}

    //Overloaded Constructor
    File( std::string nameIn, long unsigned int sizeIn, T dataIn) : name(nameIn), size(sizeIn), data(dataIn) {}
};

#endif