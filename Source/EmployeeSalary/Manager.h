#pragma once
class Manager :public Employment {
protected:
    long long _payment;
    long long _fixedpayment;
    long long _inChargeEmployment;
    string  _Name;
public:
    Manager();
        
    Manager(long long, long long);
   
    void setPayment(long long);
    void  setfixedPayment(long long);
    void setinChargeEmployee(long long);
    void setName(string);
    shared_ptr<Employment> clone();
    long long Salary();
    string toString();
};