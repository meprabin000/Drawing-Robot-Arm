#pragma once

#include "task.h"
#include <iomanip>

class ScheduleTask
{
    private:
        std::tm _startTime;
        std::tm _endTime;
        Task* _task;
        std::string _day;
        bool scheduleStatus;

        std::tm setTime();

    public:
        // constructors
        ScheduleTask();
        ScheduleTask(Task* task);
        ScheduleTask( std::tm startTime, std::tm endTime, Task* task, std::string day);

        //destructor
        virtual ~ScheduleTask();

        // getters
        std::tm getStartTime();
        std::tm getEndTime();
        Task* getTask();
        std::string getDayOfWeek();

        // setters
        void setStartTime(std::tm startTime);
        void setStartTime(int year, int month, int day, int hour, int minute);
        void setEndTime(std::tm endTime);
        void setEndTime(int year, int month, int day, int hour, int minute);
        void setTask(Task* task);
        void setDayOfWeek(std::string dayOfWeek);

        friend std::ostream& operator<<(std::ostream &os, const ScheduleTask& s);


};