# London Time Fetcher

Provides the current time in London.

## Build

```bash
nix flake update           # first time only
nix build '.#lgx-portable'
```

Produces `result/london_time_fetcher.lgx`. Install into Basecamp's modules dir
(`~/Library/Application Support/Logos/LogosBasecamp/modules/london_time_fetcher/` on macOS).

## Layout

- `src/london_time_fetcher_impl.h` — public API (pure C++, std types only)
- `src/london_time_fetcher_impl.cpp` — implementation (Qt allowed inside)
- `metadata.json` — module manifest with `"interface": "universal"`
- `flake.nix` — runs `logos-cpp-generator` in `preConfigure` to emit `generated_code/`
- `CMakeLists.txt` — `logos_module()` target

## Calling from QML

```qml
var raw = logos.callModule("london_time_fetcher", "fetchLondonTime", []);
// raw is a JSON-encoded string. Parse + extract:
var v = JSON.parse(raw);
```

## Editing

Public method signatures live in `LondonTimeFetcherImpl` in `src/london_time_fetcher_impl.h`.
Implementation lives in `src/london_time_fetcher_impl.cpp`. Add private state to the
`Private` pimpl class (already there if any Qt-typed state was declared).
