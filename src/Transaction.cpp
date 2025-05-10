#include "Transaction.hpp"
#include <sstream>
#include <iomanip>
#include <vector>
#include <stdexcept>

Transaction::Transaction(double amount,
                         TransactionType type,
                         Category category,
                         const std::string &description,
                         const std::chrono::system_clock::time_point &date)
    : amount(amount), type(type), category(category), description(description), date(date) {}

double Transaction::getAmount() const
{
    return amount;
}

TransactionType Transaction::getType() const
{
    return type;
}

Category Transaction::getCategory() const
{
    return category;
}

std::string Transaction::getDescription() const
{
    return description;
}

std::chrono::system_clock::time_point Transaction::getDate() const
{
    return date;
}

std::string Transaction::serialize() const
{
    std::stringstream ss;
    auto time = std::chrono::system_clock::to_time_t(date);

    ss << amount << "|"
       << static_cast<int>(type) << "|"
       << static_cast<int>(category) << "|"
       << description << "|"
       << time;

    return ss.str();
}

Transaction Transaction::deserialize(const std::string &data)
{
    std::stringstream ss(data);
    std::string item;
    std::vector<std::string> parts;

    while (std::getline(ss, item, '|'))
    {
        parts.push_back(item);
    }

    if (parts.size() != 5)
    {
        throw std::runtime_error("Invalid transaction data format");
    }

    double amount = std::stod(parts[0]);
    TransactionType type = static_cast<TransactionType>(std::stoi(parts[1]));
    Category category = static_cast<Category>(std::stoi(parts[2]));
    std::string description = parts[3];
    std::time_t time = std::stoull(parts[4]);

    return Transaction(amount, type, category, description,
                       std::chrono::system_clock::from_time_t(time));
}