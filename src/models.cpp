#include "models.h"
#include "ui.h"

const std::vector<std::string> available_models = {
    "llama3:8b", "llama2-uncensored", "gemma3", "gemma", "phi3:mini", "mistral",
    "gemma:2b", "gemma:7b", "qwen:7b", "qwen2.5-coder", "qwen3", "deepseek-coder:6.7b",
    "deepseek-v2:16b", "dolphin-mistral:7b", "dolphin3", "starcoder2:7b",
    "magistral", "devstral"};

void list_models()
{
    print_muted("Available models:\n");
    for (const auto &model : available_models)
    {
        print_muted("  - %s\n", model.c_str());
    }
}

bool is_valid_model(const std::string &model)
{
    return std::find(available_models.begin(), available_models.end(), model) != available_models.end();
}
