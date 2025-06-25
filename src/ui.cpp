#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "../include/ui.h"

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

void print_error(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\033[1;31merror:\033[0m ");
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void print_intro_box(void)
{
    printf(COLOR_MUTED "\n╭────────────────────────────────────────────────────────────────────────────╮\n" COLOR_RESET);
    // Gradient colors for each line
    const char *gradient[] = {
        "\x1b[38;5;81m",  // blue
        "\x1b[38;5;75m",  // cyan
        "\x1b[38;5;78m",  // green-cyan
        "\x1b[38;5;114m", // green
        "\x1b[38;5;149m", // yellow-green
        "\x1b[38;5;221m"  // yellow
    };
    const char *ascii_lines[] = {
        "  ██╗             ███╗   ███╗██████╗      ██████╗██╗  ██╗ █████╗ ████████╗",
        "   ╚██╗           ████╗ ████║╚════██╗    ██╔════╝██║  ██║██╔══██╗╚══██╔══╝",
        "     ╚██╗         ██╔████╔██║ █████╔╝    ██║     ███████║███████║   ██║   ",
        "    ██╔╝          ██║╚██╔╝██║ ╚═══██╗    ██║     ██╔══██║██╔══██║   ██║   ",
        "  ██╔╝███████╗    ██║ ╚═╝ ██║██████╔╝    ╚██████╗██║  ██║██║  ██║   ██║   ",
        "  ╚═╝ ╚══════╝    ╚═╝     ╚═╝╚═════╝      ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   "};
    for (int i = 0; i < 6; ++i)
    {
        printf(COLOR_MUTED "│"
                           "%s%s" COLOR_RESET,
               gradient[i], ascii_lines[i]);
        printf("  ");
        printf(COLOR_MUTED "│\n" COLOR_RESET);
    }
    printf(COLOR_MUTED "│                                                                            │\n" COLOR_RESET);
    printf(COLOR_MUTED "│ " COLOR_WHITE "    "
                       "\x1b[36m*\x1b[97m"
                       " Welcome to m3chat-tui                                 " COLOR_MUTED "               │\n" COLOR_RESET);
    printf(COLOR_MUTED "│                                                                            │\n" COLOR_RESET);
    printf(COLOR_MUTED "│ " COLOR_WHITE "    Type a prompt and get an AI response from the LLM   " COLOR_MUTED "                   │\n" COLOR_RESET);
    printf(COLOR_MUTED "│                                                                            │\n" COLOR_RESET);
    printf(COLOR_MUTED "│ " COLOR_WHITE "    /models — list available models                         " COLOR_MUTED "               │\n" COLOR_RESET);
    printf(COLOR_MUTED "│ " COLOR_WHITE "    /exit   — quit                                          " COLOR_MUTED "               │\n" COLOR_RESET);
    printf(COLOR_MUTED "│ " COLOR_WHITE "    /clear  — clear screen                                  " COLOR_MUTED "               │\n" COLOR_RESET);
    printf(COLOR_MUTED "│                                                                            │\n" COLOR_RESET);
    printf(COLOR_MUTED "╰────────────────────────────────────────────────────────────────────────────╯\n\n" COLOR_RESET);
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
