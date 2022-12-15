#include "todos.h"

/*
int nextTaskId;
std::list<ScheduleTask>* scheduledTasks;
*/

Todos::Todos()
{
    this->nextTaskId = 0;
    this->scheduledTasks = new std::list<ScheduleTask*>();
}

int Todos::getTaskCount()
{
    return this->scheduledTasks->size();
}

// returns the next task in the schedule queue
ScheduleTask* Todos::getNextTask()
{
    if(!this->scheduledTasks->empty())
        return this->scheduledTasks->front();
    else return nullptr;
}

void Todos::addTask(std::string name, int expectedCompletionTimeInMin)
{
    ScheduleTask* newScheduleTask = new ScheduleTask();
    newScheduleTask->setTask(new Task(++(this->nextTaskId), name, expectedCompletionTimeInMin));
    this->scheduledTasks->push_back(newScheduleTask);
}

void Todos::addTask(std::string name, int expectedCompletionTimeInMin, std::tm deadline)
{
    ScheduleTask* newScheduleTask = new ScheduleTask();
    newScheduleTask->setTask(new Task(++(this->nextTaskId), name, expectedCompletionTimeInMin, deadline));
    this->scheduledTasks->push_back(newScheduleTask);
}

void Todos::addTask(Task* task)
{
    ScheduleTask* newScheduleTask = new ScheduleTask();
    newScheduleTask->setTask(task);
    this->scheduledTasks->push_back(newScheduleTask);
}

void Todos::generateAWeekSchedule()
{
    throw "Not Implemented";
}

void Todos::getTodaySchedule()
{
    throw "Not Implemented";
}

void Todos::updateDeadline(ScheduleTask* t, std::tm deadline)
{
    t->getTask()->setDeadline(deadline);
}

void Todos::removeTask(ScheduleTask* task)
{
    this->scheduledTasks->remove(task);
    delete task;
}

void Todos::displayTodos()
{
    int i = 1;
    for( auto it = this->scheduledTasks->begin(); it != this->scheduledTasks->end(); ++it )
    {
        std::cout << std::setw(4) << std::left << i++ << ". " << std::setw(20) <<  **it;
    }

}