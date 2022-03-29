Contribute to Animal Farm
=========================

### Coding Conventions
- `using namespace std` in `.cpp` files is OK
- `using namespace std` in `.h` files is **NOT** OK
- Most methods should return a `bool` to indicate success or failure.  This makes it easier to `assert()`.
- Use `assert()` for things that should never happen and we don't really want to catch
- Use `throw` for issues that we may want to catch, not warnings.  See [When to use assertions and when to use exceptions?](https://softwareengineering.stackexchange.com/questions/15515/when-to-use-assertions-and-when-to-use-exceptions)
- Put 2 or 3 blank lines between methods
- We are using `cout` now, not `printf()`
- Messages and exceptions should be pre-pended with `PROGRAM_NAME`
- Usually, I document the narrative of a function or member in the `.h` file.  Then, I document the details `@param`, `@returns`, `@throws`, `@todo` and Sample Output in the `.cpp` file.
- If there's a procedue that's longer than a page, I'll usually comment the `}` with an indication of what it's closing.  Ex. `} // validate()` 

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
