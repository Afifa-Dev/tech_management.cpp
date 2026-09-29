#include <iostream>
#include <string>
#include<fstream>
#include<iomanip>
using namespace std;

class Admin
{
private:
    string username;
    string password;

public:
    Admin()
    {
        username = "abc@tech";
        password = "12345";
    }

    bool login()
    {
        string user, pass;
        int attempts = 3;

        while (attempts > 0)
        {
            cout << "========= ADMIN LOGIN =========="<<endl;
            cout << "Username: "<<endl;
            cin >> user;

            cout << "Password: "<<endl;
            cin >> pass;

            if (user == username && pass == password)
            {
                cout << "Login Successful!"<<endl;
                return true;
            }
            else
            {
                attempts--;
                cout << "Incorrect Username or Password."<<endl;

                if (attempts > 0)
                {
                    cout << "Attempts Remaining: " << attempts << endl;
                }
            }
        }

        cout << "Too many failed attempts. Access Denied!"<<endl;
        return false;
    }
};

class Customer
{
private:
    string username;
    string password;

public:
    Customer()
    {
        username = "xyz@cust";
        password = "123";
    }

    bool login()
    {
        string user, pass;
        int attempts = 3;

        while (attempts > 0)
        {
            cout << "========== CUSTOMER LOGIN =========="<<endl;
            cout << "Username: "<<endl;
            cin >> user;

            cout << "Password: "<<endl;
            cin >> pass;

            if (user == username && pass == password)
            {
                cout << "Login Successful!"<<endl;
                return true;
            }
            else
            {
                attempts--;
                cout << "Invalid Username or Password."<<endl;

                if (attempts > 0)
                    cout << "Attempts Remaining: " << attempts << endl;
            }
        }

        cout << "Too many failed attempts. Access Denied!"<<endl;
        return false;
    }
};

class Product
{
private:
    int id;
    string name;
    string category;
    double price;
    int quantity;

public:
    void addProduct()
    {
        cout << "Enter Product ID: "<<endl;
        cin >> id;

        cin.ignore();

        cout << "Enter Product Name: "<<endl;
        getline(cin, name);

        cout << "Enter Category: "<<endl;
        getline(cin, category);

        cout << "Enter Price: "<<endl;
        cin >> price;

        cout << "Enter Quantity: "<<endl;
        cin >> quantity;
    }

    void displayProduct()
    {
      
        cout << "Product ID : " << id<<endl;
        cout << "Name       : " << name<<endl;
        cout << "Category   : " << category<<endl;
        cout << "Price      : $" << price<<endl;
        cout << "Quantity   : " << quantity<<endl;
    }

    int getID()
    {
        return id;
    }

    void updateProduct()
    {
        cin.ignore();

        cout << "Enter New Product Name: "<<endl;
        getline(cin, name);

        cout << "Enter New Category: "<<endl;
        getline(cin, category);

        cout << "Enter New Price: "<<endl;
        cin >> price;

        cout << "Enter New Quantity: "<<endl;
        cin >> quantity;

        cout << "Product Updated Successfully!"<<endl;
    }
};

class Cart
{
private:
    int productID[100];
    string productName[100];
    double price[100];
    int quantity[100];
    int count;

public:
    Cart()
    {
        count = 0;
    }

    void addToCart()
    {
        cout << "Enter Product ID: "<<endl;
        cin >> productID[count];

        cin.ignore();

        cout << "Enter Product Name: "<<endl;
        getline(cin, productName[count]);

        cout << "Enter Price: "<<endl;
        cin >> price[count];

        cout << "Enter Quantity: "<<endl;
        cin >> quantity[count];

        count++;

        cout << "Product Added to Cart Successfully!"<<endl;
    }

    void viewCart()
    {
        if (count == 0)
        {
            cout << "Your cart is empty."<<endl;
            return;
        }

        double total = 0;

        cout << "SHOPPING CART ";

        for (int i = 0; i < count; i++)
        {
            cout << "Product ID : " << productID[i]<<endl;
            cout << "Name       : " << productName[i]<<endl;
            cout << "Price      : $" << price[i]<<endl;
            cout << "Quantity   : " << quantity[i]<<endl;
            cout << "Subtotal   : $" << price[i] * quantity[i]<<endl;

            total += price[i] * quantity[i];
        }

        cout << "Total Bill : $" << total << endl;
    }

    void removeFromCart()
    {
        int id;
        cout << "Enter Product ID to Remove: "<<endl;
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (productID[i] == id)
            {
                for (int j = i; j < count - 1; j++)
                {
                    productID[j] = productID[j + 1];
                    productName[j] = productName[j + 1];
                    price[j] = price[j + 1];
                    quantity[j] = quantity[j + 1];
                }

                count--;

                cout << "Product Removed Successfully!"<<endl;
                return;
            }
        }

