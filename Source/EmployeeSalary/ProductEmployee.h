#pragma once
class ProductEmployee :public Employment {
protected:
    long long _payment;
    long long _ProductWorked;
    string  _Name;
public:
    ProductEmployee();
        
    ProductEmployee(long long, long long);

    void setPayment(long long);
    void setTotalProduct(long long);
    void setName(string);
    shared_ptr<Employment> clone();
    long long Salary();
    string toString();
};