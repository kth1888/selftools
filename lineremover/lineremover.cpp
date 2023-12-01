#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string line;

    string input;

    int *p1;
    int interval;
    int amount;
    int *p2;

    // Setting the size of each inputs

    cout << "set interval : ";

    cin >> interval;

    p1 = new int[interval];

    cout << "how many lines to delete? : ";

    cin >> amount;

    p2 = new int[amount];

    cin.ignore();

    cout << "select line location to delete : ";

    getline(cin, input);
    stringstream inputint(input);

    int num;
    int count = 0;

    while (inputint >> num)
    {
        cout << num << "th selected"
             << "\n";
        if (count < amount)
        {
            p2[count] = num;
            count++;
        }
    }

    // File I/O

    int filelength = 0;
    ifstream file("/Users/copy/Copy/Projects/selftools/lineremover/songs.txt");

    if (file.is_open())
    {
        cout << "file opened"
             << "\n";
        while (getline(file, line))
        {
            filelength++;
        }
    }
    else
    {
        cout << "File not found!"
             << "\n";
        return 0;
    }

    cout << filelength << " lines detected"
         << "\n";

    // Counting bundles

    int sacks = filelength / interval;

    cout << sacks << " bundles"
         << "\n";

    // Writing files
    ifstream existfile("/Users/copy/Copy/Projects/selftools/lineremover/songs.txt");
    ofstream newfile("/Users/copy/Copy/Projects/selftools/lineremover/modified.txt");

    int index = 1;

    int hardcoding[] = {3, 6};

    if (newfile.is_open())
    {
        int innercount = 0;
        while (getline(existfile, line))
        {
            int indexmodulo = index % 7;
            if (indexmodulo == hardcoding[0] || indexmodulo == hardcoding[1])
            {
                newfile << line << "\n";

                innercount++;
                if (innercount % 2 == 0)
                {
                    newfile << "\n";
                    innercount = 0;
                }
            }
            index++;
        }
    }
    else
    {
        cout << "File not found!"
             << "\n";
        return 0;
    }

    // deallocate pointer variables
    delete[] p1;
    delete[] p2;

    return 0;
}

// References
/*
https://datahub.tistory.com/15
https://zetawiki.com/wiki/C%2B%2B_%EB%AC%B8%EC%9E%90%EC%97%B4_%EB%B0%B0%EC%97%B4
https://yeolco.tistory.com/107
https://eclipse360.tistory.com/97
https://namwhis.tistory.com/entry/cin%EA%B3%BC-getline%EC%9D%84-%EA%B0%99%EC%9D%B4-%EC%82%AC%EC%9A%A9%ED%95%A0%EB%95%8C-cinignore%EC%9D%B4-%ED%95%84%EC%9A%94%ED%95%9C-%EC%9D%B4%EC%9C%A0-%EA%B8%B0%EB%A1%9D









*/