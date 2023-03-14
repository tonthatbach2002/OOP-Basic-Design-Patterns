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

int main()
{
    DataReader Reader("November2021.txt");
    vector<shared_ptr<Employment>> list = Reader.all();
    for (int i = 0; i < list.size(); i++)
    {
        shared_ptr<Employment> temp = list[i];
        shared_ptr<DailyEmployee> c = dynamic_pointer_cast<DailyEmployee> (temp);
        if (c != NULL) {
            cout << c->toString() << " => " << "Final Payment=" << c->Salary() << "$" <<  endl;


        }
        shared_ptr<HourlyEmployee> t = dynamic_pointer_cast<HourlyEmployee> (temp);
        if (t != NULL) {
            cout << t->toString() << " => " << "Final Payment=" << t->Salary() << "$" << endl;


        }
        shared_ptr<ProductEmployee> r = dynamic_pointer_cast<ProductEmployee> (temp);
        if (r != NULL) {
            cout << r->toString() << " => " << "Final Payment=" << r->Salary()<<"$" << endl;


        }
        shared_ptr<Manager> o = dynamic_pointer_cast<Manager> (temp);
        if (o != NULL) {
            cout << o->toString() << " => " << "Final Payment=" << o->Salary() << "$" << endl;


        }
    }
    cin.get();
   

    
    
    

    
   
}

