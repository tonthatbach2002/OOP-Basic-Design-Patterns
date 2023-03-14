#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;
#include"Employment.h"
#include"DailyEmployee.h"
#include"HourlyEmployee.h"
#include"ProductEmployee.h"
#include"Manager.h"
#include"EmploymentFactory.h"
#include"ConverterFactory.h"
#include"DataReader.h"



DataReader::DataReader()
{

}
DataReader::DataReader(string filename)
{
    _filename = filename;
}

    vector <shared_ptr<Employment>> DataReader::all() {
        vector<shared_ptr<Employment>> list;
        
        auto Factory = converterFactory::instance();
        ifstream reader;
        reader.open(_filename);
        while (!reader.eof())
        {
            string x;
            getline(reader, x);
            int colon = x.find(':');
            string Type = x.substr(0, colon);

            string temp = "";
            getline(reader, temp);
            auto v = Factory->create(Type);
            list.push_back(v->convertback(x, temp));
           
        }
        return list;
    }