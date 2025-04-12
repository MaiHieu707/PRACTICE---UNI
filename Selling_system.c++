#include <iostream>
#include <vector>

class Person;
class Customer;
class Order;
class Product;


using namespace std;

class Person{
    private:
        string fullName;
        string phoneNumber;
        string emailAddress;

    public:
        // Constructor mặc định
        Person() : fullName(""), phoneNumber(""), emailAddress("") {}

        // Constructor đầy đủ (dùng khi biết trc thông tin và truyền biến vào)
        Person(string fname, string pnum, string eAdd) : fullName(fname), phoneNumber(pnum), emailAddress(eAdd) {}

        ~ Person(){}

        void Setter_Person(){
            cout << "~ INPUT PERSON'S INFO ~" << endl;

            cout <<"ENTER NAME: ";
            getline(cin >> ws, fullName) ;
            cout <<"ENTER PHONE NUMBER: ";
            getline(cin >> ws, phoneNumber);
            cout <<"ENTER EMAIL ADDRESS: ";
            getline(cin >> ws, emailAddress);
        }

        string Getter_fullName(){
            return fullName;
        }

        string Getter_phoneNumber(){
            return phoneNumber;
        }


        string Getter_emailAddress(){
            return emailAddress;
        }

        void printInformation()
        {
            cout<< "NAME: " << Getter_fullName() << " ~ PHONE NUMBER: " << Getter_phoneNumber() << " ~ EMAIL ADDRESS: " << Getter_emailAddress() << endl;
        }
    
};

class Customer : public Person{
    private:
        string customerID;
        string username;
        double amountOfMoney;

    public:
        // Constructor mặc định
        Customer() : Person("", "", ""), customerID(""), username(""), amountOfMoney(0.0) {}

        // Constructor đầy đủ (dùng khi biết trc thông tin và truyền biến vào)
        Customer(string fname, string pnum, string eAdd, string cusID, string uname, double aom) : Person(fname, pnum, eAdd), customerID(cusID), username(uname), amountOfMoney(aom) {}

        ~ Customer(){}
        
        void Setter_Customer(){
            cout << "~ INPUT CUSTOMER'S INFO ~" << endl;

            cout <<"ENTER CUSTOMER ID: " ;
            getline(cin >> ws, customerID);
            cout <<"ENTER USER NAME: ";
            getline(cin >> ws, username);
            cout <<"ENTER AMOUNT OF MONEY: ";
            cin >> amountOfMoney;
        }

        void Setter_amountOfMoney(double aom)
        {
            amountOfMoney = aom;
        }

        
        string Getter_customerID(){
            return customerID;
        }

        string Getter_username(){
            return username;
        }

        double Getter_amountOfMoney(){
            return amountOfMoney;
        }

        void addMoneyToSystem(double add){
            amountOfMoney = amountOfMoney + add;
        }

        void subtractMoneyToSystem(double subtract){
            amountOfMoney = amountOfMoney - subtract;
        }

        void printInformation()
        {
            cout<< "CUSTOMER ID: " << Getter_customerID() << " ~ USER NAME: " << Getter_username() << " ~ AMOUNT OF MONEY: " << Getter_amountOfMoney() << " $ " << endl;
        }

};



class Product{
    private: 
        string productID;
        int quantity;
        double unitPrice;

    public:
        Product() : productID(""), quantity(0), unitPrice(0.0) {}

        ~ Product(){}

        void Setter_Product_Stock(){
            cout << "\n~ INPUT PRODUCT'S INFO TO STOCK ~" << endl;

            cout <<"ENTER PRODUCT ID: " ;
            getline(cin >> ws, productID);
            cout <<"ENTER QUANTITY IN STOCK: ";
            cin >> quantity;
            cout <<"ENTER UNIT PRICE: ";
            cin >> unitPrice;
        }


        void Setter_ProductID_Order(string productID_temp){
            productID = productID_temp;
        
        }

        void Setter_ProductQuantity_Order(int quantity_temp){
            quantity = quantity_temp;
        }

        void Setter_Price_Order(double unit_price_temp)
        {
            unitPrice = unit_price_temp;
        }
        
        string Getter_productID(){
            return productID;
        }

        int Getter_quantity(){
            return quantity;
        }

        double Getter_unitPrice(){
            return unitPrice;
        }

        void addProductQuantity(int amount){
            quantity = quantity + amount;
        }

        void updateUnitPrice(double new_price){
            unitPrice = new_price;
        }
            
        void printInformation()
        {
            cout<< "PRODUCT ID: " << Getter_productID() << " ~ QUANTITY IN STOCK: " << Getter_quantity() << " ~ UNIT PRICE: " << Getter_unitPrice() << " $ " << endl;
        }
};



class Order{
    private:
        string orderID;
        vector <int> quantities;
        string customerID;
        vector <Product> products;

    public:
        Order() : orderID(""), customerID("") {}

        ~ Order(){}

