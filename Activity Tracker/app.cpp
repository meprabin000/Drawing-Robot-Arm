#include "app.h"

App::App() 
{
    this->todos = new Todos();
}

int App::getSelectionInput()
{
    bool invalid = true;
    int selection;
    do
    {
        std::cout << "Enter your selection: ";
        selection = this->getIntegerInput();
        if( selection >= 0 && selection <= NUM_OF_OPTIONS )
            invalid = false;
        else
            std::cout << "Invalid Selection. Please enter a number between 0 and " << NUM_OF_OPTIONS << std::endl;
    } while (invalid);
    
    return selection;
}

void App::displayMainMenu()
{
    std::cout << "\n:::::::\tWELCOME TO AUTO PLANNER\t:::::::" << std::endl;
    std::cout << "\n";
    std::cout << "1. Add a task." << std::endl;
    std::cout << "2. Generate the schedule for today." << std::endl;
    std::cout << "3. View the schedule for today." << std::endl;
    std::cout << "4. View all tasks." << std::endl << std::endl;
    std::cout << "[enter 0 and press enter to quit]" << std::endl;
    std::cout << std::endl;
}

void App::addNewTask()
{
    std::string name, buffer;
    int expectedCompletionTimeInMin;
    std::tm deadline;
    
    std::cout << "Enter the name of the task: ";
    name = getStringInput();

    std::cout << "Enter the expected completion time (in min): ";
    expectedCompletionTimeInMin = getIntegerInput();

    std::cout << "Is there a deadline ? (y/n): ";
    buffer = this->getStringInput();
    if( buffer[0] == 'y' || buffer[0] == 'Y')
    {
        deadline = getDeadline();
        this->todos->addTask(name, expectedCompletionTimeInMin, deadline);
    }
    else
    {
        this->todos->addTask(name, expectedCompletionTimeInMin);
    }
    

    }

std::tm App::getDeadline()
{
    int year, month, day, hour, min;
    std::cout << "Please enter the deadline below: " << std::endl;
    std::cout << "Enter the year: ";
    year = getIntegerInput();
    std::cout << "Enter the month: ";
    month = getIntegerInput();
    std::cout << "Enter the day: ";
    day = getIntegerInput();
    std::cout << "Enter the hour (24-hour-scale): ";
    hour = getIntegerInput();
    std::cout << "Enter the minute: ";
    min = getIntegerInput();

    std::tm tempTm{};
    tempTm.tm_year = year;
    tempTm.tm_mon = month;
    tempTm.tm_mday = day;
    tempTm.tm_hour = hour;
    tempTm.tm_min = min;

    return tempTm;
}

std::string App::getStringInput()
{
    std::string buffer;
    try
    {
        std::getline( std::cin, buffer );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return buffer;
}

int App::getIntegerInput()
{

    char buffer[BUFFER_SIZE];
    int returnVal;
    bool invalid = true;
    while(invalid)
    {
        try
        {
            std::cin.getline( buffer, BUFFER_SIZE );
            returnVal = atoi(buffer);
            invalid = false;
        }
        catch(const std::exception& e)
        {
            std::cout << "(Integer conversion failed): Please enter the valid integer input: " << std::endl;
            
        }
    }
    
    return returnVal;
    
}

bool App::executeSelection(int selection)
{
    switch( selection )
    {
        case 0:
            return false;

        case 1:
            this->addNewTask();
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            this->todos->displayTodos();
            break;
    }

    return true;
}

void App::start()
{
    bool notQuit = true;
    while(notQuit)
    {
        this->displayMainMenu();
        int selection = this->getSelectionInput();
        notQuit = this->executeSelection( selection );
    }
    std::cout << "\nThanks for using the AUTO-PLANNER.\n" << std::endl;
}