/******************************************************************************
 * 
 * https://cpp0x.pl/artykuly/Inne-artykuly/Przeciazanie-operatorow-w-C++/15
 * 
 ******************************************************************************/

#include <iostream>
#include <string.h>
#include <stdint.h>

namespace simpledb
{
constexpr uint16_t MaxNumberOfItems {10};

class Item
{
    
    uint16_t IdNumber;
    char* FirstName;
    char* LastName;
    char* HomeAddress;
    
    static uint16_t NumberOfItems;

public:

    Item(char *, char *);
    ~Item();
    void Show();
    Item &operator= (const Item &);  
    friend std::ostream  & operator<< (std::ostream &os, const Item &obj);
};

/*******************************************************************************
*
******************************************************************************/
Item::Item(char *fn, char *ln)  
{
    FirstName = new char[strlen(fn) + 1];
    LastName = new char[strlen(ln) + 1];    

    strcpy(FirstName, fn);
    strcpy(LastName, ln);

    IdNumber = NumberOfItems;
    NumberOfItems++;
    
    std::cout << "Common constructor works\n";
}

Item::~Item()
{
    for (auto i = 0; i < Item::NumberOfItems; i++)
    {
        std::cout << i << std::endl;
    }
    std::cout << "\nBye...\n";
}

void Item::Show()
{
    std::cout << "ID:         " << IdNumber << std::endl;
    std::cout << "First name: " << FirstName << std::endl;
    std::cout << "Last name:  " << LastName << std::endl << std::endl;
}

Item &Item::operator= (const Item &Data)
{
    this -> FirstName = Data.FirstName;
    this -> LastName = Data.LastName;
    return *this;
}
} /* namespace simpledb */

std::ostream  & operator<< (std::ostream &os, const simpledb::Item &obj) 
{
    os << "Fitst name: "<< obj.FirstName << 
        " , Last name: " << obj.LastName;
    return os;
}

using namespace simpledb;

uint16_t Item::NumberOfItems = 0;

/*******************************************************************************
* Main function
******************************************************************************/
int main()
{

    Item MyItem1("Albert", "Einstein");
    Item MyItem2("Nicolae", "Tesla");
    
    MyItem1.Show();
    MyItem2.Show();
    
    Item MyItem3("Thomas", "Edison");
    MyItem3.Show();
    MyItem3 = MyItem2;
    MyItem3.Show();

    return 0;
}