#include <unistd.h>
#include <iostream>
#include <deque>
#include <string>
#include <fstream>

using namespace std;

void loadnotes(deque<string>& notes) {
    ifstream in("zakhire.txt");
    if (!in.is_open()) {
        cerr << "could not open " << "zakhire.txt"
             << " (starting empty)\n";
        return;
    }
    string line;
    while (getline(in, line)) {
        notes.push_back(line);
    }
    in.close();
}

void savenotes(const deque<string>& notes) {
    ofstream out("zakhire.txt", ios::trunc);
    if (!out.is_open()) {
        cerr << "error" << "zakhire.txt" << " for writing!\n";
        return;
    }
    for (const string& note : notes) {
        out << note << "\n";
    }
    out.close();
}

int main()
{
    const char* file = "zakhire.txt";

    if (access(file, F_OK) == 0) {

    } else {
        ofstream out(file);
        out.close();
    }
    cout << "wellcome to opennote\n";
    cout << "rd to read, mk to write note,ex to exit\n";
    deque<string> notes;
    loadnotes(notes);
    while(1 == 1){
        string dastur;
        cin >> dastur;
        string ex = "ex";
        string rd = "rd";
        string mk = "mk";

        if(dastur == ex){
            savenotes(notes);
            break;
        }
        else if(dastur == mk){
            cout << "write your note,then press enter\n";
            string matn;
            cin.ignore();
            getline(cin, matn);
            notes.push_back(matn);
            cout << "what do you want to do? mk or rd?\n";
        }
        else if(dastur == rd){
            cout << "type your wanted note number,then press enter\n";
            int x;
            cin >> x;
            int sznt;
            sznt= notes.size();
            if(notes.empty()){
                cout << "first write note , then read notes!\n";
                continue;
            }
            else if(x <= 0){
                cout << "enter num larger than 0\n";
                continue;
            }
            else if(x > sznt){
                cout << "enter a num,that should be in your range of notes numbers.\n";
                continue;
            }
            else{
                cout << "your wanted note:\n" << notes[x - 1]<<"\n";
                cout << "what do you want to do? mk or rd?\n";
            }
        }
        else{
            cout << "enter mk or rd or ex!";
            continue;


        }
    }

}

