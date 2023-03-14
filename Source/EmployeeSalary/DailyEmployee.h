#pragma once
class DailyEmployee :public Employment {
protected:
    long long _payment;
    long long _DaysWorked;
    string  _Name;
public:
    DailyEmployee();
       
    DailyEmployee(long long, long long);
    
    void setPayment(long long);
        void setDay(long long);
        void setName(string);
        shared_ptr<Employment> clone();
   
        long long Salary();
       
        string toString();
        
    
};