#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "network.h"
#include "ui.h"

#define MAX_INPUT 2048
#define API_URL "https://m3-chat.vercel.app/api/gen"
#define CURL_CMD_TEMPLATE "curl --no-buffer -sS \"%s?model=%s&content=%s\""

static char *url_encode(const char *str)
{
    char *enc = malloc(strlen(str) * 3 + 1);
    char *penc = enc;

    if (!enc)
        return NULL;

    while (*str)
    {
        if (
            ('a' <= *str && *str <= 'z') ||
            ('A' <= *str && *str <= 'Z') ||
            ('0' <= *str && *str <= '9') ||
            *str == '-' || *str == '_' || *str == '.' || *str == '~')
        {
            *penc++ = *str;
        }
        else
        {
            sprintf(penc, "%%%02X", (unsigned char)*str);
            penc += 3;
        }
        str++;
    }
    *penc = '\0';
    return enc;
}

void fetch_response(const char *model, const char *input)
{
    char *encoded_input = url_encode(input);
    if (!encoded_input)
    {
        print_muted("Failed to encode input.\n");
        return;
    }

    char cmd[MAX_INPUT * 3];
    snprintf(cmd, sizeof(cmd), CURL_CMD_TEMPLATE, API_URL, model, encoded_input);

    free(encoded_input);

    FILE *fp = popen(cmd, "r");
    if (fp == NULL)
    {
        print_muted("Failed to contact server.\n");
        return;
    }

    print_muted("m3chat (%s):\n", model);

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
        fflush(stdout);
    }
    putchar('\n');
    pclose(fp);
}
