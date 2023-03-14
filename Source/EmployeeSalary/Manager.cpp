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
#include "Manager.h"
Manager::Manager() {
    _payment = 0;
    _inChargeEmployment = 0;
    _Name = "";
}
Manager::Manager(long long payment, long long  dw)
{
    this->_payment = payment;
    this->_inChargeEmployment = dw;

}
void Manager::setPayment(long long payment) { this->_payment = payment; }
void  Manager::setfixedPayment(long long payment) { this->_fixedpayment = payment; }
void Manager::setinChargeEmployee(long long dw) { this->_inChargeEmployment = dw; }
void Manager::setName(string  n) { this->_Name = n; }
shared_ptr<Employment> Manager::clone() {
    return make_shared<Manager>();
}
long long Manager::Salary() {
    return _payment * _inChargeEmployment + _fixedpayment;
}
string Manager::toString() {
    stringstream out;
    out << "Manager: " << _Name << endl;
    out << "   FixedPayment=" << _fixedpayment << "$; TotalEmployees=" << _inChargeEmployment << "; PaymentPerEmployee=" << _payment << "$";
    string res;
    res = out.str();
    return res;
}
