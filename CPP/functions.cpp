/*
 # Functions Quiz: Basic to Advanced

## Question 1 (Basic)
Write a function called `greet` that takes a name as a parameter and returns "Hello, [name]!". If no name is provided, it should return "Hello, World!".

**Expected Output:**
```
greet("Alice") → "Hello, Alice!"
greet() → "Hello, World!"
```

---

## Question 2 (Basic)
Create a function `is_even` that takes an integer and returns `True` if the number is even, `False` otherwise.

**Expected Output:**
```
is_even(4) → True
is_even(7) → False
```

---

## Question 3 (Basic-Intermediate)
Write a function `calculate_area` that can calculate the area of different shapes. It should take a shape name and necessary parameters:
- Circle: radius
- Rectangle: length, width
- Triangle: base, height

**Expected Output:**
```
calculate_area("circle", 5) → 78.54 (approximately)
calculate_area("rectangle", 4, 6) → 24
calculate_area("triangle", 10, 8) → 40
```

---

## Question 4 (Intermediate)
Create a function `find_max_min` that takes a list of numbers and returns both the maximum and minimum values as a tuple.

**Expected Output:**
```
find_max_min([3, 7, 2, 9, 1]) → (9, 1)
find_max_min([5]) → (5, 5)
```

---

## Question 5 (Intermediate)
Write a recursive function `factorial` that calculates the factorial of a positive integer. Include error handling for negative numbers.

**Expected Output:**
```
factorial(5) → 120
factorial(0) → 1
factorial(-3) → "Error: Factorial not defined for negative numbers"
```

---

## Question 6 (Intermediate-Advanced)
Create a higher-order function `apply_operation` that takes a list of numbers and a function, then applies that function to each element in the list.

**Example Usage:**
```python
def square(x):
    return x ** 2

def double(x):
    return x * 2

apply_operation([1, 2, 3, 4], square) → [1, 4, 9, 16]
apply_operation([1, 2, 3, 4], double) → [2, 4, 6, 8]
```

---

## Question 7 (Advanced)
Write a function `memoize` that implements memoization (caching) for any function. It should store previously computed results and return them if the same inputs are provided again.

**Test with this Fibonacci function:**
```python
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

memoized_fib = memoize(fibonacci)
# Should be much faster for large values
```

---

## Question 8 (Advanced)
Create a function `compose` that takes multiple functions as arguments and returns a new function that applies them in sequence (function composition).

**Expected Behavior:**
```python
def add_one(x):
    return x + 1

def multiply_by_two(x):
    return x * 2

def square(x):
    return x ** 2

composed = compose(square, multiply_by_two, add_one)
composed(3) → 64  # ((3 + 1) * 2)² = (8)² = 64
```

---

## Question 9 (Advanced)
Write a function `curry` that converts a function that takes multiple arguments into a series of functions that each take a single argument.

**Expected Behavior:**
```python
def add_three_numbers(a, b, c):
    return a + b + c

curried_add = curry(add_three_numbers)
result = curried_add(1)(2)(3)  # Should return 6

# Or partial application:
add_1_and_2 = curried_add(1)(2)
result = add_1_and_2(3)  # Should return 6
```

---

## Question 10 (Advanced)
Create a function `create_counter` that demonstrates closures. It should return a function that maintains its own count and increments it each time it's called. Each counter should be independent.

**Expected Behavior:**
```python
counter1 = create_counter()
counter2 = create_counter()

counter1() → 1
counter1() → 2
counter2() → 1
counter1() → 3
counter2() → 2
```

---

## Bonus Challenge (Expert Level)
Implement a function `throttle` that limits how often a function can be called. It should take a function and a time limit (in milliseconds), and return a new function that can only be executed once per time period.

**Usage:**
```python
import time

def expensive_operation():
    print("Expensive operation executed!")
    return "Result"

throttled_op = throttle(expensive_operation, 1000)  # 1 second limit

# Multiple rapid calls should only execute once per second
for i in range(5):
    throttled_op()
    time.sleep(0.2)  # 200ms between calls
```

---

## Assessment Rubric

**Basic (Questions 1-2):** Understanding of function syntax, parameters, and return values
**Intermediate (Questions 3-5):** Control flow, data structures, recursion, error handling
**Advanced (Questions 6-10):** Higher-order functions, closures, decorators, functional programming concepts
**Expert (Bonus):** Advanced concepts like throttling, timing, and practical optimization techniques
*/
#include<iostream>
using namespace std;
string greet(string name ) {

   
    if(name.empty()) {
        return "Hello, World!";
    }
    // If the name is not empty, return a personalized greeting
    // using the provided name.
    else{
        return "Hello, " + name + "!";
    }
}
int main() {
    
    cout << greet() << endl;
    return 0;
}