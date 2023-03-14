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
#include "HourlyEmployee.h"
HourlyEmployee::HourlyEmployee() {
    _payment = 0;
    _HoursWorked = 0;
    _Name = "";
}
HourlyEmployee::HourlyEmployee(long long payment, long long  dw)
{
    this->_payment = payment;
    this->_HoursWorked = dw;
}
void HourlyEmployee::setPayment(long long payment) { this->_payment = payment; }
void HourlyEmployee::setHour(long long dw) { this->_HoursWorked = dw; }
void HourlyEmployee::setName(string  n) { this->_Name = n; }
shared_ptr<Employment> HourlyEmployee::clone() {
    return make_shared<HourlyEmployee>();
}
long long HourlyEmployee::Salary() {
    return _payment * _HoursWorked;
}
string HourlyEmployee::toString() {
    stringstream out;
    out << "HourlyEmployee: " << _Name << endl;
    out << "   HourlyPayment=" << _payment << "$; TotalHours=" << _HoursWorked;
    string res;
    res = out.str();
    return res;
}