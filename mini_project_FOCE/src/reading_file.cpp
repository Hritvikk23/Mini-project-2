#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>


using namespace std;
//=====================================================
bool readFile(const string &fileName, vector<string> &lines)
{
    ifstream file(fileName);

    if (!file)
    {
        return false;
    }

    string line;

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    return true;
}
//=====================================================
vector <string> splitline(const string &line){
    vector<string> field;
    string current;
    bool quotes = false;
    int n = line.size();
    for(int i=0;i<n;i++){
        char c= line[i];
        if(quotes){
            if(c=='\\' && i+1 <n && line[i+1]=='"'){
                current += '"';
                i++;
            }
            else if(c=='"'&&i+1<n&&line[i+1]=='"'){
                current+= '"';
                i++;
            }
            else if(c == '"'){
                quotes = false;
            }
            else{
                current +=c;
            }
        }
        else{
            if (c=='"'){
                quotes=true;
            }
            else if(c==','){
                field.push_back(current);
                current.clear();
            }
            else{
                current +=c;
            }
        }
    }
    field.push_back(current);
    return field;
}

//=====================================================