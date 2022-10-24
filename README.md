# ConcreteAbstracts
COS 214 Project

### Code

 - Please put all header files in the `include` directory.
 - All `.cpp` files go in the `src` directory.
 - After adding a file to the project, make sure to add it to the `CMakeLists.txt` file.

## Building

### Option 1

 1. Try running `./build.sh`. If you get a permission denied error, first run `chmod +x build.sh`
 2. Change directory into the `build` directory and run `make`. This will compile the project and 
create an executable in the `build` directory. You can also run it with `make run`

### Option 2 (If option 1 doesn't work)

 1. Create a folder called `build` in the main directory.
 2. Change directory into  `build` and run `cmake ..`
 3. Now you can use `make` or `make run` inside the `build` directory like normal. 

## Testing

 1. To run all the tests, open a terminal in the build directory and run `make test`

## Doxygen 

### (DEBIAN BASED)
#### Pre-requisites
- sudo apt-get install doxygen
- sudo apt-get install graphviz -y 
#### Run Doxygen file
1. In Root directory run `doxygen`
2. locate [html/index.html](html/index.html)

