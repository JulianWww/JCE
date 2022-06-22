#include <headers.hpp>
#include <iostream>

io::Header::Header(const std::string& name): stream(JCE_CONFIG_FILE) {
    stream << "#pragma once" << std::endl << std::endl;
}
void io::Header::addMacro(const std::string& name, const std::string& definition) {
    stream << "#define " << name << " " << definition << std::endl;
}
void io::Header::addMacro(const std::string& name, const size_t& definition) {
    stream << "#define " << name << " " << definition << std::endl;
}

io::Header config("");