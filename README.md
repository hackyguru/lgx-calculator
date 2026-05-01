# Calculator

A module that performs arithmetic calculations based on input strings.

## Build

```bash
nix flake update           # first time only
nix build '.#lgx-portable'
```

Produces `result/calculator.lgx`. Install into Basecamp's modules dir
(`~/Library/Application Support/Logos/LogosBasecamp/modules/calculator/` on macOS).

## Layout

- `src/calculator_impl.h` — public API (pure C++, std types only)
- `src/calculator_impl.cpp` — implementation (Qt allowed inside)
- `metadata.json` — module manifest with `"interface": "universal"`
- `flake.nix` — runs `logos-cpp-generator` in `preConfigure` to emit `generated_code/`
- `CMakeLists.txt` — `logos_module()` target

## Calling from QML

```qml
var raw = logos.callModule("calculator", "calculate", []);
// raw is a JSON-encoded string. Parse + extract:
var v = JSON.parse(raw);
```

## Editing

Public method signatures live in `CalculatorImpl` in `src/calculator_impl.h`.
Implementation lives in `src/calculator_impl.cpp`. Add private state to the
`Private` pimpl class (already there if any Qt-typed state was declared).
