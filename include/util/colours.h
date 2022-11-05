#ifndef __COLOURS_H__
#define __COLOURS_H__

#include <string>
namespace colours
{
    // Regular Colors
    constexpr auto&  RESET = "\033[0m";  // Text Reset
    constexpr auto&  BLACK = "\033[0;30m";   // BLACK
    constexpr auto&  RED = "\033[0;31m";     // RED
    constexpr auto&  GREEN = "\033[0;32m";   // GREEN
    constexpr auto&  YELLOW = "\033[0;33m";  // YELLOW
    constexpr auto&  BLUE = "\033[0;34m";    // BLUE
    constexpr auto&  PURPLE = "\033[0;35m";  // PURPLE
    constexpr auto&  CYAN = "\033[0;36m";    // CYAN
    constexpr auto&  WHITE = "\033[0;37m";   // WHITE

    // Bold
    constexpr auto& BLACK_BOLD = "\033[1;30m";  // BLACK
    constexpr auto& RED_BOLD = "\033[1;31m";    // RED
    constexpr auto& GREEN_BOLD = "\033[1;32m";  // GREEN
    constexpr auto& YELLOW_BOLD = "\033[1;33m"; // YELLOW
    constexpr auto& BLUE_BOLD = "\033[1;34m";   // BLUE
    constexpr auto& PURPLE_BOLD = "\033[1;35m"; // PURPLE
    constexpr auto& CYAN_BOLD = "\033[1;36m";   // CYAN
    constexpr auto& WHITE_BOLD = "\033[1;37m";  // WHITE

    // Underline
    constexpr auto& BLACK_UNDERLINED = "\033[4;30m";  // BLACK
    constexpr auto& RED_UNDERLINED = "\033[4;31m";    // RED
    constexpr auto& GREEN_UNDERLINED = "\033[4;32m";  // GREEN
    constexpr auto& YELLOW_UNDERLINED = "\033[4;33m"; // YELLOW
    constexpr auto& BLUE_UNDERLINED = "\033[4;34m";   // BLUE
    constexpr auto& PURPLE_UNDERLINED = "\033[4;35m"; // PURPLE
    constexpr auto& CYAN_UNDERLINED = "\033[4;36m";   // CYAN
    constexpr auto& WHITE_UNDERLINED = "\033[4;37m";  // WHITE

    // Background
    constexpr auto& BLACK_BACKGROUND = "\033[40m";  // BLACK
    constexpr auto& RED_BACKGROUND = "\033[41m";    // RED
    constexpr auto& GREEN_BACKGROUND = "\033[42m";  // GREEN
    constexpr auto& YELLOW_BACKGROUND = "\033[43m"; // YELLOW
    constexpr auto& BLUE_BACKGROUND = "\033[44m";   // BLUE
    constexpr auto& PURPLE_BACKGROUND = "\033[45m"; // PURPLE
    constexpr auto& CYAN_BACKGROUND = "\033[46m";   // CYAN
    constexpr auto& WHITE_BACKGROUND = "\033[47m";  // WHITE

    // High Intensity
    constexpr auto& BLACK_BRIGHT = "\033[0;90m";  // BLACK
    constexpr auto& RED_BRIGHT = "\033[0;91m";    // RED
    constexpr auto& GREEN_BRIGHT = "\033[0;92m";  // GREEN
    constexpr auto& YELLOW_BRIGHT = "\033[0;93m"; // YELLOW
    constexpr auto& BLUE_BRIGHT = "\033[0;94m";   // BLUE
    constexpr auto& PURPLE_BRIGHT = "\033[0;95m"; // PURPLE
    constexpr auto& CYAN_BRIGHT = "\033[0;96m";   // CYAN
    constexpr auto& WHITE_BRIGHT = "\033[0;97m";  // WHITE

    // Bold High Intensity
    constexpr auto& BLACK_BOLD_BRIGHT = "\033[1;90m"; // BLACK
    constexpr auto& RED_BOLD_BRIGHT = "\033[1;91m";   // RED
    constexpr auto& GREEN_BOLD_BRIGHT = "\033[1;92m"; // GREEN
    constexpr auto& YELLOW_BOLD_BRIGHT = "\033[1;93m";// YELLOW
    constexpr auto& BLUE_BOLD_BRIGHT = "\033[1;94m";  // BLUE
    constexpr auto& PURPLE_BOLD_BRIGHT = "\033[1;95m";// PURPLE
    constexpr auto& CYAN_BOLD_BRIGHT = "\033[1;96m";  // CYAN
    constexpr auto& WHITE_BOLD_BRIGHT = "\033[1;97m"; // WHITE

    // High Intensity backgrounds
    constexpr auto& BLACK_BACKGROUND_BRIGHT = "\033[0;100m";// BLACK
    constexpr auto& RED_BACKGROUND_BRIGHT = "\033[0;101m";// RED
    constexpr auto& GREEN_BACKGROUND_BRIGHT = "\033[0;102m";// GREEN
    constexpr auto& YELLOW_BACKGROUND_BRIGHT = "\033[0;103m";// YELLOW
    constexpr auto& BLUE_BACKGROUND_BRIGHT = "\033[0;104m";// BLUE
    constexpr auto& PURPLE_BACKGROUND_BRIGHT = "\033[0;105m"; // PURPLE
    constexpr auto& CYAN_BACKGROUND_BRIGHT = "\033[0;106m";  // CYAN
    constexpr auto& WHITE_BACKGROUND_BRIGHT = "\033[0;107m";   // WHITE  
};


#endif // __COLOURS_H__