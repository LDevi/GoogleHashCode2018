#include <iostream>
#include <cstring>
#include<bits/stdc++.h>
#include "City.h"
#define INPUT_FILE_PATH "PATH"
static const char *const FILE_NAME_INPUT_EXT = ".in";
static const char *const FILE_NAME_OUTPUT_EXT = ".out";
using namespace std;

vector<string> initFilesNames();
void processFile(char *inputFileAbsolutePath, char *outputFileAbsolutePath);
char *getInputFilePath(const char *inputFileName);;
char *getOutputFilePath(const char *inputFileName);

int main() {
    for (auto &i : initFilesNames()) {
        processFile(getInputFilePath(i.c_str()), getOutputFilePath(i.c_str()));
    }
    return 0;
}

char *getInputFilePath(const char *inputFileName) {
    char* inputFileAbsolutePath;
    inputFileAbsolutePath = static_cast<char *>(calloc(strlen(INPUT_FILE_PATH) + strlen(inputFileName) + 1, sizeof(char)));
    strcpy(inputFileAbsolutePath, INPUT_FILE_PATH);
    strcat(inputFileAbsolutePath, inputFileName);
    strcat(inputFileAbsolutePath, FILE_NAME_INPUT_EXT);
    return inputFileAbsolutePath;
}

char *getOutputFilePath(const char *inputFileName) {
    char* inputFileAbsolutePath;
    inputFileAbsolutePath = static_cast<char *>(calloc(strlen(INPUT_FILE_PATH) + strlen(inputFileName) + 1, sizeof(char)));
    strcpy(inputFileAbsolutePath, INPUT_FILE_PATH);
    strcat(inputFileAbsolutePath, inputFileName);
    strcat(inputFileAbsolutePath, FILE_NAME_OUTPUT_EXT);
    return inputFileAbsolutePath;
}
void processFile(char *inputFileAbsolutePath, char *outputFileAbsolutePath) {
    City c(inputFileAbsolutePath,outputFileAbsolutePath);
    c.basic_simulation();
    c.fleetStat();
    delete inputFileAbsolutePath;
    delete outputFileAbsolutePath;
}

vector<string> initFilesNames() {
    vector<string> inputFilesNames;
    inputFilesNames.emplace_back("a_example");
    inputFilesNames.emplace_back("b_should_be_easy");
    inputFilesNames.emplace_back("c_no_hurry");
    inputFilesNames.emplace_back("d_metropolis");
    inputFilesNames.emplace_back("e_high_bonus");
    return inputFilesNames;
}