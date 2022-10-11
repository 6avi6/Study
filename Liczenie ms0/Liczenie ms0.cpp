#include <iostream>
#include <math.h>

int main()
{
    float a=2, b=0, c = 0;
    //wprowadzanie
    std::cout << "Liczymy :Ax^2+Bx+C=0\n";
    std::cout << "Podaj A:\n";
    std::cin >> a;
    std::cout << "Podaj B:\n";
    std::cin >> b;
    std::cout << "Podaj C:\n";
    std::cin >> c;

    std::cout <<std::endl<< a<<"x(^2)+ "<<b<<"x+ "<<c << std::endl << std::endl;


    
    //kwadratowa funkcja
    if (a != 0) {

        float delta = (b * b) - 4 * (a * c);

        if (delta > 0) {
            

            float x1 = (-b - sqrt(delta)) /( 2 * a);
            float x2 = (-b + sqrt(delta)) / (2 * a);

            std::cout << " Dwa miejsca zerowe: " << std::endl;
            std::cout <<"x1 = " << x1 << std::endl;
            std::cout <<"x2 = " << x2 << std::endl;
        }
        else if (delta == 0) {
            float x = (-b ) / (2 * a);
            std::cout << "Jedno miejsce zerowe x = " << x << std::endl;
        
        }
        else if (delta < 0) {
            std::cout << "Brak rozwian!" << std::endl;
        }

    }
    //liniowa
    else if (a == 0 && b!=0) {
        std::cout << "Wynik jest rowny x: " << (-c) / b << std::endl;
    }
    

    else if (a == 0 && b == 0) {
        std::cout << "Brak rozwiazan" << std::endl;
    }

    else if (a == 0 && b == 0 && c == 0) {
        std::cout << "Nieskoczenie wiele rozwiazan" << std::endl;
    }



    return 0;
}

