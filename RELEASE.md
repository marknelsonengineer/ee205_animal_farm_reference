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

- For each constructor:
  - Are we using delegating constructors?
  - Are we using initializer lists?

- Doxygen
    - No Doxygen warnings
    - Proofread the Doxygen-generated content

- Last looks
    - Do a `Rebuild Project` without any warnings
    - `All_Boost_Tests` pass

- Releasing to students
    - Determine if `DOXYGEN_SOURCE_BROWSER` should be `ON`
    - Determine if `VERBATIM_HEADERS` should be `ON`
    - Determine if `STRIP_CODE_COMMENTS` should be `ON`
    - Determine if `WARN_AS_ERROR` should be `FAIL_ON_WARNINGS` or something else