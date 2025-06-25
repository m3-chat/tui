#include "models.h"
#include "ui.h"

#include <string>
#include <vector>
#include <curl/curl.h>
#include <algorithm>

static std::vector<std::pair<std::string, std::string>> models;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

void parse_models(const std::string &json)
{
    models.clear();
    size_t pos = 0;
    while ((pos = json.find("{", pos)) != std::string::npos)
    {
        size_t labelStart = json.find("\"label\":\"", pos);
        if (labelStart == std::string::npos)
            break;
        labelStart += 9;
        size_t labelEnd = json.find("\"", labelStart);
        std::string label = json.substr(labelStart, labelEnd - labelStart);

        size_t valueStart = json.find("\"value\":\"", labelEnd);
        if (valueStart == std::string::npos)
            break;
        valueStart += 9;
        size_t valueEnd = json.find("\"", valueStart);
        std::string value = json.substr(valueStart, valueEnd - valueStart);

        models.emplace_back(label, value);
        pos = valueEnd;
    }
}

void fetch_models()
{
    std::string response;
    CURL *curl = curl_easy_init();
    if (!curl)
    {
        print_error("failed to init curl\n");
        return;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://m3-chat.vercel.app/api/models");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "m3chat-tui");
    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK)
    {
        print_error("couldn't fetch model list: %s\n", curl_easy_strerror(res));
        return;
    }

    parse_models(response);

    if (models.empty())
    {
        print_error("no models loaded — check your connection or the API response\n");
    }
}

void list_models()
{
    if (models.empty())
        fetch_models();

    print_muted("Available models:\n");
    for (const auto &[label, value] : models)
        print_muted("  %s (%s)\n", label.c_str(), value.c_str());
}

bool is_valid_model(const std::string &model)
{
    if (models.empty())
        fetch_models();

    if (models.empty())
        return model == "mistral";

    return std::any_of(models.begin(), models.end(), [&](const auto &m)
                       { return m.second == model; });
}
