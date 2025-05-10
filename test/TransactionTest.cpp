#include <gtest/gtest.h>
#include "Transaction.hpp"

TEST(TransactionTest, ConstructorAndGetters)
{
    double amount = 100.50;
    TransactionType type = TransactionType::INCOME;
    Category category = Category::SALARY;
    std::string description = "Monthly salary";

    Transaction transaction(amount, type, category, description);

    EXPECT_EQ(transaction.getAmount(), amount);
    EXPECT_EQ(transaction.getType(), type);
    EXPECT_EQ(transaction.getCategory(), category);
    EXPECT_EQ(transaction.getDescription(), description);
}

TEST(TransactionTest, SerializationDeserialization)
{
    double amount = 75.25;
    TransactionType type = TransactionType::EXPENSE;
    Category category = Category::FOOD;
    std::string description = "Grocery shopping";

    Transaction original(amount, type, category, description);

    // Serialize
    std::string serialized = original.serialize();

    // Deserialize
    Transaction deserialized = Transaction::deserialize(serialized);

    EXPECT_EQ(deserialized.getAmount(), original.getAmount());
    EXPECT_EQ(deserialized.getType(), original.getType());
    EXPECT_EQ(deserialized.getCategory(), original.getCategory());
    EXPECT_EQ(deserialized.getDescription(), original.getDescription());
}

TEST(TransactionTest, InvalidDeserialization)
{
    std::string invalidData = "invalid|data";

    EXPECT_THROW({ Transaction::deserialize(invalidData); }, std::runtime_error);
}