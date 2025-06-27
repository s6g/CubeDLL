#pragma once
namespace COLORS {
    // Reset
    inline const char* RESET = "\033[0m";

    // Regular Colors
    inline const char* BLACK = "\033[0;30m";
    inline const char* RED = "\033[0;31m";
    inline const char* GREEN = "\033[0;32m";
    inline const char* YELLOW = "\033[0;33m";
    inline const char* BLUE = "\033[0;34m";
    inline const char* MAGENTA = "\033[0;35m";
    inline const char* CYAN = "\033[0;36m";
    inline const char* WHITE = "\033[0;37m";

    // Bold Colors
    inline const char* BOLD_BLACK = "\033[1;30m";
    inline const char* BOLD_RED = "\033[1;31m";
    inline const char* BOLD_GREEN = "\033[1;32m";
    inline const char* BOLD_YELLOW = "\033[1;33m";
    inline const char* BOLD_BLUE = "\033[1;34m";
    inline const char* BOLD_MAGENTA = "\033[1;35m";
    inline const char* BOLD_CYAN = "\033[1;36m";
    inline const char* BOLD_WHITE = "\033[1;37m";

    // Background Colors
    inline const char* BG_BLACK = "\033[40m";
    inline const char* BG_RED = "\033[41m";
    inline const char* BG_GREEN = "\033[42m";
    inline const char* BG_YELLOW = "\033[43m";
    inline const char* BG_BLUE = "\033[44m";
    inline const char* BG_MAGENTA = "\033[45m";
    inline const char* BG_CYAN = "\033[46m";
    inline const char* BG_WHITE = "\033[47m";

    // Bright Colors
    inline const char* BRIGHT_BLACK = "\033[0;90m";
    inline const char* BRIGHT_RED = "\033[0;91m";
    inline const char* BRIGHT_GREEN = "\033[0;92m";
    inline const char* BRIGHT_YELLOW = "\033[0;93m";
    inline const char* BRIGHT_BLUE = "\033[0;94m";
    inline const char* BRIGHT_MAGENTA = "\033[0;95m";
    inline const char* BRIGHT_CYAN = "\033[0;96m";
    inline const char* BRIGHT_WHITE = "\033[0;97m";

    // Text Styling
    inline const char* BOLD = "\033[1m";
    inline const char* DIM = "\033[2m";
    inline const char* UNDERLINE = "\033[4m";
    inline const char* BLINK = "\033[5m";
    inline const char* REVERSE = "\033[7m";

}

#define LOG_ACTIVE(MSG)   std::cout << COLORS::GREEN  << MSG << COLORS::RESET << std::endl
#define LOG_INACTIVE(MSG)  std::cout << COLORS::RED << MSG << COLORS::RESET << std::endl
