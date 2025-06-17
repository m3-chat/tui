#include <iostream>
#include <string>
#include "models.h"
#include "network.h"
#include "ui.h"

int main(int argc, char *argv[])
{
    std::string model = (argc > 1) ? argv[1] : "";

    print_intro_box();

    if (model.empty() || !is_valid_model(model))
    {
        list_models();
        print_muted("Usage: ./m3 <model>\n\n");
        return 0;
    }

    print_muted("Selected model: %s\n", model.c_str());

    std::string input;
    while (true)
    {
        print_muted("\n> ");
        if (!std::getline(std::cin, input))
            break;

        if (input == "/exit")
            break;
        if (input == "/models")
        {
            list_models();
            continue;
        }
        if (input == "/clear")
        {
            clear_screen();
            continue;
        }

        box_input(input.c_str());
        fetch_response(model.c_str(), input.c_str());
    }

    print_muted("\nExiting m3chat-tui. Bye!\n");
    return 0;
}
