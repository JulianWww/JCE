#include <jce/consoleUtils.hpp>

void jce::consoleUtils::render_progress_bar(float progress, bool persistant)
{
    if (progress <= 1.0) {
        int barWidth = 70;

        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        if (persistant) 
        {
            std::cout << "] " << int(progress * 100.0) << std::endl;
        }
        else
        {
            std::cout << "] " << int(progress * 100.0) << " %\r";
        }
        std::cout.flush();
    }
}