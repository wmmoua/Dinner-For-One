/***************************************
Dinner For One
Author: Well Moua
Date Created: 9/30/19
Description: In this program, the user will try to input in their order or custom order if they enter a combo. 
***************************************/

#include <iostream>
using namespace std;

class ComboInstance
{
    private:
    string Entree;
    string Side;
    float Cost;
    string Drink;
    int Size;
    string SizeDescribed;
    
    public:
    ComboInstance(string e, string s, float c) : Drink("Coke"), Size(1)
    {
        Entree = e;
        Side = s;
        Cost = c;
    }

    void display(int ComboNumber)
    {
        cout<<endl<<"Combo "<<ComboNumber<<endl;
        cout<<"Entree: "<<Entree<<endl;
        cout<<"Side: "<<Side<<endl;
        cout<<"Price: $"<<Cost<<endl;        
    }

    // Setter
    void setDrink(string newDrink)
    {
        Drink = newDrink;
    }

    void setSize(int newSize)
    {
        Size = newSize;
    }
    
    void setEntree(string newEntree)
    {
        Entree = newEntree;
    }

    void setSide(string newSide)
    {
        Side = newSide;
    }
    void setSizeDescribed(string newSizeDescribed)
    {
        SizeDescribed = newSizeDescribed;
    }

    // Getter
    string getDrink()
    {
        return Drink;
    }
    
    int getSize()
    {
        return Size;
    }
    
    string getEntree()
    {
        return Entree;
    }
    
    string getSide()
    {
        return Side;
    }
    
    float getCost()
    {
        return Cost;
    }
    string getSizeDescribed()
    {
        return SizeDescribed;
    }

};

// Function of which user will choose which combo they want.
ComboInstance pickAcombo()
{
    // list of combo that has been created already.
    ComboInstance Combo1("Hamburger", "Fries", 5.99);
    ComboInstance Combo2("Burrito", "Fries", 4.99);
    ComboInstance Combo3("Salad", "Rice", 4.49);
    ComboInstance Combo4("Entree", "Side", 6.99);

    // Output the way a drive-thru would do.
    cout<<"Welcome to Ecletic Drive-Thru. What would you like to order?"<<endl;
    Combo1.display(1);
    Combo2.display(2);
    Combo3.display(3);
    cout<<endl<<"Combo 4"<<endl;
    cout<<"Custom Order"<<endl;
    cout<<"Price: $6.99"<<endl;

    // User input in their order.
    int ComboSelected;
    cout<<endl<<"Please select your order: ";
    cin>>ComboSelected;
    
    // If/else statement is used of which user inputed the order they want returning that order list.
    if (ComboSelected == 1)
    {
        return Combo1;
    }
    else if (ComboSelected == 2)
    {
        return Combo2;
    }
    else if (ComboSelected == 3)
    {
        return Combo3;
    }
    else
    {
        string UserEntree;
        string UserSide;
        cout<<endl<<"Please enter an entree: ";
        cin>>UserEntree;
        cin.ignore();
        Combo4.setEntree(UserEntree);
        cout<<endl<<"Please enter a side: ";
        cin>>UserSide;
        cin.ignore();
        Combo4.setSide(UserSide);
        return Combo4;
    }
}

// Function which it will be called to make user choose size of cup they want. 
int pickAsize()
{
    // User input for their size they wanted.
    int sizePicked;
    string sizedChosed;
    cout<<endl<<"Size Upgrade prices: Small $0, Medium $2, Large $3"<<endl;
    cout<<"What size would you like? (1 = Small, 2 = Medium, 3 = Large)"<<endl;
    cin>>sizePicked;
    if (sizePicked == 3)
    {
        sizePicked = 3;
        return sizePicked;
    }
    else if (sizePicked == 2)
    {
        sizePicked = 2;
        return sizePicked;
    }
    else
    {
        sizePicked = 1;
        return sizePicked;
    }
}

// Function of which User will decide on their drink.
string pickAdrink()
{
    // Tell user to pick what drink they want and ask them to input.
    string newDrink;
    cout<<"What would you like to drink (Leave blank to to keep Coke as default)"<<endl;
    cin.ignore();
    getline(cin, newDrink);
    if (newDrink == "")
    {
        newDrink = "Coke";
        return newDrink;
    }
    return newDrink;
}


int main()
{ 
    // created a new combo which holds stores the combo that user order.
    ComboInstance selected = pickAcombo();
    
    // Used the new combo and set the size to be different from small or just small itself.
    int sizePicked = pickAsize();
    selected.setSize(sizePicked);

    // Used the new combo and set the drink to be not Coke or it can be coke if they leave blank.
    string drinkPicked = pickAdrink();
    selected.setDrink(drinkPicked);
    
    // Display the reciept of what the user ordered.
    cout<<endl<<"Here is your order: "<<endl;
    cout<<"Entree: "<<selected.getEntree()<<endl;
    cout<<"Side: "<<selected.getSide()<<endl;
    cout<<"Size: "<<selected.getSize()<<endl;
    cout<<"Drink: "<<selected.getDrink()<<endl;
    cout<<"Price: $"<<(selected.getCost() + selected.getSize())<<endl;
    return 0;
}