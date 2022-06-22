#pragma once
#include <fstream>

namespace io {
    class Header {
        private: std::ofstream stream;

        public: Header(const std::string& name);
        public: void addMacro(const std::string& name, const std::string& definition);
        public: void addMacro(const std::string& name, const size_t& definition);
    };
}

extern io::Header config;