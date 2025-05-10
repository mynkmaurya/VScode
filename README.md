# Personal Finance Tracker

A C++ console application for tracking personal finances. This project demonstrates core C++ concepts including:

- Class abstraction with proper encapsulation
- File I/O for data persistence
- STL containers (vector, map)
- Modern C++ features (C++17)
- Unit testing with Google Test

## Features

- Create and manage multiple user profiles
- Track income and expenses
- Categorize transactions (food, transport, entertainment, etc.)
- Generate monthly financial reports
- View expenses by category
- Data persistence to files

## Project Structure

- `include/` - Header files
- `src/` - Source files
- `test/` - Unit tests
- `data/` - User data files (created at runtime)

## Building the Project

### Prerequisites

- CMake 3.10 or higher
- C++17 compatible compiler
- Internet connection (for initial download of Google Test)

### Build Instructions

1. Clone the repository
2. Create a build directory and navigate to it:

```bash
mkdir -p build && cd build
```

3. Generate the build files with CMake:

```bash
cmake ..
```

4. Build the project:

```bash
cmake --build .
```

## Running the Application

From the build directory:

```bash
./src/finance_tracker
```

## Running the Tests

From the build directory:

```bash
./test/finance_tracker_tests
```

## Usage

1. Create a new user profile or load an existing one
2. Add income and expenses with appropriate categories
3. Generate reports to view your financial status

## License

This project is open source and available under the MIT License.
