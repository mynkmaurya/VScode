#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <chrono>

enum class TransactionType
{
    INCOME,
    EXPENSE
};

enum class Category
{
    SALARY,
    FOOD,
    TRANSPORT,
    ENTERTAINMENT,
    UTILITIES,
    RENT,
    OTHER
};

class Transaction
{
public:
    Transaction(double amount,
                TransactionType type,
                Category category,
                const std::string &description,
                const std::chrono::system_clock::time_point &date = std::chrono::system_clock::now());

    // Getters
    double getAmount() const;
    TransactionType getType() const;
    Category getCategory() const;
    std::string getDescription() const;
    std::chrono::system_clock::time_point getDate() const;

    // Serialization
    std::string serialize() const;
    static Transaction deserialize(const std::string &data);

private:
    double amount;
    TransactionType type;
    Category category;
    std::string description;
    std::chrono::system_clock::time_point date;
};

#endif // TRANSACTION_HPP