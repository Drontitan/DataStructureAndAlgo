#include <bits/stdc++.h>
using namespace std;


map<string, double> items = {
    { "Samsung", 15000 },
    { "Redmi", 12000 },
    { "Apple", 100000 },
    { "Macbook", 250000 },
    { "HP", 40000 },
    { "Lenovo", 35000 },
    { "C", 1000 },
    { "C++", 3000 },
    { "Java", 4000 },
    { "Python", 3500 }
};
map<string, int> selected_items;


class Ecommerce{

    public:

void printbill(){
    double total_amoun;
     
     for(auto ele : selected_items){
        auto quantity = ele.second;
        auto item  = ele.first;
        total_amoun += quantity*items[item];
     }
    
     for(auto ele : selected_items){
        auto quantity = ele.second;
        auto item  = ele.first;
        cout<<"item name : "<<" "<<item<<"amount :"<<" "<<quantity*items[item]<<endl;
     }

     cout<<"The total amount is : "<<" "<<total_amoun<<endl;

}

void show_menu(){
    cout<<"The all the available items are as follows : "<<endl;
    for(auto ele: items){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
}

void selectmenu(){
    cout<<"Select the menu from the above list "<<endl;
    string str;
    
    cin>>str;

    cout<<"select the quantity  u want "<<endl;
    int  quantity;
    cin>>quantity;
    selected_items[str]=quantity;

}

};


int main(){

    Ecommerce e;

    cout<<"Welcome to the online shopping :"<<endl;
   int flag=0;
   do
   {
    cout<<"Enter the choice from the following options :-1)exit 1) showmenu , 2)selectmenu ,3) printbill "<<endl;
    int ch;
    cin>>ch;
    switch (ch)
    {
    case 1:
            e.show_menu();
        break;
    
    case 2:
            e.selectmenu();
        break;
    
    case 3:
            e.printbill();
        break;
    default:
        break;
    }

    if(ch==-1)break;


    } while (true); 

}