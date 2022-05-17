Contribute to Animal Farm
=========================

### Coding Conventions
- `using namespace std` in `.cpp` files is OK
- `using namespace std` in `.h` files is **NOT** OK
- Animal Farm uses `cout`, not `printf`
- Sources that contain a `main()` are named `main_someProgram.cpp`
- Messages and exceptions should be pre-pended with `PROGRAM_NAME`
- Hierarchy of messages & error handling
  - DEBUG - Print message only when DEBUG is enabled
  - INFO - Print message for both debug and release code
  - WARN - Print a message
  - ERROR - Print message & throw an exception
    - Use `throw` for issues that we may want to catch, not warnings.  See [When to use assertions and when to use exceptions?](https://softwareengineering.stackexchange.com/questions/15515/when-to-use-assertions-and-when-to-use-exceptions)
  - FATAL - Print message and kill the program
    - Use `assert()` for things that should never happen and we don't really want to catch
- Put 2 blank lines between methods
- Usually, I document the one-line description of a function or member in the `.h` file.  Then, I document the narrative/details `@param`, `@returns`, `@throws`, `@todo` and Sample Output in the `.cpp` file.
- If there's a code-block that's longer than a page, I'll usually comment the `}` with an indication of what it's closing.  Ex. `} // validate()` 
- When declaring a class, I'll usually put the declarations in the following order:
  - Friend declarations
  - Enumerations
  - Constants
  - Private, Protected & Public member variables
  - Constructors
  - Public Getters & setters
  - Static methods
  - Public methods
  - Protected methods
  - Private methods
  - Abstract methods
  - Overrides
