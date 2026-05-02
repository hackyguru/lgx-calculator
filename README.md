# Notes Backend

Manages note storage and retrieval using SQLite.

## Build

```bash
nix flake update           # first time only
nix build '.#lgx-portable'
```

Produces `result/notes_backend.lgx`. Install into Basecamp's modules dir
(`~/Library/Application Support/Logos/LogosBasecamp/modules/notes_backend/` on macOS).

## Layout

- `src/notes_backend_impl.h` — public API (pure C++, std types only)
- `src/notes_backend_impl.cpp` — implementation (Qt allowed inside)
- `metadata.json` — module manifest with `"interface": "universal"`
- `flake.nix` — runs `logos-cpp-generator` in `preConfigure` to emit `generated_code/`
- `CMakeLists.txt` — `logos_module()` target

## Calling from QML

```qml
var raw = logos.callModule("notes_backend", "addNote", []);
// raw is a JSON-encoded string. Parse + extract:
var v = JSON.parse(raw);
```

## Editing

Public method signatures live in `NotesBackendImpl` in `src/notes_backend_impl.h`.
Implementation lives in `src/notes_backend_impl.cpp`. Add private state to the
`Private` pimpl class (already there if any Qt-typed state was declared).
