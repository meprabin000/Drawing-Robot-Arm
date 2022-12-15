#include "scheduleTask.h"

// constructors
ScheduleTask::ScheduleTask() {}

ScheduleTask::ScheduleTask(Task* task)
{
    this->_task = task;
}

ScheduleTask::ScheduleTask( std::tm startTime, std::tm endTime, Task* task, std::string day): ScheduleTask::ScheduleTask(task)
{
    this->_startTime = startTime;
    this->_endTime = endTime;
    this->_day = day;
}

//destructors
ScheduleTask::~ScheduleTask()
{
    delete this->_task;
}

// getters
std::tm ScheduleTask::getStartTime()
{
    return this->_startTime;
}

std::tm ScheduleTask::getEndTime()
{
    return this->_endTime;
}

Task* ScheduleTask::getTask()
{
    return this->_task;
}
std::string ScheduleTask::getDayOfWeek()
{
    return this->_day;
}

// setters
void ScheduleTask::setStartTime(std::tm startTime)
{
    this->_startTime = startTime;
}

void ScheduleTask::setStartTime(int year, int month, int day, int hour, int minute)
{
    this->_startTime = Task::convertTime(year, month, day, hour, minute);
}

void ScheduleTask::setEndTime(std::tm endTime)
{
    this->_endTime = endTime;
}

void ScheduleTask::setEndTime(int year, int month, int day, int hour, int minute)
{
    this->_endTime = Task::convertTime(year, month, day, hour, minute);
}

void ScheduleTask::setTask(Task* task)
{
    this->_task = task;
}

void ScheduleTask::setDayOfWeek(std::string dayOfWeek)
{
    this->_day = dayOfWeek;
}

std::ostream& operator<<(std::ostream &os, const ScheduleTask& s)
{
    return os << std::setw(50) << s._task->getName() << std::endl;
}
