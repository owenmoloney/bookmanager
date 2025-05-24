#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class person{
   protected:
   string name;
   int id;
   public:
   person();
   person(string name, int id);
   string const Get_Name();
   int const get_Id();
   void set_Name(string newname);
   void set_wId(int newid);
};

class author : public person{
    private:
    int numberofbooks;
    public:
    author();
    author(string name,int id,int numberofbooks);
    int const getnumberofbooks();
    void setnumberofbooks(int count);
};
class customer : public person{
    public:
    customer();
    customer(string name, int Id);
};
class books{
    private:
    string name;
    string author;
    int id;
    double price;
    public:
    books(string title, int bookid,int authorid, double price);
    string const get_title();
    int const get_book_id();
    int const get_author_id();
    double const get_price();

    void set_title(string title);
    void set_book_id(int id);
    void set_author_id(int aid);
    void set_price(double price);
};
class sale : public books{
    public:
    sale();
    sale( int bookid,int quantity,int cutomerid,double price);
    int const get_book_id();
    int const get_quantity();
    int const get_customerid();
    double const get_price();


    void set_book_id(int id);
    void set_quantity(int quantity);
    void set_customerid(int id);
    void set_price(double price);
};
