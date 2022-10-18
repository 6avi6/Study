#include <iostream>


using namespace std;
int main()
{
    string text = "ALA MA KOTA";

    std::cout <<text<<text.size() << std::endl;

    const int height{ 3 }, width{ 11 };
    char table[height][width];
  

    //szyfrowanie
    bool height_bounc = false;

    
    

    int i{ 0 };

     for (int k = 0; k <= height; k++) {

                
                
                if (height_bounc == true) {
                    k = k-2;
                    

                }
                if (k <= 0) {
                    height_bounc = false;
                    k = 0;
                    
                }
                //chodzi wezyk gora dol 
                table[k][i] = text[i];
                cout << i << " : " << k << endl;
                
                
                
                
                
                if (k == height - 1) {
                    height_bounc = true;
                    //k = k -1;
                }
                
                i++;
                if (i == width)
                {
                    k = height + 2;
                }
                

            
        
    }



     for (int i = 0; i < height; i++) {
         for (int k = 0; k < width; k++) {
             cout << " " << table[i][k]<<" ";
         }
     cout<<endl;
     }
    std::cout << "End!\n";
    
}


