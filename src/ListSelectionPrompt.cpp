#include <util/ListSelectionPrompt.h>
#include <iostream>

ListSelectionPrompt::ListSelectionPrompt(std::initializer_list<std::string> init)
    : options(init)
{
}

std::string ListSelectionPrompt::getSelection(const std::string& prompt) const
{
    unsigned long maxVal = options.size();
    for (int i = 1; i < options.size() + 1; i++)
        std::printf("%d. %s\n", i, options[i - 1].c_str());

    int selection;
    do {
        std::cout << prompt;
        std::cin >> selection;
        if (selection <= 0 || selection > maxVal)
            std::cout << "Invalid selection!" << std::endl;
    } while (selection <= 0 || selection > maxVal);

    return options[selection - 1];
}

int ListSelectionPrompt::getSelectionIndex(const std::string& prompt) const
{
    unsigned long maxVal = options.size();
    for (int i = 1; i < options.size() + 1; i++)
        std::printf("%d. %s\n", i, options[i - 1].c_str());

    int selection;
    do {
        std::cout << prompt;
        std::cin >> selection;
        if (selection <= 0 || selection > maxVal)
            std::cout << "Invalid selection!" << std::endl;
    } while (selection <= 0 || selection > maxVal);

    return selection - 1;
}