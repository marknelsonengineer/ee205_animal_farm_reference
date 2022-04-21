Contribute to Animal Farm
=========================

### Coding Conventions
- `using namespace std` in `.cpp` files is OK
- `using namespace std` in `.h` files is **NOT** OK
- We are using `cout` now, not `printf()`
- Messages and exceptions should be pre-pended with `PROGRAM_NAME`
- Hierarchy of messages & error handling
  - DEBUG - Print message only when DEBUG is enabled
  - INFO - Print message for both debug and release code
  - WARN - Print a message
  - ERROR - Print message & throw an exception
    - Use `throw` for issues that we may want to catch, not warnings.  See [When to use assertions and when to use exceptions?](https://softwareengineering.stackexchange.com/questions/15515/when-to-use-assertions-and-when-to-use-exceptions)
  - FATAL - Print message and kill the program
    - Use `assert()` for things that should never happen and we don't really want to catch
- Put 2 or 3 blank lines between methods
- Usually, I document the narrative of a function or member in the `.h` file.  Then, I document the details `@param`, `@returns`, `@throws`, `@todo` and Sample Output in the `.cpp` file.
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

### Pre-commit Checklist
- For each source file:
  - Cleanup `#include` files
  - Ensure all parameters are validated
  - `assert( validateDatabase() )` before-and-after anything that modifies it
  - Look for `const`-able parameters
  - Look for `const`-able and `noexcept`-able methods
  - Are the exceptions documented?
  - Are the parameters documented?
  - Search for \\tag and replace with \@tag
  - Only accepted Clang-Tidy problems
- Doxygen
  - No Doxygen warnings
  - Proofread the Doxygen-generated content
- Last looks
  - Do a `Rebuild Project` without any warnings
