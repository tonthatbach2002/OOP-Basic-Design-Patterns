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
#include "Employment.h"
#include "DailyEmployee.h"

DailyEmployee::DailyEmployee() {
    _payment = 0;
    _DaysWorked = 0;
    _Name = "";
}
DailyEmployee::DailyEmployee(long long payment, long long  dw)
{
    this->_payment = payment;
    this->_DaysWorked = dw;
}
void DailyEmployee::setPayment(long long payment) { this->_payment = payment; }
void DailyEmployee::setDay(long long dw) { this->_DaysWorked = dw; }
void DailyEmployee::setName(string  n) { this->_Name = n; }
shared_ptr<Employment> DailyEmployee::clone() {
    return make_shared<DailyEmployee>();
}
long long DailyEmployee::Salary() {
    return _payment * _DaysWorked;
}
string DailyEmployee::toString() {
    stringstream out;
    out << "DailyEmployee: " << _Name << endl;
    out << "   DailyPayment=" << _payment << "$; TotalDays=" << _DaysWorked;
    string res;
    res = out.str();
    return res;
}