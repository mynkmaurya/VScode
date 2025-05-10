#ifndef BUDGET_MANAGER_HPP
#define BUDGET_MANAGER_HPP

#include <memory>
#include <string>
#include <map>
#include "User.hpp"

class BudgetManager {
public:
    BudgetManager();

    // User management
    void createUser(const std::string& name, double initialBalance = 0.0);
    void loadUser(const std::string& name);
    void saveCurrentUser();
    
    // Transaction management
    void addIncome(double amount, Category category, const std::string& description);
    void addExpense(double amount, Category category, const std::string& description);
    
    // Budget analysis
    double getCurrentBalance() const;
    std::map<Category, double> getExpensesByCategory() const;
    std::map<Category, double> getMonthlyExpensesByCategory(int year, int month) const;
    double getMonthlyIncome(int year, int month) const;
    double getMonthlyExpenses(int year, int month) const;

    // File operations
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::unique_ptr<User> currentUser;
    std::string dataDirectory;
    
    void ensureDataDirectoryExists();
    std::string getUserFilePath(const std::string& username) const;
};

#endif // BUDGET_MANAGER_HPP 