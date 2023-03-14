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



EmploymentFactory::EmploymentFactory() {
    auto e1 = make_shared<DailyEmployee>();
    auto e2 = make_shared<HourlyEmployee>();
    auto e3 = make_shared<ProductEmployee>();
    auto e4 = make_shared<Manager>();

    _prototypes.insert({ "DailyEmployee",e1 });
    _prototypes.insert({ "HourlyEmployee",e2 });
    _prototypes.insert({ "ProductEmployee",e3 });
    _prototypes.insert({ "Manager",e4 });
}
    shared_ptr<EmploymentFactory>  EmploymentFactory::instance() {
    if (_setFactory == NULL) {
        auto temp = new EmploymentFactory();
        _setFactory = make_shared<EmploymentFactory>(*temp);
    }
    return _setFactory;
}
          
    shared_ptr<Employment> EmploymentFactory::create(string choice) {
        if (choice == "DailyEmployee")
        {
            shared_ptr<Employment> prototype = _prototypes[choice]->clone();
            return prototype;

        }
        if (choice == "HourlyEmployee")
        {
            shared_ptr<Employment> prototype = _prototypes[choice]->clone();
            return prototype;

        }
        if (choice == "ProductEmployee")
        {
            shared_ptr<Employment> prototype = _prototypes[choice]->clone();
            return prototype;

        }
        if (choice == "Manager")
        {
            shared_ptr<Employment> prototype = _prototypes[choice]->clone();
            return prototype;

        }
    }