        void Setter_Order_Info()
        {
            cout << "ORDER'S ID: ";
            getline(cin >> ws, orderID);
            cout << "CUSTOMER'S ID: ";
            getline(cin >> ws, customerID);
            cout << "  =========\n";
        }

        void Setter_Order_List(Product new_product_order)
        {
            products.push_back(new_product_order);
        }

        string Getter_orderID ()
        {
            return orderID;
        }

        string Getter_customerID ()
        {
            return customerID;
        }

        double calculateTotalPrice ()
        {
            double total_price = 0;
            for (int i = 0; i < products.size(); i++)
            {
                total_price += products[i].Getter_unitPrice() * products[i].Getter_quantity();
            }

            return total_price;
        }

        void printInformation()
        {   cout <<"\t __BILL__ \t" <<endl
                <<"\t ========= \t" << endl;

            for (int i = 0; i < products.size(); i++)
            {
                cout << i + 1  <<". " << products[i].Getter_productID() << endl;

            }

            cout <<"\t ========= \t" << endl
                <<"TOTAL PRICE: " << calculateTotalPrice() << " $ " << endl
                <<"\t ========= \t" << endl;

        }
};



int main (){

    vector <Customer> Client_database;
    vector <Product> Stock;

    int choice;
    int choice_per;
    int choice_pro;

    do
    {
        cout << "~~~ WELCOME TO HIEU' SUPERMARKET ~~~" << endl
            << "\t ~ SELLING SYSTEM ~ \t\n" << endl;

            cout << "1. PERSON." <<endl
                << "2. PRODUCT." <<endl
                << "3. CHECKOUT. " <<endl
                << "0. EXIT. " <<endl
                <<"CHOOSE UR OPTION: ";

        cin >> choice;

        switch(choice)
        {
            //1.PERSON
            case 1:{
                do
                {
                    cout << "\n~~ PERSON ~~" << endl
                        << "1. REGISTER A CUSTOMER." << endl
                        << "2. SHOW CUSTOMER LIST." << endl
                        << "3. SHOW CUSTOMER' INFO LIST. " << endl // PERSON
                        << "0. RETURN TO HOME. "<< endl
                        <<"CHOOSE UR OPTION: ";
    
                    cin >> choice_per;
            
                    switch(choice_per)
                    {
                        //1. REGISTER A CUSTOMER.
                        case 1:{
                            Customer new_customer;
                            cout << "\n~~~ REGISTER A CUSTOMER ~~~" << endl;
                            new_customer.Setter_Person();
                            new_customer.Setter_Customer();
                            Client_database.push_back(new_customer);
                            break;
                        }
                        //2. SHOW CUSTOMER LIST.
                        case 2:{
                            if (Client_database.empty()) {
                                cout << "EMPTY." << endl;
                            } else {
                                cout << "\n   CUSTOMER LIST:" << endl;
                                for (int i = 0; i < Client_database.size(); i++) 
                                { 
                                    cout << i+1 << ".";
                                    Client_database[i].Customer :: printInformation();
                                }
                            }
                            break;
                        }
                        //3. SHOW CUSTOMER' INFO LIST.
                        case 3:{
                            if (Client_database.empty()) {
                                cout << "EMPTY." << endl;
                            } else {
                                cout << "\n CUSTOMER' INFO LIST:" << endl;
                                for (int i = 0; i < Client_database.size(); i++) 
                                { 
                                    cout << i+1 << ".";
                                    Client_database[i].Person :: printInformation();
                                }
                            }
                            break;
                        }
                        //0. RETURN TO HOME.
                        case 0: {
                            cout << "\nRETURNING TO HOME PAGE. \n" << endl;
                            break;
                        }
            
                        default: {
                            cout << "INVALID CHOICE" << endl;
                            break;
                        }
                    }
                } while(choice_per != 0);

                break;
            }

            //2. PRODUCT.
            case 2: {
                do
                {
                    cout <<"\n~~ PRODUCT ~~ " <<endl
                        << "1. INPUT PRODUCTS TO STOCK. " << endl
                        << "2. SHOW STOCK. " << endl
                        << "3. ADD PRODUCT QUANTITY. " << endl
                        << "4. UPDATE UNIT PRICE. " <<endl
                        << "0. RETURN TO HOME. " <<endl
                        <<"CHOOSE UR OPTION: ";
    
                    cin >> choice_pro;

                    switch(choice_pro){
                        //1. INPUT PRODUCTS TO STOCK.
                        case 1:{
                        Product new_product_stock;
                        new_product_stock.Setter_Product_Stock();
                        Stock.push_back(new_product_stock);
                        break;
                        }
                        //2. SHOW STOCK.
                        case 2:{
                            if(Stock.empty()) {
                                cout << "STOCK EMPTY." <<endl;
                            }
                            else{
                                cout << "\n   STOCK: " << endl;
                                for (int i = 0; i < Stock.size(); i ++)
                                {
                                    cout << i + 1 << ".";
                                    Stock[i].Product :: printInformation();
                                }
                            }
                            break;
                        }
                        //3. ADD PRODUCT QUANTITY.
                        case 3:{
                            string product_ID;
                            int amount;
                            bool found = false;

                            cout <<"PRODUCT'S ID WHICH U WANT TO ADD MORE: ";
                            getline(cin >> ws, product_ID);
                            cout <<"AMOUNT U WANT TO ADD: ";
                            cin >> amount;

                            for (int i = 0; i < Stock.size(); i++)
                            {
                                if (product_ID  == Stock[i].Getter_productID())
                                {
                                    found = true;
                                    Stock[i].addProductQuantity(amount);
                                    break;
                                }

                            
                            }

                            if (!found)
                                {
                                    cout <<"NOT FOUND." << endl;
                                }

                            break;

                        }
                        //4. UPDATE UNIT PRICE.
                        case 4:{
                            string product_ID;
                            double new_price;
                            bool found = false;

                            cout <<"PRODUCT'S ID WHICH U WANT TO CHANGE PRICE: ";
                            getline(cin >> ws, product_ID);
                            cout <<"NEW PRICE: ";
                            cin >> new_price;

                            for (int i = 0; i < Stock.size(); i++)
                            {
                                if (product_ID  == Stock[i].Getter_productID())
                                {
                                    found = true;
                                    Stock[i].updateUnitPrice(new_price);
                                    break;
                                }

                            
                            }

                            if (!found)
                            {
                                cout <<"NOT FOUND." << endl;
                            }

                            break;

                        }
                        //0. RETURN TO HOME.
                        case 0: {
                            cout << "\nRETURNING TO HOME PAGE. \n" << endl;
                            break;
                        }

                        default: {
                            cout << "INVALID CHOICE" << endl;
                            break;
                        }
                    }

                } 
                while (choice_pro != 0);

                break;
            }
            //3. CHECKOUT.
            case 3: {
                Order new_order;
                cout << "\n~<>~< ORDER >~<>~ \n" << endl;
                new_order.Setter_Order_Info();
            
                int index_customer_temp = -1;
                bool found_cus_ID = false;
                for (int i = 0; i < Client_database.size(); i++) {
                    if (new_order.Getter_customerID() == Client_database[i].Getter_customerID()) {
                        cout << "Customer Found: " 
                             << Client_database[i].Getter_customerID() << " ~ " 
                             << Client_database[i].Getter_fullName() << " ~ " 
                             << Client_database[i].Getter_amountOfMoney() << endl;
                        index_customer_temp = i;
                        found_cus_ID = true;
                        break;
                    }
                }
            
                if (!found_cus_ID) {
                    cout << "Customer not found\n" << endl;
                    break;
                }
            

                int count = 0;
                while (true) {
                    Product new_product_order; // chứa: product ID, quantity, unit price
            
                    count++;
                    string productID_temp;
                    cout << count << ". PRODUCT ID: ";
                    getline(cin >> ws, productID_temp);
            
                    if (productID_temp == "OK" || productID_temp == "ok") {
                        cout << "DONE" << endl;
                        break;
                    }
            
                    int quantities_temp;
                    cout << "QUANTITY: ";
                    cin >> quantities_temp;
            
                    bool available = false;
                    for (int i = 0; i < Stock.size(); i++) {
                        if (productID_temp == Stock[i].Getter_productID()) {
                            if (quantities_temp <= Stock[i].Getter_quantity()) {
                                new_product_order.Setter_ProductID_Order(productID_temp);
                                new_product_order.Setter_ProductQuantity_Order(quantities_temp);
                                new_product_order.Setter_Price_Order(Stock[i].Getter_unitPrice());
                                
                                new_order.Setter_Order_List(new_product_order);
                                Stock[i].addProductQuantity(-quantities_temp);
                                available = true;
                            } else {
                                cout << "Insufficient quantity for product " << productID_temp 
                                    << ". Available: " << Stock[i].Getter_quantity() << endl;
                            }
                            break;
                        }
                    }
            
                    if (!available) {
                        cout << "Product not found: " << productID_temp << endl;
                    }
                }
            
                double totalPrice = new_order.calculateTotalPrice();
                double AOM_OLD = Client_database[index_customer_temp].Getter_amountOfMoney();
                double AOM_NEW = AOM_OLD - totalPrice;
                
                if (AOM_NEW < 0) {
                    cout << "Insufficient funds. Order cannot be completed!" << endl;
                    break;
                }
                Client_database[index_customer_temp].Setter_amountOfMoney(AOM_NEW);
            
                new_order.Order :: printInformation();
            
                break; 
            }

            //0. EXIT.
            case 0:{
                cout <<"\nEXIT" <<endl
                    <<"THANK U FOR USING OUR SELLING SYSTEM." << endl;
                break;
            }

            default: {
                cout << "INVALID CHOICE" << endl;
                break;
            }
        }
    }
    while(choice != 0);

    return 0;
}

