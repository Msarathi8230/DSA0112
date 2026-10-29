# DSA01-REGISTER_NUMBER-Assignment1

**Student:** Santosh M.  
**Register Number:** REPLACE_WITH_REGISTER_NUMBER  
**Assignment:** CO1 — Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System  
**Compiler tested:** GCC g++ 14.2.0 (Linux x86-64 container)  
**Standard/flags:** `g++ -std=c++17 -Wall -Wextra -pedantic`

> Before submission, replace the register-number placeholder, confirm the required compiler/version on your own computer, and capture/retain your own execution screenshots. The `outputs/` folders contain captured console transcripts generated from the actual runs in the build environment.

## Compile and run
From the repository root, for example:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic Task06/complete_code.cpp -o task06
./task06
```
On Windows PowerShell, run `.\task06.exe` after compilation. Build all tasks and refresh output logs with:
```bash
bash scripts/build_and_test.sh
```

## Task index
| Task | Files | Result |
|---|---|---|
| 1 | `Task01/analysis.md` | Objects, OOP principles, invariants, procedural comparison |
| 2 | `Task02/tokens_constants.cpp`, `analysis.md` | Typed constants, enum class and token examples |
| 3 | `Task03/types.cpp`, `analysis.md` | `sizeof`, limits, money precision demonstration |
| 4 | `Task04/predict_output.cpp`, `prediction.md` | Pre-execution prediction and conversion analysis |
| 5 | `Task05/operators.cpp`, `prediction.md` | Pre-execution prediction and operator evaluation |
| 6 | `Task06/complete_code.cpp`, `pseudocode.md` | Completed TODOs, integer-paise fare and balance rule |
| 7 | `Task07/procedural.cpp`, `oop.cpp`, `analysis.md` | Both procedural and encapsulated versions |
| 8 | `Task08/safe_io.cpp`, `analysis.md` | Input recovery and money formatting |
| 9 | `Task09/fare_tests.cpp`, `analysis.md` | Table-driven fare tests and hand calculation |
| 10 | `Task10/totals.cpp`, `analysis.md` | Large totals, overflow and floating-point experiment |
| 11 | `Task11/final_design.cpp`, `analysis.md` | Recommended central policy and SmartCard design |
| 12 | `Task12/revised_design.cpp`, `analysis.md` | Airport zone, weekend discount, monthly pass |

## Screenshots and logs
Each task has an `outputs/` directory. `.txt` files are exact captured stdout/stderr from compiled execution; `.png` files render the captured console output for convenient viewing. `Task01` contains analysis rather than a required executable, so its output is a documented review checklist.

## Git workflow requirement
The local repository is initialized with one commit per task. To publish it, create a GitHub repository named `DSA01-<RegisterNumber>-Assignment1`, then set the remote and push:
```bash
git remote add origin https://github.com/YOUR_USERNAME/DSA01-<RegisterNumber>-Assignment1.git
git push -u origin main
```
Add the faculty as collaborator if the repository is private. Submit the working repository URL and the assignment report through Google Classroom. This local preparation does not itself publish to GitHub or submit to Classroom.
