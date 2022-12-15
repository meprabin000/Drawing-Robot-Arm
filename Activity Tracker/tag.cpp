#include "tag.h"

Tag::Tag() {}

Tag::Tag(std::string name, int priority, int avgTimeSpent)
{
    this->_name = name;
    this->_priority = priority;
    this->_avgTimeSpent = avgTimeSpent;
}

std::string Tag::getTagName()
{
    return this->_name;
}


int Tag::getPriority()
{
    return this->_priority;
}

int Tag::getAvgTimeSpent()
{
    return this->_avgTimeSpent;
}

// setters
void Tag::setTagName(std::string name)
{
    this->_name = name;
}
void Tag::setPriority(int priority)
{
    this->_priority = priority;
}

void Tag::setAvgTimeSpent(int avgTimeSpent)
{
    this->_avgTimeSpent = avgTimeSpent;
}

//operators
bool Tag::operator==(Tag tag)
{
    return (this->_name == tag.getTagName() && this->_priority == tag.getPriority());
}