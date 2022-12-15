#pragma once

#include <iostream>
#include <string>

#define MAX_NUM_TAGS 10

class Tag
{
    private:
        std::string _name;
        int _priority;
        int _avgTimeSpent;
    public:

        // constructors
        Tag();
        Tag(std::string name, int priority, int avgTimeSpent);

        // getters
        std::string getTagName();
        int getPriority();
        int getAvgTimeSpent();

        // setters
        void setTagName(std::string name);
        void setPriority(int priority);
        void setAvgTimeSpent(int avgTimeSpent);

        // operators
        bool operator==(Tag t);

};