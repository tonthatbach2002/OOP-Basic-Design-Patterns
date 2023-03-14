#pragma once
class converter {
public:
    virtual shared_ptr<Employment> convertback(string, string) = NULL;
    virtual shared_ptr<converter> clone() = NULL;

};
class DailyConverter :public converter
{
public:
    DailyConverter()
    {

    }
    shared_ptr<Employment> convertback(string, string);
    shared_ptr<converter> clone();
};
class HourlyConverter :public converter
{
public:
    HourlyConverter()
    {

    }
    shared_ptr<Employment> convertback(string, string);
    shared_ptr<converter> clone();
};
class ProductConverter :public converter
{
public:
    ProductConverter()
    {

    }
    shared_ptr<Employment> convertback(string, string);
    shared_ptr<converter> clone();
};
class ManagerConverter :public converter
{
public:
    ManagerConverter()
    {

    }
    shared_ptr<Employment> convertback(string, string);
    shared_ptr<converter> clone();
};
class converterFactory {

public:
    map<string, shared_ptr<converter>> _prototypes;
private:
    inline static shared_ptr<converterFactory> _setFactory = NULL;
    converterFactory()
    {

        _prototypes.insert({ "DailyEmployee",make_shared<DailyConverter>() });
        _prototypes.insert({ "HourlyEmployee",make_shared<HourlyConverter>() });
        _prototypes.insert({ "ProductEmployee",make_shared<ProductConverter>() });
        _prototypes.insert({ "Manager",make_shared<ManagerConverter>() });


    }

public:
    static shared_ptr<converterFactory> instance() {
        if (_setFactory == NULL)
        {
            converterFactory* temp = new converterFactory();
            _setFactory = make_shared<converterFactory>(*temp);

        }
        return _setFactory;
    }


    shared_ptr<converter> create(string type)
    {
        shared_ptr<converter> t = _prototypes[type]->clone();
        return t;
    }


};