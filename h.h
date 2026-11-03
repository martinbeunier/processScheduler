#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

std::vector<char> load_vector(const std::string& filename)
{
    std::vector<char> input;
    std::ifstream file(filename);
    char value;
    
    if (!file)
    {
        std::cerr << "File failed to open!" << std::endl;
        return input; 
    }

    while (file >> value)
    {
        input.push_back(value);
    }
    
    return input;
}

int velikost(std::vector<char> tasks)
{

    std::string pocetPrvku;
    //int pocetPrvku2 = 0;
    int i = 0;

    while(i < tasks.size() && tasks[i] >= '0' && tasks[i] <= '9'){
    
    pocetPrvku[i] = tasks[i];

    i++;
    }
    
    int pocetPrvku2 = std::stoi (pocetPrvku);


    return pocetPrvku2;

}

int round_robin(std::string batch)
{   
    int procesorHtime = 0;
    int procesorMtime = 0;
    int procesorLtime = 0;
    for (int i = 0;i < 8 ;i ++)
    { 
        switch(i % 3)
        {
            case(0):
            if (batch[i] == 'H')
            {
                procesorHtime = procesorHtime + 1;
            } else{
                procesorHtime = procesorHtime + 2;
            }
           // std::cout<<i%3<<std::endl
            ; break;

            case(1):
            if (batch[i] == 'M')
            {
                procesorMtime = procesorMtime + 1;
            } else{
                procesorMtime = procesorMtime + 2;
            }

            //std::cout<<i%3<<std::endl; 
            break;
            case(2):
            if (batch[i] == 'L')
            {
                procesorLtime = procesorLtime + 1;
            } else{
                procesorLtime = procesorLtime + 2;
            }


           // std::cout<<i%3<<std::endl;
            break;


        }
    
    }


    int timeLongest = procesorHtime ;
    
    if (timeLongest < procesorMtime )
    {
      timeLongest = procesorMtime ;
    } 
    if (timeLongest < procesorLtime )
    {
      timeLongest = procesorLtime ;
    } 
    
    
    std::cout<< timeLongest << std::endl;

    return timeLongest ;
}
int straight_core(std::string batch){

    int procesorHtime = 0;
    int procesorMtime = 0;
    int procesorLtime = 0;

    for (int i = 0;i < 8 ;i ++)
    { 

            if (batch[i] == 'H')
            {
                procesorHtime = procesorHtime + 1;
            } 
            if (batch[i] == 'M')
            {
                procesorMtime = procesorMtime + 1;
            } 
            if (batch[i] == 'L')
            {
                procesorLtime = procesorLtime + 1;
            } 
    }
    int timeLongest = procesorHtime ;
    
    if (timeLongest < procesorMtime )
    {
      timeLongest = procesorMtime ;
    } 
    if (timeLongest < procesorLtime )
    {
      timeLongest = procesorLtime ;
    } 
    std::cout<< timeLongest << std::endl;
    return timeLongest ;
}

int smart_core(std::string batch)
{

    vector<int> assign ;
    int procesorHtime = 0;
    int procesorMtime = 0;
    int procesorLtime = 0;


    int Hcount = 0;
    int Mcount = 0;
    int Lcount = 0;

    int HcountR = 0;
    int McountR = 0;
    int LcountR = 0;

    int rozdel = 3;


    for (int i = 0;i < 8 ;i ++)
    { 
        if (batch[i] == 'H')
        {
            Hcount = Hcount + 1;
        } 
        if (batch[i] == 'M')
        {
            Mcount = Mcount + 1;
        } 
        if (batch[i] == 'L')
        {
            Lcount = Lcount + 1;
        } 

    }

    if (Hcount > rozdel || Mcount >rozdel || Lcount >rozdel)
    {
    for (int i = 0;i < 8 ;i ++)
    {
        if(batch[i] == 'H' && HcountR > rozdel) //H
        {
            if(Mcount <= 2 )
            {
                assign.push_back(1)  ;
            }
            else
            {
                assign.push_back(2)  ;
            }
            
        
            HcountR = HcountR + 1;
        }else
        {
            if(batch[i] == 'H') 
            {
                assign.push_back(0)  ;
                HcountR = HcountR + 1;
            }
        }                               // H

        if(batch[i] == 'M' && McountR > rozdel) //M
        {
            if(Lcount <= 2 )
            {
                assign.push_back(2)  ;
            }
            else
            {
                assign.push_back(0)  ;
            }
            
        
            McountR = McountR + 1;
        }else
        {
            if(batch[i] == 'M') 
            {  
                assign.push_back(1)  ;
                McountR = McountR + 1;
            }
        }                               //M

        if(batch[i] == 'L' && LcountR > rozdel)//L
        {
            if(Mcount <= 2 )
            {
                assign.push_back(1)  ;
            }
            else
            {
                assign.push_back(0)  ;
            }
            
        
            LcountR = LcountR + 1;
        }else
        {
            if(batch[i] == 'L') 
            {
                assign.push_back(2)  ;
                LcountR = LcountR + 1;
            }
        }                               //L


    }

    std::cout<<"H "<<Hcount<<" M "<<Mcount<<" L "<<Lcount << std::endl;


    for (int i = 0;i < 8 ;i ++)
    { 
        switch(assign[i])
        {
            case(0):
            if (batch[i] == 'H')
            {
                procesorHtime = procesorHtime + 1;
            } else{
                procesorHtime = procesorHtime + 2;
            }
           // std::cout<<i%3<<std::endl
            ; break;

            case(1):
            if (batch[i] == 'M')
            {
                procesorMtime = procesorMtime + 1;
            } else{
                procesorMtime = procesorMtime + 2;
            }

            //std::cout<<i%3<<std::endl; 
            break;
            case(2):
            if (batch[i] == 'L')
            {
                procesorLtime = procesorLtime + 1;
            } else{
                procesorLtime = procesorLtime + 2;
            }


           // std::cout<<i%3<<std::endl;
            break;
        }
    }
    }else{
        for (int i = 0;i < 8 ;i ++)
        { 
    
                if (batch[i] == 'H')
                {
                    procesorHtime = procesorHtime + 1;
                } 
                if (batch[i] == 'M')
                {
                    procesorMtime = procesorMtime + 1;
                } 
                if (batch[i] == 'L')
                {
                    procesorLtime = procesorLtime + 1;
                } 
        }
        
    }


    
    int timeLongest = procesorHtime ;
    
    if (timeLongest < procesorMtime )
    {
      timeLongest = procesorMtime ;
    } 
    if (timeLongest < procesorLtime )
    {
      timeLongest = procesorLtime ;
    } 
    std::cout<< timeLongest << std::endl;
    return timeLongest ;

}



void TotalTime(vector<int> doby ){
    int time = 0;
    int worsttime = 0 ;
    for (int i = 0;i < doby.size() ;i ++)
    {
       time = time + doby[i];
    }   
    for (int i = 0;i < doby.size() ;i ++)
    {
        if (worsttime < doby[i])
        {
            worsttime = doby[i];
        }        
    }  


    float prumer = static_cast<float>(time) / doby.size();

        std::cout << "Celkovy cas :" <<  time <<std::endl;
        std::cout << "Prumerny cas :" <<  prumer <<std::endl;
        std::cout << "nejhorsi cas :" <<  worsttime <<std::endl;
}
