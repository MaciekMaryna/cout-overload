/******************************************************************************
 * 
 * 
 * 
 ******************************************************************************/

#include <iostream>
#include <string>
#include <stdint.h>

// namespace simpledb
// {
constexpr uint16_t MaxNumberOfItems {10};

class Item
{
    uint16_t IdNumber;
    std::string FirstName;
    std::string LastName;
    std::string HomeAddress;
    
    static uint16_t NumberOfItems;
    friend std::ostream  & operator<< (std::ostream &os, const Item &obj);    

public:

    Item(std::string, std::string);
    ~Item();
    void Show(); //niech zwraca std::string //toString zamiast Show()
    Item &operator= (const Item &);  

};

/*******************************************************************************
* 
******************************************************************************/
Item::Item(std::string fn, std::string ln)  
{
    FirstName = fn;
    LastName = ln;    

    IdNumber = NumberOfItems;
    NumberOfItems++;
    
    std::cout << "Common constructor works\n\n";
}

Item::~Item()
{
    std::cout << "Bye...\n";
}

void Item::Show()
{
    std::cout << "ID:         " << IdNumber << std::endl;
    std::cout << "First name: " << FirstName << std::endl;
    std::cout << "Last name:  " << LastName << std::endl << std::endl;
}

Item & Item::operator= (const Item &Data)
{
    this -> FirstName = Data.FirstName;
    this -> LastName = Data.LastName;
    return *this;
}

// } /* namespace simpledb */

// using namespace simpledb;

std::ostream  & operator<< (std::ostream &os, const Item &obj) 
{
    os << "Fitst name: "<< obj.FirstName << 
        " , Last name: " << obj.LastName;
    return os;
}

uint16_t Item::NumberOfItems = 0;

/*******************************************************************************
* Main function
*******************************************************************************/
int main()
{
    Item MyItem1("Albert", "Einstein");
    Item MyItem2("Nicolae", "Tesla");
    //Item MyItem3(MyItem2);

    MyItem1.Show();
    MyItem2.Show();
    
    Item MyItem3("Thomas", "Edison");
    MyItem3.Show();
    MyItem3 = MyItem2;
    MyItem3.Show();

    //cout << (MyItem3 << 1);
    
    return 0;
}

/*******************************************************************************
* TODO
*   - Konstruktor kopiujący do kompletu + Destryktor : "Zasada trzech" lub "Zasada pięciu"
*   - Przestudiować koncepcję referencji w zestawieniu ze wskaźnikami
*   - Dlaczego friend nie ma dostępu do pól prywantnych? Coś nie tak z namespace
*   - Zlikwidować funkcję Show żeby. Klasa ma zwracać (w miejsce gdzie jest wywołana) obiekt. 
    Inna warstwa ma zająć się wyświetleniem tego, co ona zwróciła. Bez tego koncepcja zapisu 
    "cout<<a<<b;" nie ma sensu.
*
*******************************************************************************/