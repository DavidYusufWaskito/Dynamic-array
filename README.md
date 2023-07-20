# DArray C++ Project

DArray is a vector-like dynamic array implementation in C++. It provides a resizable array that can dynamically grow or shrink as elements are added or removed.

## Features

- Dynamic resizing: The array automatically resizes itself when the number of elements exceeds its current capacity.
- Iterator support: Allows iterating over the elements of the array using range-based loops or manual iteration.
- Efficient memory allocation: The array dynamically allocates memory based on a capacity threshold to minimize memory waste.

## Usage

1. Include the `DArray.h` header file in your C++ project.

```cpp
#include "DArray.h"
```

2. Create an instance of `DArray` with the desired data type.

```cpp
dvd::DArray<int> myArray;
```

3. Use the `push_back` function to add elements to the array.

```cpp
myArray.push_back(42);
```

4. Access elements using the index operator `[]`.

```cpp
int element = myArray[0];
```

5. Iterate over the elements using the provided iterator.

```cpp
for (auto& element : myArray) {
    // Process each element
}
```

6. Extend the array by adding elements from another array or an initializer list.

```cpp
dvd::DArray<int> otherArray = {1, 2, 3};
myArray.extend_element(otherArray);

int additionalElements[] = {4, 5, 6};
myArray.extend_element(additionalElements);
```

7. Retrieve the size of the array using the `Size` function.

```cpp
size_t size = myArray.Size();
```

8. Clear the array and deallocate memory using the `empty` function.

```cpp
myArray.empty();
```

## Build Instructions

To build the project, follow these steps:

1. Ensure you have the GCC compiler installed.

2. Create a Makefile with the following content:

```makefile
DEBUG_FLAG = -g
RELEASE_FLAG = -s -static -O3
PATH_RELEASE = build/release
PATH_DEBUG = build/debug

all: debug release
debug: $(PATH_DEBUG)/debug.exe
release: $(PATH_RELEASE)/release.exe

$(PATH_DEBUG)/debug.exe: include/*.h src/main.cpp
	g++ $(DEBUG_FLAG) src/main.cpp -I include -o $(PATH_DEBUG)/debug.exe

$(PATH_RELEASE)/release.exe: include/*.h src/main.cpp
	g++ $(RELEASE_FLAG) src/main.cpp -I include -o $(PATH_RELEASE)/release.exe
```

3. Run the `make` command to build the project.

```shell
make
```

4. The compiled executable will be available in the `build/debug` or `build/release` directory, depending on the build configuration.

## Contributing

Contributions to the DArray project are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the [Dynamic-array](https://github.com/Dazzy467/Dynamic-array).

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute it as per the terms of the license.

## Credits

DArray is developed and maintained by [Dazzy467](https://github.com/Dazzy467).
