#pragma once

#include "tag.h"
#include <ctime>

enum TaskStatus
{
    ACTIVE,
    NOTSTARTED,
    COMPLETE
};

class Task
{
    private:
        int id;
        std::tm _deadline;
        Tag _tags[MAX_NUM_TAGS];
        std::string _name;
        int _expectedCompletionTimeInMin;
        int _timeSpent;
        TaskStatus _taskStatus;
    public:
        // constructors
        Task();
        Task(int id, std::string name, int expectedCompletionTimeInMin);
        Task(int id, std::string name, int expectedCompletionTimeInMin, std::tm deadline);

        // getters
        std::string getName();
        std::tm getDeadline();
        Tag* getAllTags();   
        bool containsTag(Tag t);
        TaskStatus getTaskStatus();  

        // setters
        void setDeadline();
        void setDeadline(std::tm deadline);
        void setDeadline(int year, int month, int mday, int hour, int min);
        void setName(std::string name);
        void setExpectedCompletionTimeInMin(int expectedCompletionTimeInMin);
        void setTaskStatus(TaskStatus _taskStatus);

        // other methods
        void addTimeSpent(int timeSpent);
        
        // static methods
        static std::tm convertTime(int year, int month, int mday, int hour, int min);
        static std::tm getCurrentTime();
        

};