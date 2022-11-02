#include <util/ListSelectionPrompt.h>
#include <iostream>

int main() {
    ListSelectionPrompt p = { "a", "b", "c", "d" };
    auto selection = p.getSelection("Please select an option: ");
    std::cout << selection << std::endl;

    return 0;
}