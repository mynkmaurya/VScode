def create_increment():
    counter = 0  # Local to the closure
    
    def increment():
        nonlocal counter  # Access outer scope variable
        counter += 1
        return counter
    
    return increment

# Create the function with persistent state
increment = create_increment()

# Test calls
print(increment())  # Output: 1
print(increment())  # Output: 2
print(increment())  # Output: 3
print(increment())  # Output: 4







