# War Game C++ Project

## Build
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude -o war_game src/*.cpp
```

## Run
```bash
./war_game <input_csv> <output_csv>
```

## Test
```bash
pytest -q
```

## Assumptions
1. The spec line saying to continue while "either" deck is non-empty was implemented as `while (!playerA_.empty() && !playerB_.empty())`. Otherwise the game would not terminate once one player ran out of cards.
2. I included `Deck::operator[]` because the overview mentions operator overloading for `operator[]`, even though the step-by-step section does not require it explicitly.
3. The provided `FileReader` and `FileWriter` implementations were used as given.
