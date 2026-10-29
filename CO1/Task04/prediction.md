# Task 4 — Prediction written before execution

**Predicted output (before running):**
```text
3 3.5
C 68
1 true
s >= u
```

Explanation: `a / b` is integer division before conversion to double, so 7/2 becomes 3. `static_cast<double>(a)` makes the division floating-point, giving 3.5. `'A' + 2` is integer arithmetic then converted to `char`, yielding `C`; `ch + 1` promotes the char to int and prints 68 (ASCII-compatible execution set). `bool flag = 5` converts nonzero to true; default bool output is `1`, and `boolalpha` prints `true`. In `s < u`, the negative signed `s` converts to unsigned, becoming a large unsigned value, so the condition is false and `s >= u` prints. Compiler/platform character encoding assumptions apply to the numeric character code.

Explicit conversions and brace initialisation make intent clearer and catch narrowing at compile time, but casts do not change the O(1) runtime or constant storage of these operations. Prefer validating signed inputs before converting to unsigned.
