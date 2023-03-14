#pragma once
class HourlyEmployee :public Employment {
protected:
    long long _payment;
    long long _HoursWorked;
    string  _Name;
public:
    HourlyEmployee();
        
    HourlyEmployee(long long, long long);
   
    void setPayment(long long);
    void setHour(long long);
    void setName(string);
    shared_ptr<Employment> clone();
    long long Salary();
    string toString();
};