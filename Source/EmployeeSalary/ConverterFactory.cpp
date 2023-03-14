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
shared_ptr<Employment> DailyConverter::convertback(string x, string temp) {

    auto Factory = EmploymentFactory::instance();
    int colon = x.find(':');
    string Type = x.substr(0, colon);
    string Name = x.substr(colon + 2, x.size() - colon - 2);


    int equal = temp.find('=');
    int semicolon = temp.find(';');
    int dollarsign = temp.find('$');
    long long  payment = stoll(temp.substr(equal + 1, dollarsign - equal - 1));
    temp = temp.substr(semicolon + 2, temp.size() - semicolon - 2);
    equal = temp.find('=');
    long long TotalDays = stoll(temp.substr(equal + 1, temp.size() - equal - 1));
    shared_ptr<Employment> t = Factory->create(Type);
    shared_ptr<DailyEmployee> e = dynamic_pointer_cast<DailyEmployee>(t);
    e->setDay(TotalDays);
    e->setName(Name);
    e->setPayment(payment);
    return  t;
}
shared_ptr<Employment> HourlyConverter::convertback(string x, string temp) {
    auto Factory = EmploymentFactory::instance();
    int colon = x.find(':');
    string Type = x.substr(0, colon);
    string Name = x.substr(colon + 2, x.size() - colon - 2);


    int equal = temp.find('=');
    int semicolon = temp.find(';');
    int dollarsign = temp.find('$');
    long long  payment = stoll(temp.substr(equal + 1, dollarsign - equal - 1));
    temp = temp.substr(semicolon + 2, temp.size() - semicolon - 2);
    equal = temp.find('=');
    long long TotalDays = stoll(temp.substr(equal + 1, temp.size() - equal - 1));
    shared_ptr<Employment> t = Factory->create(Type);
    shared_ptr<HourlyEmployee> e = dynamic_pointer_cast<HourlyEmployee>(t);
    e->setHour(TotalDays);
    e->setName(Name);
    e->setPayment(payment);
    return  t;
}
shared_ptr<Employment> ProductConverter::convertback(string x, string temp) {
    auto Factory = EmploymentFactory::instance();
    int colon = x.find(':');
    string Type = x.substr(0, colon);
    string Name = x.substr(colon + 2, x.size() - colon - 2);


    int equal = temp.find('=');
    int semicolon = temp.find(';');
    int dollarsign = temp.find('$');
    long long  payment = stoll(temp.substr(equal + 1, dollarsign - equal - 1));
    temp = temp.substr(semicolon + 2, temp.size() - semicolon - 2);
    equal = temp.find('=');
    long long TotalDays = stoll(temp.substr(equal + 1, temp.size() - equal - 1));
    shared_ptr<Employment> t = Factory->create(Type);
    shared_ptr<ProductEmployee> e = dynamic_pointer_cast<ProductEmployee>(t);
    e->setTotalProduct(TotalDays);
    e->setName(Name);
    e->setPayment(payment);
    return  t;
}
shared_ptr<Employment> ManagerConverter::convertback(string x, string temp) {
    auto Factory = EmploymentFactory::instance();
    int colon = x.find(':');
    string Type = x.substr(0, colon);
    string Name = x.substr(colon + 2, x.size() - colon - 2);
    int equal = temp.find('=');
    int semicolon = temp.find(';');
    int dollarsign = temp.find('$');
    long long  fixedpayment = stoll(temp.substr(equal + 1, dollarsign - equal - 1));
    temp = temp.substr(semicolon + 2, temp.size() - semicolon - 2);
    equal = temp.find('=');
    semicolon = temp.find(';');
    dollarsign = temp.find('$');
    long long  TotalEmployee = stoll(temp.substr(equal + 1, temp.size() - equal - 1));
    temp = temp.substr(semicolon + 2, temp.size() - semicolon - 2);
    equal = temp.find('=');
    dollarsign = temp.find('$');
    long long PaymentPerEmployee = stoll(temp.substr(equal + 1, dollarsign - equal - 1));
    shared_ptr<Employment> t = Factory->create(Type);
    shared_ptr<Manager> e = dynamic_pointer_cast<Manager>(t);
    e->setName(Name);
    e->setinChargeEmployee(TotalEmployee);
    e->setPayment(PaymentPerEmployee);
    e->setfixedPayment(fixedpayment);
    return t;

}

shared_ptr<converter> DailyConverter::clone()
{
    return make_shared<DailyConverter>();
}
shared_ptr<converter> HourlyConverter::clone()
{
    return make_shared<HourlyConverter>();
}
shared_ptr<converter> ProductConverter::clone()
{
    return make_shared<ProductConverter>();
}
shared_ptr<converter>  ManagerConverter::clone()
{
    return make_shared<ManagerConverter>();
}


