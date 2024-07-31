#include <bits/stdc++.h>
#define taskname "hello"
using namespace std;

void runCommand(const string& command) {
    cout << "Running command: " << command << endl;
    if (system(command.c_str()) != 0) {
        cerr << "Failed to execute the command." << endl;
        exit(1);
    }
}

string toString(int x) {
    string res = "";
    while(x) {
        res += ('0'+ x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    if(res.size() < 2) res = '0' + res;
    return res;
}

const int testStart = 2;  // Number of test cases to generate
const int testEnd = 2;

int main() {
    string baseFolder = taskname;
    string testgenFile = "test.cpp";
    string mainFile = taskname".cpp";
    
    
    for (int i = testStart; i <= testEnd; ++i) {
        string folderName = "test" + toString(i);
        string inputFile = taskname".inp";
        string outputFile = taskname".out";
        
        // Create the folder for the current test case
        runCommand("mkdir " + folderName);
        
        // Generate the input file
        runCommand("g++ -std=c++14 " + testgenFile + " -o test.exe");
        runCommand("test.exe");
        
        // Run the main file and generate the output file
        runCommand("g++ -std=c++14 " + mainFile + " -o test.exe");
        runCommand("test.exe");

        // Move input file and output file into folder
        runCommand("move " + inputFile + " " + folderName);
        runCommand("move " + outputFile + " " + folderName);
        // Move folder into base folder
        runCommand("move " + folderName + " " + baseFolder);
    }
    
    cout << "Test generation complete." << endl;
    
    return 0;
}
