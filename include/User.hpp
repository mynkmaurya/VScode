#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "Transaction.hpp"

class User {
public:
    User(const std::string& name, double initialBalance = 0.0);

    // Account management
    void addTransaction(const Transaction& transaction);
    double getCurrentBalance() const;
    
    // Getters
    std::string getName() const;
    const std::vector<Transaction>& getTransactions() const;
    
    // Analysis
    double getTotalIncome() const;
    double getTotalExpenses() const;
    std::vector<Transaction> getTransactionsByCategory(Category category) const;
    std::vector<Transaction> getTransactionsByMonth(int year, int month) const;

    // Serialization
    std::string serialize() const;
    static User deserialize(const std::string& data);

private:
    std::string name;
    double balance;
    std::vector<Transaction> transactions;
};

#endif // USER_HPP 