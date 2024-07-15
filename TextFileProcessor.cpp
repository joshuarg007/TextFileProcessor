#include <iostream>   // Include the input/output stream library
#include <fstream>    // Include the file stream library for file operations
#include <string>     // Include the string library for string operations
#include <algorithm>  // Include the algorithm library for standard algorithms

using namespace std;  // Use the standard namespace for convenience

// Function to append user input to a file
void appendToFile(const string& filename) 
{
    ofstream file(filename, ios::app); // Open file in append mode

    if (!file.is_open())  // Check if the file failed to open
    {
        cerr << "Error opening file: " << filename << endl;  // Print error message to standard error stream
        return;  // Exit the function if file opening failed
    }

    cout << "Enter text to append to file (enter '#' to stop):\n";  // Prompt user for input
    string input;
    getline(cin, input);  // Read a line of input from standard input

    // Sanitize input to prevent format vulnerabilities (replace newline characters)
    input.erase(remove(input.begin(), input.end(), '\n'), input.end());  // Remove newline characters
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());  // Remove carriage return characters

    // Append user input to file
    file << input << endl;  // Write sanitized input to file

    file.close();  // Close the file after writing
    cout << "Text appended to " << filename << " successfully.\n";  // Print success message
}

// Function to reverse contents of a file and write to another file
void reverseFileContents(const string& inputFile, const string& outputFile) 
{
    ifstream inFile(inputFile);  // Open input file for reading

    if (!inFile.is_open())  // Check if input file failed to open
    {
        cerr << "Error opening input file: " << inputFile << endl;  // Print error message to standard error stream
        return;  // Exit the function if input file opening failed
    }

    ofstream outFile(outputFile);  // Open output file for writing

    if (!outFile.is_open())  // Check if output file failed to open
    {
        cerr << "Error opening output file: " << outputFile << endl;  // Print error message to standard error stream
        inFile.close();  // Close input file
        return;  // Exit the function if output file opening failed
    }

    // Read content of input file into a string
    string content((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));

    inFile.close();  // Close input file after reading content

    // Reverse the content
    reverse(content.begin(), content.end());  // Reverse the string content

    // Write reversed content to output file
    outFile << content;  // Write reversed content to output file

    outFile.close();  // Close output file after writing content
    cout << "Content reversed and saved to " << outputFile << " successfully.\n";  // Print success message
}

int main() {

    string filename = "CSC450_CT5_mod5.txt";  // Define input file name

    string reversedFilename = "CSC450-mod5-reverse.txt";  // Define output file name

    // Append user input to the file
    appendToFile(filename);

    // Reverse contents of the file
    reverseFileContents(filename, reversedFilename);

    return 0;  // Return 0 to indicate successful execution
}
