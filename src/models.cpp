#include <stdio.h>
#include "models.h"
#include "ui.h"

const char *available_models[] = {
    "llama3:8b", "llama2-uncensored", "gemma3", "gemma", "phi3:mini", "mistral",
    "gemma:2b", "gemma:7b", "qwen:7b", "qwen2.5-coder", "qwen3", "deepseek-coder:6.7b",
    "deepseek-v2:16b", "dolphin-mistral:7b", "dolphin3", "starcoder2:7b",
    "magistral", "devstral"};

const int available_models_count = sizeof(available_models) / sizeof(available_models[0]);

void list_models(void)
{
    print_muted("\nAvailable models:\n");
    for (int i = 0; i < available_models_count; i++)
    {
        print_muted(" - %s\n", available_models[i]);
    }
    putchar('\n');
}
