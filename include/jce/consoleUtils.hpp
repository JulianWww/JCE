#pragma once
#include <iostream>


namespace jce
{
    namespace consoleUtils
    {
        void render_progress_bar(float progress, bool persistand = false);

        inline std::ostream& reset      (std::ostream &__base) { __base << "\033[0m"; return __base; }
        inline std::ostream& bold       (std::ostream &__base) { __base << "\033[1m"; return __base; }
        inline std::ostream& underline  (std::ostream &__base) { __base << "\033[4m"; return __base; }
        inline std::ostream& inverse    (std::ostream &__base) { __base << "\033[7m"; return __base; }
        inline std::ostream& debold     (std::ostream &__base) { __base << "\033[21m"; return __base; }
        inline std::ostream& deunderline(std::ostream &__base) { __base << "\033[24m"; return __base; }
        inline std::ostream& deinverse  (std::ostream &__base) { __base << "\033[27m"; return __base; }

        inline std::ostream& fblack     (std::ostream &__base) { __base << "\033[30m"; return __base; }
        inline std::ostream& fred       (std::ostream &__base) { __base << "\033[31m"; return __base; }
        inline std::ostream& fgreen     (std::ostream &__base) { __base << "\033[32m"; return __base; }
        inline std::ostream& fyellow    (std::ostream &__base) { __base << "\033[33m"; return __base; }
        inline std::ostream& fblue      (std::ostream &__base) { __base << "\033[34m"; return __base; }
        inline std::ostream& fmagenta   (std::ostream &__base) { __base << "\033[35m"; return __base; }
        inline std::ostream& fcian      (std::ostream &__base) { __base << "\033[36m"; return __base; }
        inline std::ostream& fwhite     (std::ostream &__base) { __base << "\033[37m"; return __base; }

        inline std::ostream& bblack     (std::ostream &__base) { __base << "\033[40m"; return __base; }
        inline std::ostream& bred       (std::ostream &__base) { __base << "\033[41m"; return __base; }
        inline std::ostream& bgreen     (std::ostream &__base) { __base << "\033[42m"; return __base; }
        inline std::ostream& byellow    (std::ostream &__base) { __base << "\033[43m"; return __base; }
        inline std::ostream& bblue      (std::ostream &__base) { __base << "\033[44m"; return __base; }
        inline std::ostream& bmagenta   (std::ostream &__base) { __base << "\033[45m"; return __base; }
        inline std::ostream& bcian      (std::ostream &__base) { __base << "\033[46m"; return __base; }
        inline std::ostream& bwhite     (std::ostream &__base) { __base << "\033[47m"; return __base; }
    }
}

