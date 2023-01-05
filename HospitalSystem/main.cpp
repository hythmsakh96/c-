#include <iostream>
#include <string>
#include <stdlib.h>

std::string reservation[20][5];
int counter[20];

int main(void)
{
    int spec=0,choice=0;
    int status=0;
    std::string name;
    while(1)
    {
        system("clear");
        std::cout<<"Enter your choice:\n1) Add new patient\n2) Print all patients\n3) Get next patient\n4) Exit\n\t:";
        std::cin>>choice;
        std::cout<<choice<<std::endl;
        system("clear");
        std::cout<<"=============================================================================================================================\n";
        switch (choice)
        {
        case 1:
                system("clear");
                std::cout<<"=============================================================================================================================\n";
                // read the specializtion
                std::cout<<"Enter the specialization you want:"<<std::endl;
                std::cin>>spec;
                // verify the specializtion
                while(spec<1 || spec>20)
                {
                    system("clear");
                    std::cout<<"=============================================================================================================================\n";
                    std::cout<<"Try again, Enter the specialization you want:"<<std::endl;
                    std::cin>>spec;
                }
                // read the name and status
                std::cout<<"Enter your name:"<<std::endl;
                std::getline(std::cin, name);
                std::getline(std::cin, name);
                std::cout<<"Enter your status(0 for regular, 1 for urgent):"<<std::endl;
                std::cin>>status;
                while(status!=0 && status!=1)
                {
                    std::cout<<"Try again, Enter your status:"<<std::endl;
                    std::cin>>status;
                }
                // if 5 patients exist apologise
                if(counter[spec]>=5)
                return 0;

                // if the user is regular or urgent
                switch(status)
                {
                    case 0:
                    reservation[spec][counter[spec]++]=name; 
                    break;
                    case 1:
                    // shift the list
                    for(int i=counter[spec];i>0;i--)
                    {
                        reservation[spec][i] = reservation[spec][i-1];
                    }
                    reservation[spec][0]=name;
                    counter[spec]++;
                    break;
                }

            break;
        
        case 2:
            

        break;
       case 3:

        break;
       case 4:
            return 0;
        break;

        default:
            break;
        }
    }
    return 0;
}