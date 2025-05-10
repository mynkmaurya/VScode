@echo off
echo Building Personal Finance Tracker...

if not exist bin mkdir bin
if not exist obj mkdir obj

echo Compiling Transaction.cpp...
g++ -std=c++17 -I./include -c src/Transaction.cpp -o obj/Transaction.o

echo Compiling User.cpp...
g++ -std=c++17 -I./include -c src/User.cpp -o obj/User.o

echo Compiling BudgetManager.cpp...
g++ -std=c++17 -I./include -c src/BudgetManager.cpp -o obj/BudgetManager.o

echo Compiling main.cpp...
g++ -std=c++17 -I./include -c src/main.cpp -o obj/main.o

echo Linking...
g++ -std=c++17 obj/Transaction.o obj/User.o obj/BudgetManager.o obj/main.o -o bin/finance_tracker

echo Build complete! 