        cout << "Product Not Found in Cart!"<<endl;
    }

    void checkout()
    {
        if (count == 0)
        {
            cout << "Cart is Empty!"<<endl;
            return;
        }

        double total = 0;

        for (int i = 0; i < count; i++)
        {
            total += price[i] * quantity[i];
        }

        cout << " CHECKOUT ";
        cout << "Total Amount: $" << total << endl;
        cout << "Thank you for shopping with us!\n";

        count = 0; // Empty cart after checkout
    }
};


class Checkout
{
private:
    double totalBill;
    double payment;

public:
    Checkout()
    {
        totalBill = 0;
        payment = 0;
    }

    void setTotal(double total)
    {
        totalBill = total;
    }

    void processPayment()
    {
        cout << " CHECKOUT "<<endl;
        cout << "Total Bill: Rs. " << fixed << setprecision(2) << totalBill << endl;

        do
        {
            cout << "Enter Payment Amount: Rs. "<<endl;
            cin >> payment;

            if (payment < totalBill)
            {
                cout << "Insufficient Payment! Please enter enough amount."<<endl;
            }

        } while (payment < totalBill);

        cout << "Payment Successful!"<<endl;
        cout << "Change Returned: Rs. " << payment - totalBill << endl;
    }

    void printReceipt()
    {
        cout << " TECH STORE RECEIPT"<<endl;
        cout << "Total Bill : Rs. " << totalBill<<endl;
        cout << "Paid Amount: Rs. " << payment<<endl;
        cout << "Change     : Rs. " << payment - totalBill<<endl;
        cout << "Thank you for shopping with us!"<<endl;
        cout << "Visit Again!"<<endl;
    }
};

class Invoice
{
private:
    int invoiceNo;
    string customerName;
    string productName;
    int quantity;
    double price;
    double total;

public:
    Invoice()
    {
        invoiceNo = 1001;
    }

    void generateInvoice()
    {
        cout << " GENERATE INVOICE "<<endl;

        cin.ignore();

        cout << "Enter Customer Name: "<<endl;
        getline(cin, customerName);

        cout << "Enter Product Name: "<<endl;
        getline(cin, productName);

        cout << "Enter Quantity: "<<endl;
        cin >> quantity;

        cout << "Enter Price per Unit: Rs. "<<endl;
        cin >> price;

        total = quantity * price;

        printInvoice();
    }

    void printInvoice()
    {
        cout << " TECH STORE INVOICE "<<endl;
        cout << "Invoice No    : " << invoiceNo << endl;
        cout << "Customer Name : " << customerName << endl;
        cout << left << setw(20) << "Product"
             << setw(10) << "Qty"
             << setw(12) << "Price"
             << "Total"<<endl;
        cout << left << setw(20) << productName
             << setw(10) << quantity
             << setw(12) << price
             << total << endl;
        cout << "Grand Total : Rs. " << total << endl;
        cout << "Thank You for Shopping!"<<endl;
    }
};

class Inventory
{
private:
    int productID;
    string productName;
    int stock;

public:
    void addProduct()
    {
        cout << "Enter Product ID: "<<endl;
        cin >> productID;

        cin.ignore();

        cout << "Enter Product Name: "<<endl;
        getline(cin, productName);

        cout << "Enter Initial Stock: "<<endl;
        cin >> stock;
    }

    void displayProduct()
    {
        cout << "Product ID   : " << productID<<endl;
        cout << "Product Name : " << productName<<endl;
        cout << "Stock        : " << stock<<endl;
    }

    int getProductID()
    {
        return productID;
    }

    void addStock()
    {
        int qty;
        cout << "Enter Quantity to Add: "<<endl;
        cin >> qty;

        stock += qty;

        cout << "Stock Updated Successfully!"<<endl;
    }

    void reduceStock()
    {
        int qty;
        cout << "Enter Quantity Sold: "<<endl;
        cin >> qty;

        if (qty <= stock)
        {
            stock -= qty;
            cout << "Stock Updated Successfully!"<<endl;
        }
        else
        {
            cout << "Insufficient Stock!"<<endl;
        }
    }

    void checkStock()
    {
        cout << "Available Stock: " << stock << endl;

        if (stock <= 5)
        {
            cout << "Low Stock Alert!"<<endl;
        }
    }
};

class Sales
{
private:
    int saleID;
    string customerName;
    string productName;
    int quantity;
    double unitPrice;
    double totalAmount;

public:
    void addSale()
    {
        cout << "Enter Sale ID: "<<endl;
        cin >> saleID;

        cin.ignore();

        cout << "Enter Customer Name: "<<endl;
        getline(cin, customerName);

        cout << "Enter Product Name: "<<endl;
        getline(cin, productName);

        cout << "Enter Quantity: "<<endl;
        cin >> quantity;

        cout << "Enter Unit Price: "<<endl;
        cin >> unitPrice;

        totalAmount = quantity * unitPrice;

        cout << "Sale Recorded Successfully!"<<endl;
    }

