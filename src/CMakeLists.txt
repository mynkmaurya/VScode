set(SOURCES
    main.cpp
    Transaction.cpp
    User.cpp
    BudgetManager.cpp
)

add_executable(finance_tracker ${SOURCES})
target_include_directories(finance_tracker PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_features(finance_tracker PRIVATE cxx_std_17) 