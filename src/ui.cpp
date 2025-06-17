#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "ui.h"

#define COLOR_MUTED "\x1b[38;5;102m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_WHITE "\x1b[97m"

void print_muted(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf(COLOR_MUTED);
    vprintf(fmt, args);
    printf(COLOR_RESET);
    va_end(args);
}

void print_intro_box(void)
{
    printf(COLOR_MUTED "\n╭─────────────────────────────────────────────────────────────╮\n" COLOR_RESET);
    printf(COLOR_MUTED "│                                                             │\n" COLOR_RESET);

    printf(COLOR_MUTED "│ " COLOR_WHITE "    * Welcome to m3chat-tui                                 " COLOR_MUTED "│\n" COLOR_RESET);
    printf(COLOR_MUTED "│                                                             │\n" COLOR_RESET);
    printf(COLOR_MUTED "│ " COLOR_WHITE "    Type a prompt and get an AI response from your model.   " COLOR_MUTED "│\n" COLOR_RESET);
    printf(COLOR_MUTED "│                                                             │\n" COLOR_RESET);
    printf(COLOR_MUTED "│ " COLOR_WHITE "    /models — list available models                         " COLOR_MUTED "│\n" COLOR_RESET);
    printf(COLOR_MUTED "│ " COLOR_WHITE "    /exit   — quit                                          " COLOR_MUTED "│\n" COLOR_RESET);
    printf(COLOR_MUTED "│ " COLOR_WHITE "    /clear  — clear screen                                  " COLOR_MUTED "│\n" COLOR_RESET);
    printf(COLOR_MUTED "│                                                             │\n" COLOR_RESET);

    printf(COLOR_MUTED "╰─────────────────────────────────────────────────────────────╯\n\n" COLOR_RESET);
}

void box_input(const char *input)
{
    printf(COLOR_MUTED "\n┌─ User Input ───────────────────────────────────────────┐\n" COLOR_RESET);
    printf(COLOR_MUTED "│ %s", input);
    for (int i = 0; i < 50 - (int)strlen(input); i++)
        printf(" ");
    printf("│\n");
    printf(COLOR_MUTED "└────────────────────────────────────────────────────────┘\n\n" COLOR_RESET);
}

void clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
