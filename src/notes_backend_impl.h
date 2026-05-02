#ifndef NOTES_BACKEND_IMPL_H
#define NOTES_BACKEND_IMPL_H

// Universal module — public API uses only standard C++ types
// (std::string, double, bool, void). All Qt usage is hidden in the
// .cpp behind a private pimpl, so logos-cpp-generator can parse this
// header to emit the QML/IPC glue.

#include <string>
#include <vector>

class NotesBackendImpl {
public:
    NotesBackendImpl();
    ~NotesBackendImpl();

    // Adds a note to the internal list and persists it using SQLite.
    void addNote(const std::string& note);
    // Retrieves all stored notes.
    std::vector<std::string> getNotes();

private:
    class Private;
    Private* d;
};

#endif // NOTES_BACKEND_IMPL_H
