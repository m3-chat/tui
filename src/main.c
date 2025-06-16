#include <stdio.h>
#include <string.h>
#include "models.h"
#include "network.h"
#include "ui.h"

#define MAX_INPUT 2048

int main(int argc, char *argv[])
{
    const char *model = argc > 1 ? argv[1] : NULL;

    print_intro_box();

    if (!model)
    {
        list_models();
        print_muted("Usage: ./m3 <model>\n\n");
        return 0;
    }

    print_muted("Selected model: %s\n", model);

    char input[MAX_INPUT];
    while (1)
    {
        print_muted("\n> ");
        if (!fgets(input, MAX_INPUT, stdin))
            break;

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "/exit") == 0)
            break;
        if (strcmp(input, "/models") == 0)
        {
            list_models();
            continue;
        }
        if (strcmp(input, "/clear") == 0)
        {
            clear_screen();
            continue;
        }

        box_input(input);
        fetch_response(model, input);
    }

    print_muted("\nExiting m3chat-tui. Bye!\n");
    return 0;
}
