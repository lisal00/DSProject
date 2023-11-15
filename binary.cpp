#include <string>
using namespace std;

/**Function to convert decimal to binary 
 *@param decimal The decimal to be converted to binary
 */
string DectoBin(int decimal){ 
    string res = ""; //result string
    int binaryNum[32]; // array to store binary number 
    int i = 0; 

    while (decimal > 0) { 
        // storing remainder in binary array 
        binaryNum[i] = decimal % 2; 
        decimal = decimal / 2; 
        i++; 
    }

    for (int j = i - 1; j >= 0; j--){
        res.append(to_string(binaryNum[j]));
    }

    return res;
}