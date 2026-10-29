# Task 1 — Understand the problem and identify objects

## Object-oriented analysis
- **SmartCard**: data: card ID and balance in integer paise; behaviour: recharge, check eligibility, deduct fare. The balance is private so callers cannot make it negative accidentally.
- **Passenger**: data: passenger category and concession eligibility; behaviour: request a journey. In a larger system, student/senior rules belong here or in a policy object.
- **Journey**: data: origin/destination zone, entry time, weekend flag; behaviour: validate inputs and provide journey facts to the fare calculator.
- **Zone**: a finite domain (`Inner`, `Middle`, `Outer`, later `Airport`) that selects a base fare.
- **FareTable/FarePolicy**: stores base fares and applies time-based surcharge or discounts. Centralising this rule avoids repeated magic numbers.

## Procedural vs OOP
A procedural version keeps `balance`, fares and limits in variables and calls free functions such as `fareFor(zone, peak)` and `canTravel(balance, fare)`. It can be fast and compact, but every function must respect the same invariants. The OOP version groups state with operations and hides the balance, reducing accidental misuse and localising changes.

## OOP principles
- **Encapsulation**: private card balance, modified only through validated methods.
- **Abstraction**: callers ask `canTravel()` / `deduct()` without knowing the internal balance representation.
- **Inheritance**: a `Passenger` base class could have `Student` and `SeniorCitizen` subclasses if their behaviour genuinely differs.
- **Polymorphism**: a virtual concession-policy method could calculate a concession per passenger type; for a small fixed rule, a data-driven policy may be simpler.

## Invariants and assumptions
1. Money is stored as integer paise.
2. A successful journey leaves at least Rs 50 (5000 paise) after deduction.
3. An unsuccessful journey does not alter the balance.
4. Peak hours are `[08:00, 10:00)` and `[17:00, 20:00)`: 8:00 and 17:00 are peak; 10:00 and 20:00 are not.
5. Unknown zones, invalid times and negative recharges are rejected.
6. Since the brief does not specify concession percentages, Tasks 1–11 do not invent one; concessions are identified as a policy extension.

## Alternative and complexity
Both a procedural function and a class method can compute one fare in O(1) time. A card balance occupies O(1) space in either design. OOP does not automatically make the algorithm faster; it makes invariants and rule changes easier to contain. A single fare change is ideally made in one central fare table/policy rather than in many duplicated conditionals.
