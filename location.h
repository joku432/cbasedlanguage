#ifndef CBASED_LOCATION_H
#define CBASED_LOCATION_H
#include <string>

struct Location {
    Location(const std::string& pfile, int prow, int pcol)
    : mFile(pfile), mRow(prow), mCol(pcol) {}
    std::string file;
    int row;
    int col;

    bool operator==(const Location& other) {
        return other.file == file &&
            other.row == row &&
            other.col == col;
    }
};

#endif //CBASED_LOCATION_H
