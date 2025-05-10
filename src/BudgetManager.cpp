#include "BudgetManager.hpp"
#include <filesystem>
#include <fstream>
#include <stdexcept>

namespace fs = std::filesystem;

BudgetManager::BudgetManager() {
    dataDirectory = "data";
    ensureDataDirectoryExists();
}

void BudgetManager::createUser(const std::string& name, double initialBalance) {
    currentUser = std::make_unique<User>(name, initialBalance);
    saveCurrentUser();
}

void BudgetManager::loadUser(const std::string& name) {
    std::string filePath = getUserFilePath(name);
    if (!fs::exists(filePath)) {
        throw std::runtime_error("User does not exist: " + name);
    }
    
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("Failed to open user file: " + filePath);
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    currentUser = std::make_unique<User>(User::deserialize(buffer.str()));
}

void BudgetManager::saveCurrentUser() {
    if (!currentUser) {
        throw std::runtime_error("No user loaded");
    }
    
    std::string filePath = getUserFilePath(currentUser->getName());
    std::ofstream file(filePath);
    if (!file) {
        throw std::runtime_error("Failed to save user data: " + filePath);
    }
    
    file << currentUser->serialize();
}

void BudgetManager::addIncome(double amount, Category category, const std::string& description) {
    if (!currentUser) {
        throw std::runtime_error("No user loaded");
    }
    
    Transaction transaction(amount, TransactionType::INCOME, category, description);
    currentUser->addTransaction(transaction);
    saveCurrentUser();
}

void BudgetManager::addExpense(double amount, Category category, const std::string& description) {
    if (!currentUser) {
        throw std::runtime_error("No user loaded");
    }
    
    Transaction transaction(amount, TransactionType::EXPENSE, category, description);
    currentUser->addTransaction(transaction);
    saveCurrentUser();
}

double BudgetManager::getCurrentBalance() const {
    if (!currentUser) {
        throw std::runtime_error("No user loaded");
    }
    return currentUser->getCurrentBalance();
}

std::map<Category, double> BudgetManager::getExpensesByCategory() const {
    if (!currentUser) {
        throw std::runtime_error("No user loaded");
    }
    
    std::map<Category, double> expenses;
    for (const auto& transaction : currentUser->getTransactions()) {
        if (transaction.getType() == TransactionType::EXPENSE) {
            expenses[transaction.getCategory()] += transaction.getAmount();
        }
    }
    return expenses;
}

std::map<Category, double> BudgetManager::getMonthlyExpensesByCategory(int year, int month) const {
    if (!currentUser) {
        throw std::runtime_error("No user loaded");
    }
    
    std::map<Category, double> expenses;
    auto monthlyTransactions = currentUser->getTransactionsByMonth(year, month);
    
    for (const auto& transaction : monthlyTransactions) {
        if (transaction.getType() == TransactionType::EXPENSE) {
            expenses[transaction.getCategory()] += transaction.getAmount();
        }
    }
    return expenses;
}

double BudgetManager::getMonthlyIncome(int year, int month) const {
    if (!currentUser) {
        throw std::runtime_error("No user loaded");
    }
    
    double total = 0.0;
    auto monthlyTransactions = currentUser->getTransactionsByMonth(year, month);
    
    for (const auto& transaction : monthlyTransactions) {
        if (transaction.getType() == TransactionType::INCOME) {
            total += transaction.getAmount();
        }
    }
    return total;
}

double BudgetManager::getMonthlyExpenses(int year, int month) const {
    if (!currentUser) {
        throw std::runtime_error("No user loaded");
    }
    
    double total = 0.0;
    auto monthlyTransactions = currentUser->getTransactionsByMonth(year, month);
    
    for (const auto& transaction : monthlyTransactions) {
        if (transaction.getType() == TransactionType::EXPENSE) {
            total += transaction.getAmount();
        }
    }
    return total;
}

void BudgetManager::saveToFile(const std::string& filename) const {
    if (!currentUser) {
        throw std::runtime_error("No user loaded");
    }
    
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to save to file: " + filename);
    }
    
    file << currentUser->serialize();
}

void BudgetManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to load from file: " + filename);
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    currentUser = std::make_unique<User>(User::deserialize(buffer.str()));
}

void BudgetManager::ensureDataDirectoryExists() {
    if (!fs::exists(dataDirectory)) {
        fs::create_directory(dataDirectory);
    }
}

std::string BudgetManager::getUserFilePath(const std::string& username) const {
    return (fs::path(dataDirectory) / (username + ".dat")).string();
} 