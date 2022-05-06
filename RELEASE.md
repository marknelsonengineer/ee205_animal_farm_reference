Pre-Release Checklist
=====================

- For each source file:
    - Cleanup `#include` files
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
