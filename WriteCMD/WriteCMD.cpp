#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>

using namespace std;
vector <vector<string>>alphabet;

void creat_alphabet();

typedef vector<string> CommandLineStringArgs;

int main(int argc, char* argv[1] )
{
    *argv[0] = 'A';
    CommandLineStringArgs text(&argv[0], &argv[0 + argc]);
    creat_alphabet();

    string abc = "ABCDEFGHIJKLMNOPQRTSUVWXYZ";
    
    abc = "ABC";
    abc = "ILONA";
   
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    for (int k = 0; k < 7; ++k)
    {
    for (int i = 0; i < abc.size(); ++i)
    {
        SetConsoleTextAttribute(hConsole, k+1);

            
        cout << alphabet[((int)abc[i]) - 65][k];
        }
    cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 10);
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(2));
    
}





void creat_alphabet() {
    alphabet.resize(26);
    alphabet[0].push_back("           ");
    alphabet[0].push_back("     /\\    ");
    alphabet[0].push_back("    /  \\   ");
    alphabet[0].push_back("   / /\\ \\  ");
    alphabet[0].push_back("  / ____ \\ ");
    alphabet[0].push_back(" /_/    \\_\\");
    alphabet[0].push_back("           ");

    alphabet[1].push_back("  ____  ");
    alphabet[1].push_back(" |  _ \\ ");
    alphabet[1].push_back(" | |_) |");
    alphabet[1].push_back(" |  _ < ");
    alphabet[1].push_back(" | |_) |");
    alphabet[1].push_back(" |____/ ");
    alphabet[1].push_back("        ");

    alphabet[2].push_back("   _____ ");
    alphabet[2].push_back("  / ____|");
    alphabet[2].push_back(" | |     ");
    alphabet[2].push_back(" | |     ");
    alphabet[2].push_back(" | |____ ");
    alphabet[2].push_back("  \\_____|");
    alphabet[2].push_back("         ");

    alphabet[3].push_back("  _____  ");
    alphabet[3].push_back(" |  __ \\ ");
    alphabet[3].push_back(" | |  | |");
    alphabet[3].push_back(" | |  | |");
    alphabet[3].push_back(" | |__| |");
    alphabet[3].push_back(" |_____/ ");
    alphabet[3].push_back("         ");

    alphabet[4].push_back("  ______ ");
    alphabet[4].push_back(" |  ____|");
    alphabet[4].push_back(" | |__   ");
    alphabet[4].push_back(" |  __|  ");
    alphabet[4].push_back(" | |____ ");
    alphabet[4].push_back(" |______|");
    alphabet[4].push_back("         ");

    alphabet[5].push_back("  ______ ");
    alphabet[5].push_back(" |  ____|");
    alphabet[5].push_back(" | |__   ");
    alphabet[5].push_back(" |  __|  ");
    alphabet[5].push_back(" | |     ");
    alphabet[5].push_back(" |_|     ");
    alphabet[5].push_back("         ");

    alphabet[6].push_back("   _____ ");
    alphabet[6].push_back("  / ____|");
    alphabet[6].push_back(" | |  __ ");
    alphabet[6].push_back(" | | |_ |");
    alphabet[6].push_back(" | |__| |");
    alphabet[6].push_back("  \\_____|");
    alphabet[6].push_back("         ");

    alphabet[7].push_back("  _    _ ");
    alphabet[7].push_back(" | |  | |");
    alphabet[7].push_back(" | |__| |");
    alphabet[7].push_back(" |  __  |");
    alphabet[7].push_back(" | |  | |");
    alphabet[7].push_back(" |_|  |_|");
    alphabet[7].push_back("         ");

    alphabet[8].push_back("  _____ ");
    alphabet[8].push_back(" |_   _|");
    alphabet[8].push_back("   | |  ");
    alphabet[8].push_back("   | |  ");
    alphabet[8].push_back("  _| |_ ");
    alphabet[8].push_back(" |_____|");
    alphabet[8].push_back("        ");

    alphabet[9].push_back("       _ ");
    alphabet[9].push_back("      | |");
    alphabet[9].push_back("      | |");
    alphabet[9].push_back("  _   | |");
    alphabet[9].push_back(" | |__| |");
    alphabet[9].push_back("  \\____/ ");
    alphabet[9].push_back("         ");

    alphabet[10].push_back("  _  __");
    alphabet[10].push_back(" | |/ /");
    alphabet[10].push_back(" | ' / ");
    alphabet[10].push_back(" |  <  ");
    alphabet[10].push_back(" | . \\ ");
    alphabet[10].push_back(" |_|\\_\\");
    alphabet[10].push_back("       ");

    alphabet[11].push_back("  _      ");
    alphabet[11].push_back(" | |     ");
    alphabet[11].push_back(" | |     ");
    alphabet[11].push_back(" | |     ");
    alphabet[11].push_back(" | |____ ");
    alphabet[11].push_back(" |______|");
    alphabet[11].push_back("         ");

    alphabet[12].push_back("  __  __ ");
    alphabet[12].push_back(" |  \\/  |");
    alphabet[12].push_back(" | \\  / |");
    alphabet[12].push_back(" | |\\/| |");
    alphabet[12].push_back(" | |  | |");
    alphabet[12].push_back(" |_|  |_|");
    alphabet[12].push_back("         ");

    alphabet[13].push_back("  _   _ ");
    alphabet[13].push_back(" | \\ | |");
    alphabet[13].push_back(" |  \\| |");
    alphabet[13].push_back(" | . ` |");
    alphabet[13].push_back(" | |\\  |");
    alphabet[13].push_back(" |_| \\_|");
    alphabet[13].push_back("        ");

    alphabet[14].push_back("   ___  ");
    alphabet[14].push_back("  / _ \\ ");
    alphabet[14].push_back(" | | | |");
    alphabet[14].push_back(" | | | |");
    alphabet[14].push_back(" | |_| |");
    alphabet[14].push_back("  \\___/ ");
    alphabet[14].push_back("        ");

    alphabet[15].push_back("  _____  ");
    alphabet[15].push_back(" |  __ \\ ");
    alphabet[15].push_back(" | |__) |");
    alphabet[15].push_back(" |  ___/ ");
    alphabet[15].push_back(" | |     ");
    alphabet[15].push_back(" |_|     ");
    alphabet[15].push_back("         ");

    alphabet[16].push_back("   ____  ");
    alphabet[16].push_back("  / __ \\ ");
    alphabet[16].push_back(" | |  | |");
    alphabet[16].push_back(" | |  | |");
    alphabet[16].push_back(" | |__| |");
    alphabet[16].push_back("  \\___\\_\\");
    alphabet[16].push_back("         ");

    alphabet[17].push_back("  _____  ");
    alphabet[17].push_back(" |  __ \\ ");
    alphabet[17].push_back(" | |__) |");
    alphabet[17].push_back(" |  _  / ");
    alphabet[17].push_back(" | | \\ \\ ");
    alphabet[17].push_back(" |_|  \\_\\");
    alphabet[17].push_back("         ");

    alphabet[18].push_back("   _____ ");
    alphabet[18].push_back("  / ____|");
    alphabet[18].push_back(" | (___  ");
    alphabet[18].push_back("  \\___ \\ ");
    alphabet[18].push_back("  ____) |");
    alphabet[18].push_back(" |_____/ ");
    alphabet[18].push_back("         ");

    alphabet[19].push_back("  _______ ");
    alphabet[19].push_back(" |__   __|");
    alphabet[19].push_back("    | |   ");
    alphabet[19].push_back("    | |   ");
    alphabet[19].push_back("    | |   ");
    alphabet[19].push_back("    |_|   ");
    alphabet[19].push_back("          ");

    alphabet[20].push_back("  _    _ ");
    alphabet[20].push_back(" | |  | |");
    alphabet[20].push_back(" | |  | |");
    alphabet[20].push_back(" | |  | |");
    alphabet[20].push_back(" | |__| |");
    alphabet[20].push_back("  \\____/ ");
    alphabet[20].push_back("         ");

    alphabet[21].push_back(" __      __");
    alphabet[21].push_back(" \\ \\    / /");
    alphabet[21].push_back("  \\ \\  / / ");
    alphabet[21].push_back("   \\ \\/ /  ");
    alphabet[21].push_back("    \\  /   ");
    alphabet[21].push_back("     \\/    ");
    alphabet[21].push_back("           ");

    alphabet[22].push_back(" __          __");
    alphabet[22].push_back(" \\ \\        / /");
    alphabet[22].push_back("  \\ \\  /\\  / / ");
    alphabet[22].push_back("   \\ \\/  \\/ /  ");
    alphabet[22].push_back("    \\  /\\  /   ");
    alphabet[22].push_back("     \\/  \\/    ");
    alphabet[22].push_back("               ");

    alphabet[23].push_back(" __   __");
    alphabet[23].push_back(" \\ \\ / /");
    alphabet[23].push_back("  \\ V / ");
    alphabet[23].push_back("   > <  ");
    alphabet[23].push_back("  / . \\ ");
    alphabet[23].push_back(" /_/ \\_\\");
    alphabet[23].push_back("        ");

    alphabet[24].push_back(" __     __");
    alphabet[24].push_back(" \\ \\   / /");
    alphabet[24].push_back("  \\ \\_/ / ");
    alphabet[24].push_back("   \\   /  ");
    alphabet[24].push_back("    | |   ");
    alphabet[24].push_back("    |_|   ");
    alphabet[24].push_back("          ");

    alphabet[25].push_back("  ______");
    alphabet[25].push_back(" |___  /");
    alphabet[25].push_back("    / / ");
    alphabet[25].push_back("   / /  ");
    alphabet[25].push_back("  / /__ ");
    alphabet[25].push_back(" /_____|");
    alphabet[25].push_back("        ");






}