{
  description = "Manages note storage and retrieval using SQLite.";

  inputs = {
    logos-module-builder.url = "github:logos-co/logos-module-builder";
  };

  outputs = inputs@{ logos-module-builder, ... }:
    logos-module-builder.lib.mkLogosModule {
      src = ./.;
      configFile = ./metadata.json;
      flakeInputs = inputs;
      # Runs the universal-module code generator. It parses
      # src/notes_backend_impl.h and produces the QML/IPC glue under
      # generated_code/. CMakeLists.txt picks those up.
      preConfigure = ''
        logos-cpp-generator --from-header src/notes_backend_impl.h \
          --backend qt \
          --impl-class NotesBackendImpl \
          --impl-header notes_backend_impl.h \
          --metadata metadata.json \
          --output-dir ./generated_code
      '';
    };
}
