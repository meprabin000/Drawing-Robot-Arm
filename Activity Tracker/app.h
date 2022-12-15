#pragma once 

#include "todos.h"
#include <cstdlib>

#define NUM_OF_OPTIONS 4
#define BUFFER_SIZE 50


class App
{
    private:
        Todos* todos;
    public:
        App();
        int getSelectionInput();
        static int getIntegerInput();
        void addNewTask();
        static std::tm getDeadline();
        static std::string getStringInput();
        void displayMainMenu();
        void start();
        bool executeSelection(int selection);
};