# Simple Calculator

A module that performs basic arithmetic calculations.

## Build

```bash
nix flake update           # first time only
nix build '.#lgx-portable'
```

Produces `result/simple_calculator.lgx`. Install into Basecamp's modules dir
(`~/Library/Application Support/Logos/LogosBasecamp/modules/simple_calculator/` on macOS).

## Layout

- `src/simple_calculator_impl.h` — public API (pure C++, std types only)
- `src/simple_calculator_impl.cpp` — implementation (Qt allowed inside)
- `metadata.json` — module manifest with `"interface": "universal"`
- `flake.nix` — runs `logos-cpp-generator` in `preConfigure` to emit `generated_code/`
- `CMakeLists.txt` — `logos_module()` target

## Calling from QML

```qml
var raw = logos.callModule("simple_calculator", "add", []);
// raw is a JSON-encoded string. Parse + extract:
var v = JSON.parse(raw);
```

## Editing

Public method signatures live in `SimpleCalculatorImpl` in `src/simple_calculator_impl.h`.
Implementation lives in `src/simple_calculator_impl.cpp`. Add private state to the
`Private` pimpl class (already there if any Qt-typed state was declared).
