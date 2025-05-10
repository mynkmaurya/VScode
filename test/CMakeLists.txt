set(TEST_SOURCES
    TransactionTest.cpp
)

add_executable(finance_tracker_tests ${TEST_SOURCES})
target_include_directories(finance_tracker_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(finance_tracker_tests PRIVATE
    gtest_main
    gtest
    pthread
)

target_sources(finance_tracker_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src/Transaction.cpp
    ${CMAKE_SOURCE_DIR}/src/User.cpp
    ${CMAKE_SOURCE_DIR}/src/BudgetManager.cpp
)

include(GoogleTest)
gtest_discover_tests(finance_tracker_tests) 