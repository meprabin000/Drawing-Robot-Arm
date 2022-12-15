#pragma once

#include "scheduleTask.h"
#include <list>

class Todos
{
    private:
        int nextTaskId;
        std::list<ScheduleTask*>* scheduledTasks;
    
    public:
        Todos();

        int getTaskCount();

        ScheduleTask* getNextTask();

        void addTask(Task* task);

        void addTask(std::string name, int expectedCompletionTimeInMin);

        void addTask(std::string name, int expectedCompletionTimeInMin, std::tm deadline);

        void generateAWeekSchedule();

        void getTodaySchedule();

        void updateDeadline(ScheduleTask* t, std::tm deadline);

        void removeTask(ScheduleTask* task);

        void displayTodos();
             

};