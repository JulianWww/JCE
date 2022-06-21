#include <jce/consoleUtils.hpp>
#include <sort.hpp>

int main(int argc, char **argv) {
    std::cout << jce::consoleUtils::fgreen << "Performing optimization" << jce::consoleUtils::reset << std::endl;

    optim::optimizeSort();
    
    return 1;
}