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
#include "ProductEmployee.h"
ProductEmployee::ProductEmployee() {
    _payment = 0;
    _ProductWorked = 0;
    _Name = "";
}
ProductEmployee::ProductEmployee(long long payment, long long  dw)
{
    this->_payment = payment;
    this->_ProductWorked = dw;
}
void ProductEmployee::setPayment(long long payment) { _payment = payment; }
void ProductEmployee::setTotalProduct(long long dw) { _ProductWorked = dw; }
void ProductEmployee::setName(string  n) { this->_Name = n; }
shared_ptr<Employment> ProductEmployee::clone() {
    return make_shared<ProductEmployee>();
}
long long ProductEmployee::Salary() {
    return _payment * _ProductWorked;
}
string ProductEmployee::toString() {
    stringstream out;
    out << "ProductEmployee: " << _Name << endl;
    out << "   PaymentPerProduct=" << _payment << "$; TotalProducts=" << _ProductWorked;
    string res;
    res = out.str();
    return res;
}
