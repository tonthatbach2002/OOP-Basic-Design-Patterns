#pragma once
class EmploymentFactory
{
public:
    map<string, shared_ptr<Employment>> _prototypes;
private:
    inline static shared_ptr<EmploymentFactory> _setFactory = NULL;
    EmploymentFactory();
    
public:
    static shared_ptr<EmploymentFactory> instance();


    shared_ptr<Employment> create(string);

};