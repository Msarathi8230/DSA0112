# Task 3 — Data types and compatibility

| Value | Recommended type | Reason |
|---|---|---|
| Zone | `enum class Zone` | finite, type-safe set |
| Hour/minute | `int` | small validated integer range |
| Peak flag | `bool` | two states |
| Fare/balance | `long long` paise | exact arithmetic and large totals |
| Journey count | `long long` | comfortably handles millions and larger counts |
| Text/card ID | `std::string` | variable-length text |
| Approximate sensor values only | `double` | floating point is not appropriate for money |

`sizeof` and limits are printed by `types.cpp` for the actual compiler/platform; sizes are implementation-dependent. On typical x86-64 GCC, `int` is 4 bytes and `long long`/`double` are 8 bytes. `INT_MAX` is typically 2,147,483,647. Three million journeys at Rs 36 total Rs 108,000,000,000 paise (Rs 108,000,000) if each fare is 3600 paise, which exceeds `int` in paise. `int + double` converts the integer to double; arithmetic with bool promotes it to int. `0.1` has no exact binary floating representation, so repeated additions may not equal the mathematically exact result. Integer paise avoids this for fares. Addition costs O(1) in either type; each `long long` and `double` is typically 8 bytes.
