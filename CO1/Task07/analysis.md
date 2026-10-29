# Task 7 — Procedural vs OOP

Both versions are executable. In the procedural version, the balance is passed by reference and every caller must use `deduct` correctly. In the OOP version, `balance_` is private and can change only through `deduct`, which checks the invariant. The minimum balance is centralised in one constant, so a change is local. If the balance were public, any code could set it negative or bypass the minimum-balance rule. Both versions use O(1) time per check/deduction and O(1) state per card; encapsulation changes maintainability, not asymptotic complexity.
