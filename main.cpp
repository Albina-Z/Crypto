#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "    Encryption    " << endl;
    const int n(40);
    char Vowel_Letters[12] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'u', 'i', 'o','y'};
    char StringOut[3 * n];

    ifstream StringIn("C:\\1\\StringIn.txt");
    if (!StringIn)
    {
        cout << "Error! The File can't be read";
        return -1;
    }
    else
    {
        int i;
        cout << "Input String: ";
        char *Line = new char[n];
        StringIn.getline(Line, n + 1);
        cout << Line << endl;
        for (i = 0; Line[i] != '\0'; i++);
        int j(0);
        int t(0);
        while (j <= i) {
            int k(0);
            bool flag(false);
            while ((k <= 11) && !flag)
            {
                if (Line[j] == Vowel_Letters[k])
                {
                    if ((0 <= k) && (k <= 5))
                        k = k + 6;
                    StringOut[t] = Line[j];
                    StringOut[t + 1] = 's';
                    StringOut[t + 2] = Vowel_Letters[k];
                    t = t + 3;
                    flag = true;
                }
                k++;
            }
            if (!flag)
            {
                StringOut[t] = Line[j];
                t = t + 1;
            }
            j++;
        }
        cout << "Output String: " << StringOut << endl;
        ofstream Out("C:\\1\\StringOut.txt");
        if (!Out)
        {
            cout << "Error! The File can't be open";
            return -1;
        }
        else
        {
            Out << StringOut << endl;
        }
    }

    cout << "    Decryption    " << endl;
    const int m(3*n);
    char StringOut_1[n];
    int i;

    ifstream Out("C:\\1\\StringOut.txt");
    if (!Out)
    {
        cout << "Error! The File can't be open";
        return -1;
    }
    else
    {
        cout << "Input String: ";
        char *Line = new char[m];
        Out.getline(Line, m+1);
        cout << Line << endl;
        for (i = 0; Line[i] != '\0'; i++);
        int j(0);
        int t(0);
        while (j <= i) {
            int k(0);
            bool flag(false);
            while ((k <= 11) && !flag) {
                if (Line[j] == Vowel_Letters[k]) {
                    StringOut_1[t] = Line[j];
                    t = t + 1;
                    flag = true;
                }
                k++;
            }
            if (!flag) {
                StringOut_1[t] = Line[j];
                t = t + 1;
                j++;
            } else j = j + 3;
        }
        cout << "Output String: " << StringOut_1 << endl;
    }
}