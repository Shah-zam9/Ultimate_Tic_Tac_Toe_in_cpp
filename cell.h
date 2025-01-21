#include<iostream>

class Cell
{
    char value;
    public:
    Cell()
    {
        value=' ';
    }
    bool setValue(char value)
    {
        this->value=value;
    }
    char getValue() const
    {
        return value;
    }
    bool operator==(Cell &other)
    {
        return value==other.value;
    }
};