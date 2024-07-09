#pragma once
#include<vector>

class JSON_member
{
    char* name;
    JSON_value value;

public:
    JSON_member(char* _name, JSON_value _value):name(_name), value(_value){}
};

class JSON_value
{
    //value = false / null / true / object / array / number / string
    enum TYPE{Spcial, Num, Str, Obj, Arr};
    TYPE valueType;

    JSON_value(TYPE _type):valueType(_type){};
};

class JSON_object
{
    std::vector<JSON_member> obj;
};

class JSON_array
{
    std::vector<JSON_value> arr;
};