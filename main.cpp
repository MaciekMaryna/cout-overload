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
    friend std::ostream  & operator<< (std::ostream &os, const Item *obj);   

public:

    Item(std::string, std::string);

    //  3_Rule
    ~Item();
    Item(const Item &);
    Item &operator= (const Item &);  

    // std::ostream ToString();
    //void Show(); //niech zwraca std::string //toString zamiast Show()

};

/*******************************************************************************
*  The rule of three
********************************************************************************    
*    If a class requires a user-defined-
*       - destructor, 
*       - copy constructor, or 
*       - copy assignment operator, 
*    it almost certainly requires all three. 
******************************************************************************/

Item::Item(std::string fn, std::string ln)  
{
    FirstName = fn;
    LastName = ln;    
    IdNumber = NumberOfItems;
    NumberOfItems++;
    
    std::cout << "Common constructor works: " << NumberOfItems << std::endl;
}

Item::~Item()
{
    std::cout << "Bye: " << NumberOfItems-- << std::endl;
}

Item::Item(const Item &ObjectToCopy) 
{
    this -> FirstName = ObjectToCopy.FirstName;
    this -> LastName = ObjectToCopy.LastName;    
    this -> IdNumber = NumberOfItems;
    NumberOfItems++;  
    std::cout << "Copy constructor works: " << NumberOfItems << std::endl;   
}

Item & Item::operator= (const Item &Data)
{
    this -> FirstName = Data.FirstName;
    this -> LastName = Data.LastName;
    
    std::cout << "Assignment operator works: " << NumberOfItems << std::endl;   
    return *this;
}

// } /* namespace simpledb */
// using namespace simpledb;

std::ostream  & operator<< (std::ostream &os, const Item &obj) 
{
    os  << "ID: " << obj.IdNumber 
        << ", FIRST_NAME: "<< obj.FirstName 
        << ", LAST_NAME: " << obj.LastName;

    return os;
}

std::ostream  & operator<< (std::ostream &os, const Item *obj)
{
        os  << "ID*: " << obj -> IdNumber 
            << ", FIRST_NAME*: "<< obj -> FirstName 
            << ", LAST_NAME*: " << obj -> LastName;
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
    Item MyItem3("Thomas", "Edison");

    std::cout   << "MyItem1: " << MyItem1 << std::endl 
                << "MyItem2: " << MyItem2 << std::endl
                << "MyItem3: " << MyItem3 << std::endl;

    Item MyItem4 = MyItem3;

    Item MyItem5("-", "-");
    MyItem5 = MyItem1;

    std::cout   << "MyItem1: " << MyItem1 << std::endl 
                << "MyItem2: " << MyItem2 << std::endl
                << "MyItem3: " << MyItem3 << std::endl
                << "MyItem4: " << MyItem4 << std::endl
                << "MyItem5: " << MyItem5 << std::endl;

    Item * pItem = &MyItem1;

    std::cout   << std::endl << "MyItem1: " << pItem << std::endl;

    return 0;
}

/*******************************************************************************
* 4.07.2024
* TODO
*   OK  - Konstruktor kopiujący do kompletu + Destryktor : "Zasada trzech" lub "Zasada pięciu"
*   OK  - Przestudiować koncepcję referencji w zestawieniu ze wskaźnikami
*   ??  - Dlaczego friend nie ma dostępu do pól prywantnych? Coś nie tak z namespace
*   OK  - Zlikwidować funkcję Show. Klasa ma zwracać (w miejsce gdzie jest wywołana) obiekt. 
*           Inna warstwa ma zająć się wyświetleniem tego, co ona zwróciła. Bez tego koncepcja zapisu 
*           "cout<<a<<b;" nie ma sensu.
*
* 11.07.2024 
    Q:
*   - 3_Rule - po co, żeby miec? Nie mam żadnych obiektów tworzonych dynamicznie, 
*    pliów ani innych zasobów. A skoro tak to co powinny zawirać?
*   - 5_Rule - co to jest semantyka ruchu (move?)
*
* 12.07.2024
*   TODO
*    -
*    -
*    -
*    -
*    -
*    -
*******************************************************************************/