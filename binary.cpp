#include <string>
#include <vector>
using namespace std;

/** Function to convert decimal to binary
 * @param decimal The decimal to be converted to binary
 */
string DectoBin(int decimal)
{
    vector<int> binaryNum; // vector to store binary number

    while (decimal > 0)
    {
        binaryNum.push_back(decimal % 2); // push the remainder to binary vector
        decimal = decimal / 2;
    }

    // Convert from vector to string
    string res = "";
    for (auto it = binaryNum.rbegin(); it != binaryNum.rend(); ++it)
    {
        res.append(to_string(*it));
    }

    return res;
}
