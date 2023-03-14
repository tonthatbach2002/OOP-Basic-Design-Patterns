#pragma once
class DataReader {
private:
    string _filename;
public:
    DataReader();
   
    DataReader(string);
   
public:
    vector <shared_ptr<Employment>> all();
};