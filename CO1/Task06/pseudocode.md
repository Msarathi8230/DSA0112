# Task 6 — Standard algorithmic pseudocode

```text
ALGORITHM CalculateFare(zone, hour, weekend)
INPUT: valid zone, hour in 0..23, weekend flag
OUTPUT: fare in paise or INVALID
BEGIN
  SELECT zone
    Inner: base ← 1000
    Middle: base ← 2000
    Outer: base ← 3000
    OTHERWISE: RETURN INVALID
  END SELECT
  peak ← (hour >= 8 AND hour < 10) OR (hour >= 17 AND hour < 20)
  IF peak THEN fare ← base + (base * 20 DIV 100)
  ELSE fare ← base
  END IF
  RETURN fare
END

ALGORITHM ProcessJourney(cardBalance, fare)
BEGIN
  IF fare is INVALID OR cardBalance - fare < 5000 THEN
    OUTPUT "Denied"; keep balance unchanged
  ELSE
    cardBalance ← cardBalance - fare
    OUTPUT fare and cardBalance
  END IF
END
```

The completed C++ uses `switch` for the three fixed zones and integer paise. A `for` loop suits a known collection of trips; range-based `for` improves readability. `while` suits input until a sentinel or EOF. `continue` skips an invalid journey; `break` exits when no more input is required. A switch without a matching case and without `default` does nothing, so `default` is useful for invalid zones. Boundary policy: 10:00 and 20:00 are off-peak.
