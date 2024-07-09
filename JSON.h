#pragma once

class JSON_value
{
    //value = false / null / true / object / array / number / string

};

class JSON_member
{
    char* name;
    JSON_value value;

public:
    JSON_member(char* _name, JSON_value _value):name(_name), value(_value){}
};