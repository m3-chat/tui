#pragma once
#include <string>
#include <vector>

extern const std::vector<std::string> available_models;

void list_models();
bool is_valid_model(const std::string &model);
