#include "Logger.h"
#include <fstream>
using namespace std;

namespace Logger {
    void log(LogLevel level, const std::string& message) {
        if (level == INFO) cout << "[INFO] " << message << endl;
        else if (level == WARNING) cout << "[WARNING] " << message << endl;
        else if (level == ERROR)   cout << "[ERROR] " << message << endl;
    }
    namespace FileLogger {
        void logToFile(const string& filename, const string& message) {
            ofstream file(filename, ios::app);
            if (file.is_open()) {
                file << message << endl;
            }
        }
    }
}