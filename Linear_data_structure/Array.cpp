#include <iostream>
#include<windows.h>
using namespace std;
template <class t>

class Array
{
private:
    int size; //the size of all of the array
    int length;   //the current number of elements that array contains
    t*arr;

public:
  Array(int size_arr = 10){

        size = size_arr;
        arr = new t[size];
        length = 0;
    }
  void insert_end(t item)
  {
      if(isFull()) {cout<<"Oops!! >> there is no area to insert\n";Sleep(1000); return;}
      arr[length++]=item;
  }

  void delete_item(int pos)
  {
      if(isEmpty())
      {
          cout<<"The array is empty!.\n";
          Sleep(1000);
          return;
      }
      if(pos>size-1||pos<0)
      {
          cout<<"The Position you entered out of pounds !!\n";
          Sleep(1000);
          return;
      }
      for(int i=pos;i<length;i++)
      {
        arr[i]=arr[i+1];
      }
      length-=1;
  }
  void insertAt(t item,int pos)
  {
      if(isFull()) {cout<<"Oops!! >> there is no area to insert\n"; Sleep(1000); return;}
      if(pos > length || pos < 0)
      {
          cout<<"The Position you entered out of pounds !!\n";
          Sleep(1000);
          return;
      }
      else if(pos==length)
      {
          insert_end(item);
      }

      else
      {

      length++;
      for(int i=length-1;i>pos;i--)
      {
          arr[i]=arr[i-1];
      }
      arr[pos]=item;
  }}
  void Modify(t newValue,int pos)
  {if(isEmpty())
  {
      cout<<"No items found to modify\n";
      Sleep(1000);
      return;
  }
      if(pos>length-1||pos<0)
      {
          cout<<"The Position you entered out of pounds !!\n";
          Sleep(1000);
          return;
      }

      t oldValue=arr[pos];//the value that will be modified
      arr[pos]=newValue;
      cout<<"Modified and the old value is : "<<oldValue<<"\n";
      Sleep(1500);
  }
  int search(t item)
  {
      int pos=-1;

      if(isEmpty()){
        cout<<"The array is empty now\n";
        Sleep(1000);
        return pos;
      }
      for(int i=0;i<length;i++)
      {
          if(arr[i]==item)
          {
              pos=i;
              break;
          }

      }
      return pos;
  }
  void printArray(){

    if(isEmpty()){
        cout<<"No items to view.\n";
        return;
        }
      cout<<"[";
      for(int i=0;i<length;i++)
      {
          cout<<arr[i]<<" ";
      }
      cout<<"]\n";
  }

  bool isFull()
  {
      return length==size;
  }
  bool isEmpty()
  {
      return length==0;
  }
  int getSize()
  {
      return size;
  }
  int getLenth()
  {
      return length;
  }
  void menu()
  {   //user interface
      int choice =-1;
      while(choice!=0)
      {
      system("cls");
      cout<<" Length >> "<<getLenth()<<" : Size >> "<<getSize()<<"\n";
      printArray();
      string option="1. Insert at end\n2. Insert at position\n3. Delete item\n4. Modify item\n5. Search\n0. End\n";
      cout<<option<<"choose an option : ";

      cin>>choice;
      switch(choice)
      {
    case 1:
        {t item;
        cout<<"enter the item value : "; cin>> item;
        insert_end(item);
        }
        break;
    case 2:
        {int pos; t item;
         cout<<"enter the item value : "; cin>> item; cout<<" The position : "; cin>>pos;
         insertAt(item,pos);
        }
        break;
    case 3:
        {int pos;
        cout<<" The position : "; cin>>pos;
        delete_item(pos);
        }
        break;
    case 4:
      {int pos; t item;
       cout<<"enter the new value : "; cin>> item; cout<<" The position : "; cin>>pos;
       Modify(item,pos);
       }
       break;
    case 5:
        {t item;
        cout<<"enter the item value : "; cin>> item;
        int i=search(item);
        if(i!=-1) cout<<"Found at ["<<i<<"]\n";
        else cout<<"Not found\n";
        Sleep(1500);
        }
        break;
    case 0:
        cout<<"Good bye\n";
    break;
    default: {cout<<"invalid option\n"; Sleep(1000);}
      }

  }
  }



    ~Array(){
        delete [] arr;
    }
};
int main()
{
  Array <int> array;
  array.menu();

    return 0;
}
