#pragma once
class Employment {
public:
    virtual long long Salary() = 0;
    virtual string toString() { return ""; }
    virtual shared_ptr<Employment> clone() = 0;
};