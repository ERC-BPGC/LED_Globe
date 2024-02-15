#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//zypherr aka yashraj

// Function to split a string based on a delimiter
vector<string> splitString(const string &input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

int main() {
    // Input CSV file name
    string csvFileName = "C:\\Users\\yashr\\Desktop\\csv2code\\data_captain.csv";

    // Output text file name
    string outputFileName = "captain.txt";

    // Open the CSV file for reading
    ifstream inputFile(csvFileName);

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open CSV file." << endl;
        return 1;
    }

    // Open the output text file for writing
    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output text file." << endl;
        inputFile.close();
        return 1;
    }

    // Read and process each row of the CSV file
    string rowData;
    string ele = "";
    vector<string> red, green, blue;
    vector<string> rowValue;

    bool f=1;
    while (getline(inputFile, rowData)) {
        // Split the row into individual column values
        rowValue = splitString(rowData, ',');
        if(f){
            // rowValue.erase(rowValue.begin());
            printf("%d\n", rowValue.size());
            // for (int i = 0; i < rowValue.size(); i++)
            // {
            //     cout<<rowValue[i]<<" ";
            // }
            
            f = !f;
        }
        int z=0;
        for(int k=0; k<14; k++){
            //below writes for 8 leds at a time
            for(int i=0; i<3; i++){
                int cnt=0;
                while(cnt<8){
                    int l = (8*z)+cnt;
                    ele = ele.append(string(1, rowValue[l][i]));
                    cnt++;
                }
                if(i==0){
                red.push_back(ele);
                ele = "";
                }
                else if(i==1){
                green.push_back(ele);
                ele = "";
                }
                else{
                blue.push_back(ele);
                ele = "";
                }
                
            }
            z++;
        }

        // Process the column values as needed
        int k = 0;
        for (const string &valuer : red) {
            // Do something with each value (e.g., write to the output file)
            outputFile << "arr_red["<< k++ << "]= B" << valuer << ";" << "\n";
        }
        outputFile << endl;
        k=0;
        for (const string &valueg : green) {
            // Do something with each value (e.g., write to the output file)
            outputFile << "arr_green["<< k++ << "]= B" << valueg << ";" << "\n";
        }
        outputFile << endl;
        k=0;
        for (const string &valueb : blue) {
            // Do something with each value (e.g., write to the output file)
            outputFile << "arr_blue["<< k++ << "]= B" << valueb << ";" << "\n";
        }
        outputFile << "rgb_clm();\ndelay(dl);\n" << endl;
        red.clear();
        green.clear();
        blue.clear();
        
        
    }

    
    // Close the input and output files
    inputFile.close();
    outputFile.close();

    printf("Data has been successfully written to ");
    std::cout << outputFileName;
    return 0;
}
