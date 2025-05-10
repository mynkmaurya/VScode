#include "User.hpp"
#include <sstream>
#include <stdexcept>
#include <ctime>

User::User(const std::string& name, double initialBalance)
    : name(name)
    , balance(initialBalance) {}

void User::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
    
    if (transaction.getType() == TransactionType::INCOME) {
        balance += transaction.getAmount();
    } else {
        balance -= transaction.getAmount();
    }
}

double User::getCurrentBalance() const {
    return balance;
}

std::string User::getName() const {
    return name;
}

const std::vector<Transaction>& User::getTransactions() const {
    return transactions;
}

double User::getTotalIncome() const {
    double total = 0.0;
    for (const auto& transaction : transactions) {
        if (transaction.getType() == TransactionType::INCOME) {
            total += transaction.getAmount();
        }
    }
    return total;
}

double User::getTotalExpenses() const {
    double total = 0.0;
    for (const auto& transaction : transactions) {
        if (transaction.getType() == TransactionType::EXPENSE) {
            total += transaction.getAmount();
        }
    }
    return total;
}

std::vector<Transaction> User::getTransactionsByCategory(Category category) const {
    std::vector<Transaction> result;
    for (const auto& transaction : transactions) {
        if (transaction.getCategory() == category) {
            result.push_back(transaction);
        }
    }
    return result;
}

std::vector<Transaction> User::getTransactionsByMonth(int year, int month) const {
    std::vector<Transaction> result;
    
    for (const auto& transaction : transactions) {
        auto time = std::chrono::system_clock::to_time_t(transaction.getDate());
        std::tm* timeInfo = std::localtime(&time);
        
        if (timeInfo->tm_year + 1900 == year && timeInfo->tm_mon + 1 == month) {
            result.push_back(transaction);
        }
    }
    
    return result;
}

std::string User::serialize() const {
    std::stringstream ss;
    ss << name << "\n" << balance << "\n" << transactions.size() << "\n";
    
    for (const auto& transaction : transactions) {
        ss << transaction.serialize() << "\n";
    }
    
    return ss.str();
}

User User::deserialize(const std::string& data) {
    std::stringstream ss(data);
    std::string name;
    double balance;
    size_t transactionCount;
    
    std::getline(ss, name);
    ss >> balance >> transactionCount;
    ss.ignore(); // Skip newline
    
    User user(name, balance);
    
    std::string transactionData;
    for (size_t i = 0; i < transactionCount && std::getline(ss, transactionData); ++i) {
        user.transactions.push_back(Transaction::deserialize(transactionData));
    }
    
    return user;
} 