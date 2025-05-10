#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <ctime>
#include "BudgetManager.hpp"

// Helper functions
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printHeader(const std::string &title)
{
    std::cout << "\n===== " << title << " =====\n"
              << std::endl;
}

void waitForKey()
{
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

std::string categoryToString(Category category)
{
    switch (category)
    {
    case Category::SALARY:
        return "Salary";
    case Category::FOOD:
        return "Food";
    case Category::TRANSPORT:
        return "Transport";
    case Category::ENTERTAINMENT:
        return "Entertainment";
    case Category::UTILITIES:
        return "Utilities";
    case Category::RENT:
        return "Rent";
    case Category::OTHER:
        return "Other";
    default:
        return "Unknown";
    }
}

Category getCategoryFromUser()
{
    int choice = 0;
    std::cout << "Select category:\n"
              << "1. Salary\n"
              << "2. Food\n"
              << "3. Transport\n"
              << "4. Entertainment\n"
              << "5. Utilities\n"
              << "6. Rent\n"
              << "7. Other\n"
              << "Choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
        return Category::SALARY;
    case 2:
        return Category::FOOD;
    case 3:
        return Category::TRANSPORT;
    case 4:
        return Category::ENTERTAINMENT;
    case 5:
        return Category::UTILITIES;
    case 6:
        return Category::RENT;
    case 7:
        return Category::OTHER;
    default:
        std::cout << "Invalid choice, using 'Other'" << std::endl;
        return Category::OTHER;
    }
}

// Function prototypes
void showMainMenu(BudgetManager &manager);
void handleUserManagement(BudgetManager &manager);
void handleTransactions(BudgetManager &manager);
void handleReports(BudgetManager &manager);
void displayMonthlyReport(BudgetManager &manager);

int main()
{
    BudgetManager manager;

    std::cout << "Welcome to Personal Finance Tracker!" << std::endl;

    try
    {
        showMainMenu(manager);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Thanks for using Personal Finance Tracker!" << std::endl;
    return 0;
}

void showMainMenu(BudgetManager &manager)
{
    bool running = true;

    while (running)
    {
        clearScreen();
        printHeader("MAIN MENU");

        std::cout << "1. User Management\n"
                  << "2. Transactions\n"
                  << "3. Reports\n"
                  << "0. Exit\n"
                  << "Choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            handleUserManagement(manager);
            break;
        case 2:
            handleTransactions(manager);
            break;
        case 3:
            handleReports(manager);
            break;
        case 0:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            waitForKey();
        }
    }
}

void handleUserManagement(BudgetManager &manager)
{
    bool returning = false;

    while (!returning)
    {
        clearScreen();
        printHeader("USER MANAGEMENT");

        std::cout << "1. Create New User\n"
                  << "2. Load Existing User\n"
                  << "0. Back to Main Menu\n"
                  << "Choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            std::string name;
            double initialBalance;

            std::cout << "Enter username: ";
            std::getline(std::cin, name);

            std::cout << "Enter initial balance: ";
            std::cin >> initialBalance;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            try
            {
                manager.createUser(name, initialBalance);
                std::cout << "User created successfully!" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            waitForKey();
            break;
        }
        case 2:
        {
            std::string name;

            std::cout << "Enter username: ";
            std::getline(std::cin, name);

            try
            {
                manager.loadUser(name);
                std::cout << "User loaded successfully!" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            waitForKey();
            break;
        }
        case 0:
            returning = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            waitForKey();
        }
    }
}