    void displaySale()
    {
        cout << "Sale ID        : " << saleID<<endl;
        cout << "Customer Name  : " << customerName<<endl;
        cout << "Product Name   : " << productName<<endl;
        cout << "Quantity       : " << quantity<<endl;
        cout << "Unit Price     : Rs. " << unitPrice<<endl;
        cout << "Total Amount   : Rs. " << totalAmount<<endl;
    }

    int getSaleID()
    {
        return saleID;
    }

    double getTotalAmount()
    {
        return totalAmount;
    }
};

class Supplier
{
private:
    int supplierID;
    string supplierName;
    string companyName;
    string phoneNumber;
    string email;

public:
    void addSupplier()
    {
        cout << "Enter Supplier ID: "<<endl;
        cin >> supplierID;

        cin.ignore();

        cout << "Enter Supplier Name: "<<endl;
        getline(cin, supplierName);

        cout << "Enter Company Name: "<<endl;
        getline(cin, companyName);

        cout << "Enter Phone Number: "<<endl;
        getline(cin, phoneNumber);

        cout << "Enter Email Address: "<<endl;
        getline(cin, email);

        cout << "Supplier Added Successfully!"<<endl;
    }

    void displaySupplier()
    {
        cout << "Supplier ID   : " << supplierID<<endl;
        cout << "Supplier Name : " << supplierName<<endl;
        cout << "Company Name  : " << companyName<<endl;
        cout << "Phone Number  : " << phoneNumber<<endl;
        cout << "Email         : " << email<<endl;
    }

    int getSupplierID()
    {
        return supplierID;
    }

    void updateSupplier()
    {
        cin.ignore();

        cout << "Enter New Supplier Name: "<<endl;
        getline(cin, supplierName);

        cout << "Enter New Company Name: "<<endl;
        getline(cin, companyName);

        cout << "Enter New Phone Number: "<<endl;
        getline(cin, phoneNumber);

        cout << "Enter New Email Address: "<<endl;
        getline(cin, email);

        cout << "Supplier Updated Successfully!"<<endl;
    }
};

class Reports
{
private:
    int totalProducts;
    int totalCustomers;
    int totalSuppliers;
    int totalSales;
    double totalRevenue;

public:
    Reports()
    {
        totalProducts = 120;
        totalCustomers = 75;
        totalSuppliers = 10;
        totalSales = 50;
        totalRevenue = 250000;
    }

    void productReport()
    {
        cout << " PRODUCT REPORT "<<endl;
        cout << "Total Products : " << totalProducts << endl;
    }

    void customerReport()
    {
        cout << " CUSTOMER REPORT "<<endl;
        cout << "Total Customers : " << totalCustomers << endl;
    }

    void supplierReport()
    {
        cout << " SUPPLIER REPORT "<<endl;
        cout << "Total Suppliers : " << totalSuppliers << endl;
    }

    void salesReport()
    {
        cout << " SALES REPORT "<<endl;
        cout << "Total Sales : " << totalSales << endl;
        cout << "Revenue     : Rs. " << totalRevenue << endl;
    }

    void inventoryReport()
    {
        cout << " INVENTORY REPORT "<<endl;
        cout << "Products Available : " << totalProducts << endl;
        cout << "Low Stock Products : 8" << endl;
    }

    void showReports()
    {
        int choice;

        do
        {
            cout << " REPORTS MENU "<<endl;
            cout << "1. Product Report"<<endl;
            cout << "2. Customer Report"<<endl;
            cout << "3. Supplier Report"<<endl;
            cout << "4. Sales Report"<<endl;
            cout << "5. Inventory Report"<<endl;
            cout << "6. Exit"<<endl;
            cout << "Enter Choice: "<<endl;
            cin >> choice;

            switch(choice)
            {
            case 1:
                productReport();
                break;

            case 2:
                customerReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                salesReport();
                break;

            case 5:
                inventoryReport();
                break;

            case 6:
                cout << "Returning to Main Menu..."<<endl;
                break;

            default:
                cout << "Invalid Choice!"<<endl;
            }

        } while(choice != 6);
    }
};

class System
{
public:

