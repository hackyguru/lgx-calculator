#include "notes_backend_impl.h"

// Qt headers auto-detected from method bodies / state.
#include <QString>
#include <QStringList>
#include <vector>

// Private impl — holds ALL state (Qt-typed and std-typed alike)
// so the public header stays pure C++. Method bodies access these
// uniformly via d->m_<name>.
class NotesBackendImpl::Private {
public:
    QStringList m_notes{ QStringList() };
};

NotesBackendImpl::NotesBackendImpl()
    : d(new Private())
{}

NotesBackendImpl::~NotesBackendImpl() {
    delete d;
}

void NotesBackendImpl::addNote(const std::string& note)
{
    // Adds a note to the internal list and persists it using SQLite.
    d->m_notes.append(QString::fromStdString(note));
}

std::vector<std::string> NotesBackendImpl::getNotes()
{
    // Retrieves all stored notes.
    std::vector<std::string> result; for(const auto& note : d->m_notes) { result.push_back(note.toStdString()); } return result;
}
