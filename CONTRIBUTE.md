Contribute to Animal Farm
=========================

## Coding Conventions
- `using namespace std` in `.cpp` files is OK
- `using namespace std` in `.h` files is **NOT** OK
- Most methods should return a bool to indicate success or failure.  This makes it easier to assert.
- Throw exceptions for catastrophic issues, not warnings
- Put 2 or 3 blank lines between methods
- We are using cout now, not printf
- Messages should be pre-pended with PROGRAM_NAME

## Pre-commit Checklist
- For each source file:
  - Cleanup #include files
  - Ensure all parameters are validated
  - `assert( validateDatabase() )` before-and-after anything that modifies it
  - Look for `const`-able parameters
  - Look for `const`-able and `noexcept`-able methods
  - Are the exceptions documented?
  - Are the parameters documented?
  - Only accepted Clang-Tidy problems
- Doxygen
  - No Doxygen warnings
  - Proofread the Doxygen-generated content
- Last looks
  - Do a `Rebuild Project` without any warnings
