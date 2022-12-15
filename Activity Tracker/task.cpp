#include "task.h"

// constructors

Task::Task() {}

Task::Task(int id, std::string name, int expectedCompletionTimeInMin)
{
    this->id = id;
    this->_name = name;
    this->_expectedCompletionTimeInMin = expectedCompletionTimeInMin;
    this->setDeadline();
}

Task::Task(int id, std::string name, int expectedCompletionTimeInMin, std::tm deadline) : Task::Task(id, name, expectedCompletionTimeInMin)
{
    this->setDeadline(deadline);
}

// getters
std::string Task::getName()
{
    return this->_name;
}

std::tm Task::getDeadline()
{
    return this->_deadline;
}

Tag* Task::getAllTags()
{
    return this->_tags;
}  

bool Task::containsTag(Tag t)
{
    for( Tag tag : this->_tags )
    {
        if( t == tag )
            return true;
    }
    return false;
}

TaskStatus Task::getTaskStatus()
{
    return this->_taskStatus;
}  

// setters

void Task::setDeadline()
{
    this->_deadline = Task::getCurrentTime();
}

void Task::setDeadline(std::tm deadline)
{
    this->_deadline = deadline;
}

void Task::setDeadline(int year, int month, int mday, int hour, int min)
{
    this->_deadline = Task::convertTime(year, month,  mday, hour, min);
}

void Task::setName(std::string name)
{
    this->_name = name;
}

void Task::setExpectedCompletionTimeInMin(int expectedCompletionTimeInMin)
{
    this->_expectedCompletionTimeInMin = expectedCompletionTimeInMin;
}

void Task::setTaskStatus(TaskStatus taskStatus)
{
    this->_taskStatus = taskStatus;
}

// other methods
void Task::addTimeSpent(int timeSpent)
{
    this->_timeSpent += timeSpent;
}

//static methods
std::tm Task::convertTime(int year, int month, int mday, int hour, int min)
{
    std::tm tmObj = {};
    tmObj.tm_year = year - 1900;
    tmObj.tm_mon = month - 1;
    tmObj.tm_mday = mday - 1;
    tmObj.tm_hour = hour;
    tmObj.tm_min = min;
    return tmObj;
}

std::tm Task::getCurrentTime()
{
    std::time_t now = time(nullptr);
    return *(std::localtime(&now));
}