    void adminMenu()
    {
        int choice;

        do
        {
            cout << " ADMIN MENU "<<endl;
            cout << "1. Product Management"<<endl;
            cout << "2. Inventory Management"<<endl;
            cout << "3. Customer Management"<<endl;
            cout << "4. Sales Management"<<endl;
            cout << "5. Supplier Management"<<endl;
            cout << "6. Reports"<<endl;
            cout << "7. Logout"<<endl;
            cout << "Enter Choice: "<<endl;
            cin >> choice;

            switch(choice)
            {
                case 1:
                    cout << "[Product Module Called]"<<endl;
                    break;

                case 2:
                    cout << "[Inventory Module Called]"<<endl;
                    break;

                case 3:
                    cout << "[Customer Module Called]"<<endl;
                    break;

                case 4:
                    cout << "[Sales Module Called]"<<endl;
                    break;

                case 5:
                    cout << "[Supplier Module Called]"<<endl;
                    break;

                case 6:
                    cout << "[Reports Module Called]"<<endl;
                    break;

                case 7:
                    cout << "Logging out..."<<endl;
                    break;

                default:
                    cout << "Invalid Choice!"<<endl;
            }

        } while(choice != 7);
    }

    void customerMenu()
    {
        int choice;

        do
        {
            cout << " CUSTOMER MENU "<<endl;
            cout << "1. View Products";
            cout << "2. Search Product"<<endl;
            cout << "3. Add to Cart"<<endl;
            cout << "4. View Cart"<<endl;
            cout << "5. Checkout"<<endl;
            cout << "6. Invoice"<<endl;
            cout << "7. Logout"<<endl;
            cout << "Enter Choice: "<<endl;
            cin >> choice;

            switch(choice)
            {
                case 1:
                    cout << "[View Products Called]"<<endl;
                    break;

                case 2:
                    cout << "[Search Product Called]"<<endl;
                    break;

                case 3:
                    cout << "[Add to Cart Called]"<<endl;
                    break;

                case 4:
                    cout << "[View Cart Called]"<<endl;
                    break;

                case 5:
                    cout << "[Checkout Called]"<<endl;
                    break;

                case 6:
                    cout << "[Invoice Called]"<<endl;
                    break;

                case 7:
                    cout << "Logging out..."<<endl;
                    break;

                default:
                    cout << "Invalid Choice!"<<endl;
            }

        } while(choice != 7);
    }

    void mainMenu()
    {
        int choice;

        do
        {
            cout << " TECH STORE SYSTEM "<<endl;
            cout << "1. Admin Login"<<endl;
            cout << "2. Customer Login"<<endl;
            cout << "3. Exit"<<endl;
            cout << "Enter Choice: "<<endl;
            cin >> choice;

            switch(choice)
            {
                case 1:
                {
                    cout << "Admin Login Successful (Demo)"<<endl;
                    adminMenu();
                    break;
                }

                case 2:
                {
                    cout << "Customer Login Successful (Demo)"<<endl;
                    customerMenu();
                    break;
                }

                case 3:
                    cout << "Exiting System..."<<endl;
                    break;

                default:
                    cout << "Invalid Choice!"<<endl;
            }

        } while(choice != 3);
    }
};

class CustomerSystem
{
public:

    void customerMenu()
    {
        int choice;

        do
        {
            cout << " CUSTOMER DASHBOARD "<<endl;
            cout << "1. View Products"<<endl;
            cout << "2. Search Product"<<endl;
            cout << "3. Add to Cart"<<endl;
            cout << "4. View Cart"<<endl;
            cout << "5. Remove from Cart"<<endl;
            cout << "6. Checkout"<<endl;
            cout << "7. Generate Invoice"<<endl;
            cout << "8. Logout"<<endl;
            cout << "Enter Choice: "<<endl;
            cin >> choice;

            switch(choice)
            {
                case 1:
                    cout << "[View Products Module Called]"<<endl;
                    // viewProducts();
                    break;

                case 2:
                    cout << "[Search Product Module Called]"<<endl;
                    // searchProduct();
                    break;

                case 3:
                    cout << "[Add to Cart Module Called]"<<endl;
                    // addToCart();
                    break;

                case 4:
                    cout << "[View Cart Module Called]"<<endl;
                    // viewCart();
                    break;

                case 5:
                    cout << "[Remove from Cart Module Called]"<<endl;
                    // removeFromCart();
                    break;

                case 6:
                    cout << "[Checkout Module Called]"<<endl;
                    // checkout();
                    break;

                case 7:
                    cout << "[Invoice Module Called]"<<endl;
                    // generateInvoice();
                    break;

                case 8:
                    cout << "Logging out of Customer Panel..."<<endl;
                    break;

                default:
                    cout << "Invalid Choice! Try Again."<<endl;
            }

        } while(choice != 8);
    }
};



int main()
{
    System s;

do
{
    cout << "1. Admin Login\n";
    cout << "2. Customer Login\n";
    cout << "3. Exit\n";
    cin >> choice;

    switch(choice)
    {
        case 1:
            s.adminMenu();
            break;

        case 2:
            s.customerMenu();
            break;

        case 3:
            cout << "Exit\n";
            break;
    }

} while(choice != 3);
return 0;
}
