#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to append user input to a file
void appendToFile(const string& filename) 
{
    ofstream file(filename, ios::app); // Open file in append mode
    
    if (!file.is_open()) 
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    cout << "Enter text to append to file (enter '#' to stop):\n";
    string input;
    getline(cin, input);

    // Sanitize input to prevent format vulnerabilities (replace newline characters)
    input.erase(remove(input.begin(), input.end(), '\n'), input.end());
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());

    // Append user input to file
    file << input << endl;

    file.close();
    cout << "Text appended to " << filename << " successfully.\n";
}

// Function to reverse contents of a file and write to another file
void reverseFileContents(const string& inputFile, const string& outputFile) 
{
    ifstream inFile(inputFile);

    if (!inFile.is_open()) 
    {
        cerr << "Error opening input file: " << inputFile << endl;
        return;
    }

    ofstream outFile(outputFile);

    if (!outFile.is_open()) 
    {
        cerr << "Error opening output file: " << outputFile << endl;
        inFile.close();
        return;
    }

    // Read content of input file into a string
    string content((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));
    
    inFile.close(); // Close input file after reading content

    // Reverse the content
    reverse(content.begin(), content.end());
    
    // Write reversed content to output file
    outFile << content;

    outFile.close(); // Close output file after writing content

    cout << "Content reversed and saved to " << outputFile << " successfully.\n";
}

int main() {

    string filename = "CSC450_CT5_mod5.txt";

    string reversedFilename = "CSC450-mod5-reverse.txt";

    // Append user input to the file
    appendToFile(filename);

    // Reverse contents of the file
    reverseFileContents(filename, reversedFilename);

    return 0;
}
