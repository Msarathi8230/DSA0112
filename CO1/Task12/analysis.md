# Task 12 — Day-4 design challenge

## A. Impact analysis
The fourth zone affects the `Zone` enum, fare table and zone validation. Weekend discount adds a named constant, a `weekend` input and a rule with priority over peak surcharge. Monthly passes require a new `MonthlyPass` class storing two covered zones and a coverage check. `SmartCard` remains useful for stored-value users; a journey authorisation layer should check the pass before charging stored value.

## B. Evaluate the original design
A switch can be extended with `Airport`, but each new zone requires another branch and can miss a case. An indexed fare table makes adding a zone one row plus an enum update, but must validate enum/index values. Example: Airport base Rs60; weekday peak = Rs72 (7200 paise); weekend = Rs54 (5400 paise), because weekend discount does not combine with peak surcharge. A Rs100 card cannot pay Rs72 and retain Rs50, so stored-value travel is denied; a valid pass covering Airport can authorise the journey without fare deduction, subject to pass policy.

## C. Adaptation
The working `revised_design.cpp` uses a four-entry `constexpr` fare table, integer paise, an independent weekend rule, and `MonthlyPass` covering two selected zones. For simplicity, this sample shows pass coverage but does not model expiry dates, purchase/refund or passenger identity. A production authorisation function should check pass coverage first, then apply stored-card eligibility and deduction only if the pass does not cover the zone.

## D. Evidence-based defence
The included test prints Rs72.00 for Airport weekday peak and Rs54.00 for Airport weekend, and demonstrates that a pass can cover Inner and Airport but not Outer. The table is O(1) lookup and uses O(z) constant storage; the switch and table are both O(1) for a fixed zone set. Choose **MODIFY**, not full redesign: preserve SmartCard encapsulation and integer-paise invariants, while moving fare selection into a table and adding separate discount/pass policy components. Extend tests for all zones, all time boundaries, weekends, pass-covered/uncovered zones and card balance boundary cases before production release.
