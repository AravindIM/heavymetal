#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 100

int count_substring(char string[], char substring[]);

int main() {
  char string[BUFFER_LEN], substring[BUFFER_LEN];
  int count;

  printf("Enter your string:");
  scanf(" %[^\n]s", string);
  printf("Enter your substring:");
  scanf(" %[^\n]s", substring);

  count = count_substring(string, substring);

  printf("%s occurs %d times in '%s'\n", substring, count, string);
}

int count_substring(char string[], char substring[]) {
  size_t string_len, substring_len;
  size_t string_index, substring_index;
  size_t match_count;
  int count = 0;

  string_len = strlen(string);
  substring_len = strlen(substring);

  string_index = 0;
  while (string_index < string_len) {
    substring_index = 0;
    match_count = 0;

    while (string[string_index] == substring[substring_index]) {
      ++match_count;
      ++string_index;
      ++substring_index;
    }
    if (match_count == substring_len) {
      ++count;
    } else {
      ++string_index;
    }
  }
  return count;
}