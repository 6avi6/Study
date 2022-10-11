#include <iostream>

int main()
{
  

    const int x = 20;
    
    int table[x];
    
    time_t t;
    //tworzenie tablicy z losowymi cyframi od 0 do 100
    srand((unsigned)time(&t));
    for (int i = 0; i < x; i++) {
        table[i] = rand() % 101;
    }

    //wyświetlanie tablicy
    srand((unsigned)time(&t));
    for (int i = 0; i < x; i++) {
        std::cout << i+1 << ") " << table[i] << std::endl;
    }

    //sort
    int i = 0,k;
    while (i<x-1)
    {
        if (table[i] > table[i + 1]) {
            k=table[i];
            table[i] = table[i + 1];
            table[i + 1] = k;
            i = 0;
        }
        if (table[i] <= table[i + 1]) {
            i++;
        }
    }



    //wyświetlanie tablicy
    srand((unsigned)time(&t));
    for (int i = 0; i < x; i++) {
        std::cout<<i+1<<") " << table[i] << std::endl;
    }


    
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
