#include <iostream>
#include <vector>
#include "airport_bst.h"
#include "reading_file.h"

using namespace std;
void findcode(const AirportBST &tree, const string &code){
    vector<string> path;
    int comp=0;
    const Airport *a = tree.search(code,path,comp);
    int k = path.size();
    
    cout <<"Find "<<code<<endl;
    cout << "Path ";
    for(int i=0;i<k;i++){
        cout << path[i]<< "->";
    }
    if (a==nullptr){
        cout << "Not found. Comparisions "<<comp<<endl;
    }
    else{
        cout << "Comparisions: "<<comp<<endl;
    }
}
int main()
{
    string fileName = "../data/raw/airports.dat";
    vector<string> lines;

    
    if (!readFile(fileName, lines))
    {
        cout << "Error: cannot open " << fileName << '\n';
        return 1;
    }

    cout << "Read " << lines.size() << " lines.\n";

    vector<string> f= splitline(lines[0]);
    int m = f.size();

    for(int i=0;i<m;i++){
        cout<<i<<": "<<f[i]<<'\n';
    }
    cout << "//====================================================="<<endl;
//=====================================================

    AirportBST tree;    
    vector<Airport> ap;

    int skipped = 0;
    int total = lines.size();
    for(int i=0;i<total;i++){

        vector<string> fields = splitline(lines[i]);

        if (fields.size() < 8 || fields[4]== "\\N"){
            skipped++;
            continue;
        }
        Airport a;
        a.name = fields[1];
        a.city = fields[2];
        a.country = fields[3];
        a.iata = fields[4];
        a.icao = fields[5];
        a.lat = stod(fields[6]);
        a.lon = stod(fields[7]);
        ap.push_back(a);
    }


    int dup =0;
    int n = ap.size();

    for(int i=0;i<n;i++){
        if(!tree.insert(ap[i])){
            dup++;
            cout<<"Duplicate codes: "<<ap[i].iata<<'\n';
        }
    }
    cout <<"Duplicates: "<<dup<<endl;
    cout <<"Skipped: "<<skipped<<endl;
    cout <<"Inserted: "<<tree.size()<<endl;
    cout << "//====================================================="<<endl;
//=====================================================

    cout << "Height: " << tree.height()<<endl;
    cout <<"Avg depth: "<<tree.avg_depth()<<endl;
    cout << "//====================================================="<<endl;

//=====================================================
    cout << "Min " << tree.min()->iata<<endl;
    cout << "Max: "<< tree.max()->iata<<endl;
    cout << "//====================================================="<<endl;
    string deepest;
    int longest =0;
    for(int i=0;i<n;i++){
        vector<string> p;
        int c=0;
        tree.search(ap[i].iata,p,c);
        if(c>longest){
            longest = c;
            deepest = ap[i].iata;
        }
    }
    findcode(tree,ap[0].iata);
    findcode(tree,deepest);
    findcode(tree, "BOS");
    findcode(tree, "XYZ");
    findcode(tree, "000");
    findcode(tree, "ZZZ");

    cout << "//====================================================="<<endl;

//=====================================================
    string code;
    cin>>code;

    if (tree.remove(code)){
        cout << "Deleted: "<<code<<endl;
    }
    else{
        cout<<code<<"Not found"<<endl;
    }
    cout << "//====================================================="<<endl;

    
    return 0;

}
