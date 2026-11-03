#include "h.h"
int main(){
  
    std::string batch= "";
    std::vector<char> tasks = load_vector
    //("cpu_input_smallTest.txt");
   ("cpu_input_small.txt");
   //("cpu_input_medium.txt");
   //("cpu_input_large.txt");
    std::vector<int> doby ;
    
    int pocetPrvku = velikost(tasks);
    int delkaPoctu = std::to_string(abs(pocetPrvku)).length();
    int number = 0;


    //printf("%d\n", pocetPrvku);
    //printf("%d\n", delkaPoctu);
   
    //std::vector<vector<char>>
    for (int i = delkaPoctu;i < pocetPrvku + delkaPoctu ;i ++)
    {
        if(i % 8 == 0 )
        {
        printf("\n");             
             std::cout <<"V batch je :"<< batch << std::endl;
             //number = round_robin(batch);
             //number = straight_core(batch);  
             number = smart_core(batch) ; 
            // printf("%d", number);
             doby.push_back(number) ;
             batch = "";
            
        }
        //std::cout << tasks[i]<< std::endl;
        //std::cout << batch << std::endl;
    
    batch += tasks[i];
    }
/*
    for (int i = 0;i < doby.size() ;i ++)
    {
        std::cout << doby[i]<< std::endl;
    }   
        */
    TotalTime(doby);
return 0;
}
/*
Funkce straight_core rozdělí úlohy do jader přímo podle typu . Neřeší efektivitu , že jedno jádro dostane hodně úloh a ostatní jádra nepracují .
Funkce smart_core zjistí počet úlohy na typ procesoru a při malém množství funguje jako s straight_core a při vyšším množství rozdělí úlohy podle podmínek efektivněji .


Proměnná HcountR/McountR/LcountR počítá pro podmínku počet využitých stejných úloh .


Opravit rozdělení batche .
*/