#include "MainData.hpp"

void MainData::parseFile(const std::string& path, Record* arr[], int& count, FileType type) {
    std::ifstream file{path};
    if (!file)
        throw std::runtime_error{"Cannot open file: " + path};

    std::string line;
    int line_no = 0;

    while (std::getline(file, line)) {
        ++line_no;
        if (!line.empty() && line.back() == '\r') line.pop_back();   // Windows line endings
        if (line.empty()) continue;                                   // skip blank lines

        Record* r = createRecord(type);                               // empty Event / Participant / Registration
        try {
            r->parse(line);                                           // virtual: the child reads its own fields

            if (count >= MAX_ITEMS)
                throw std::runtime_error{"storage full"};
            if (findIndex(arr, count, r->getKey()) != -1)
                throw std::runtime_error{"duplicate record " + r->getKey()};

            if (type == FileType::Registration) {                     // IDs must exist (events and participants load first)
                const Registration* reg = static_cast<const Registration*>(r);
                if (!findEvent(reg->getEventId()))
                    throw std::runtime_error{"unknown event " + reg->getEventId()};
                if (!findParticipant(reg->getParticipantId()))
                    throw std::runtime_error{"unknown participant " + reg->getParticipantId()};
            }

            arr[count++] = r;                                         // success: the array now owns it
        }
        catch (const std::exception& e) {
            delete r;                                                 // don't leak the rejected record
            std::cerr << path << " line " << line_no << " skipped: " << e.what() << "\n";
        }
    }
}

// ---------- load everything: ORDER MATTERS ----------
void MainData::loadAll(const std::string& event_file,
                       const std::string& participant_file,
                       const std::string& registration_file) {
    parseFile(event_file,        events_,        event_count_,        FileType::Event);
    parseFile(participant_file,  participants_,  participant_count_,  FileType::Participant);
    parseFile(registration_file, registrations_, registration_count_, FileType::Registration);
}

// ---------- display (one loop, three uses) ----------
void MainData::displayAll(Record* const arr[], int count) const {
    if (count == 0) {
        std::cout << "(no records)\n";
        return;
    }
    for (int i = 0; i < count; ++i)
        arr[i]->display();                                            // virtual: runtime polymorphism
}