void handleTransactions(BudgetManager &manager)
{
    bool returning = false;

    while (!returning)
    {
        clearScreen();
        printHeader("TRANSACTIONS");

        try
        {
            std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << manager.getCurrentBalance() << std::endl;
        }
        catch (const std::exception &)
        {
            std::cout << "No user loaded. Please load or create a user first." << std::endl;
            waitForKey();
            return;
        }

        std::cout << "\n1. Add Income\n"
                  << "2. Add Expense\n"
                  << "0. Back to Main Menu\n"
                  << "Choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            double amount;
            std::string description;

            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Category category = getCategoryFromUser();

            std::cout << "Enter description: ";
            std::getline(std::cin, description);

            try
            {
                manager.addIncome(amount, category, description);
                std::cout << "Income added successfully!" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            waitForKey();
            break;
        }
        case 2:
        {
            double amount;
            std::string description;

            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Category category = getCategoryFromUser();

            std::cout << "Enter description: ";
            std::getline(std::cin, description);

            try
            {
                manager.addExpense(amount, category, description);
                std::cout << "Expense added successfully!" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            waitForKey();
            break;
        }
        case 0:
            returning = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            waitForKey();
        }
    }
}

void handleReports(BudgetManager &manager)
{
    bool returning = false;

    while (!returning)
    {
        clearScreen();
        printHeader("REPORTS");

        std::cout << "1. Monthly Report\n"
                  << "2. Expenses by Category\n"
                  << "0. Back to Main Menu\n"
                  << "Choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            displayMonthlyReport(manager);
            break;
        case 2:
        {
            clearScreen();
            printHeader("EXPENSES BY CATEGORY");

            try
            {
                auto expenses = manager.getExpensesByCategory();

                if (expenses.empty())
                {
                    std::cout << "No expenses recorded yet." << std::endl;
                }
                else
                {
                    std::cout << std::left << std::setw(15) << "Category"
                              << std::right << std::setw(10) << "Amount" << std::endl;
                    std::cout << std::string(25, '-') << std::endl;

                    for (const auto &[category, amount] : expenses)
                    {
                        std::cout << std::left << std::setw(15) << categoryToString(category)
                                  << std::right << std::setw(10) << std::fixed << std::setprecision(2) << amount << std::endl;
                    }
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }

            waitForKey();
            break;
        }
        case 0:
            returning = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            waitForKey();
        }
    }
}

void displayMonthlyReport(BudgetManager &manager)
{
    clearScreen();
    printHeader("MONTHLY REPORT");

    int year, month;

    // Default to current month
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;

    std::cout << "Enter year (default: " << year << "): ";
    std::string input;
    std::getline(std::cin, input);
    if (!input.empty())
    {
        year = std::stoi(input);
    }

    std::cout << "Enter month (1-12) (default: " << month << "): ";
    std::getline(std::cin, input);
    if (!input.empty())
    {
        month = std::stoi(input);
        if (month < 1 || month > 12)
        {
            std::cout << "Invalid month. Using default." << std::endl;
            month = now->tm_mon + 1;
        }
    }

    try
    {
        double income = manager.getMonthlyIncome(year, month);
        double expenses = manager.getMonthlyExpenses(year, month);
        double balance = income - expenses;

        std::cout << "\nMonthly Report for " << year << "-" << std::setfill('0') << std::setw(2) << month << std::setfill(' ') << std::endl;
        std::cout << std::string(30, '-') << std::endl;
        std::cout << std::left << std::setw(15) << "Income:"
                  << std::right << std::setw(15) << std::fixed << std::setprecision(2) << income << std::endl;
        std::cout << std::left << std::setw(15) << "Expenses:"
                  << std::right << std::setw(15) << std::fixed << std::setprecision(2) << expenses << std::endl;
        std::cout << std::string(30, '-') << std::endl;
        std::cout << std::left << std::setw(15) << "Balance:"
                  << std::right << std::setw(15) << std::fixed << std::setprecision(2) << balance << std::endl;

        // Show expenses by category for this month
        auto monthlyExpensesByCategory = manager.getMonthlyExpensesByCategory(year, month);

        if (!monthlyExpensesByCategory.empty())
        {
            std::cout << "\nExpenses by Category:" << std::endl;
            std::cout << std::string(30, '-') << std::endl;

            for (const auto &[category, amount] : monthlyExpensesByCategory)
            {
                std::cout << std::left << std::setw(15) << categoryToString(category)
                          << std::right << std::setw(15) << std::fixed << std::setprecision(2) << amount << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    waitForKey();
}