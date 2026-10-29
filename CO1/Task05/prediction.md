# Task 5 — Prediction written before execution

**Predicted output (before running):**
```text
11 16
9 6 4
6 4
3 1 -3 -1
18
```

Line 1: multiplication binds more tightly than addition: `5 + (3*2)=11`; parentheses force `(5+3)*2=16`. Line 2: postfix `x++` yields old 5 and then increments x; prefix `++y` increments y to 4 and yields 4; sum z=9, x=6, y=4. Line 3: conditional chooses max(6,4)=6; `%` and `*` have equal precedence and associate left-to-right: `(6%4)*2=4`. Line 4: integer division truncates toward zero; remainder has the dividend's sign: 10/3=3, 10%3=1, -10/3=-3, -10%3=-1. Line 5: i takes 0,3,6,9; k=18. `i = i++` is not a valid way to increment and can have undefined behaviour in older language versions / unsequenced-modification contexts; use `++i` or `i += 1`.

Peak check: `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`. `&&` binds tighter than `||`; parentheses improve readability. A 24-entry `bool` lookup table still checks in O(1) time but adds 24 bool elements (often 24 bytes); expression uses O(1) space too.
