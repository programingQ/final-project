#include <iostream>
#include "../../include/utils/utils.h"
void freeMemory() {
    for (int i = 0; i < customerCount; ++i) delete customers[i];
    for (int i = 0; i < productCount; ++i) delete products[i];
    for (int i = 0; i < dealerCount; ++i) delete dealers[i];
    for (int i = 0; i < purchaseCount; ++i) delete purchases[i];
}
void addProduct() {
    string productID, name, brand;
    float price, weight;
    cout << "Enter Product ID: ";
    cin >> productID;
    cout << "Enter Product Name: ";
    cin >> name;
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Brand: ";
    cin >> brand;
    cout << "Enter Weight: ";
    cin >> weight;
    if (productCount < 100) {
        if (weight > 0 && price > 0) {
            bool isIdUnique = true;
            for (int i = 0; i < productCount; i++) {
                if (products[i]->getProductID() == productID) {
                    isIdUnique = false;
                    break;
                }
            }

            if (isIdUnique) {
                products[productCount++] = new Product(productID, name, price, brand, weight);
                cout << "Product added successfully!\n";
            } else {
                cout << "Id already exists ;( \n";
            }
        } else {
            cout << "Weight or price can't be 0 or less ;( \n";
        }
    } else {
        cout << "Maximum product limit reached ;( \n";
    }
}
void removeProduct() {
    string productID;
    cout << "Enter Product Id to remove: ";
    cin >> productID;
    bool found = false;
    int index = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i]->getProductID() == productID) {
            found = true;
            index = i;
            break;
        }
    }
    if (found) {
        delete products[index];
        for (int i = index; i < productCount - 1; i++) {
            products[i] = products[i + 1];
        }
        cout << "Product removed successfully!\n";
        productCount--;
        for (int i = 0; i < purchaseCount; i++) {
            if (purchases[i]->getProductId() == productID) {
                delete purchases[i];
                for (int j = i; j < purchaseCount - 1; j++) {
                    purchases[j] = purchases[j + 1];
                }
                purchaseCount--;
                i--;
            }
        }
    
    } else {
        cout << "Product not found ;(\n";
    };
}
void addCustomer() {
    string firstName, lastName, nationalID, gender, customerID, province, city;
    int birthYear;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter National ID: ";
    cin >> nationalID;
    cout << "Enter Birth Year: ";
    cin >> birthYear;
    cout << "Enter Gender: ";
    cin >> gender;
    cout << "Enter Customer ID: ";
    cin >> customerID;
    cout << "Enter Province: ";
    cin >> province;
    cout << "Enter City: ";
    cin >> city;
    bool isNationalIDUnique = true;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i]->getNationalID() == nationalID) {
            isNationalIDUnique = false;
            break;
        }
    }
    if (isNationalIDUnique) {
        if (customerCount < 100) {
            customers[customerCount++] = new Customer(firstName, lastName, nationalID,
                                                    birthYear, gender, customerID,
                                                    province, city);
            cout << "Customer added successfully ; ) \n";
        } else {
            cout << "Maximum customer limit reached ; ( \n";
        }
    } else {
        cout << "National ID already exists ; ( \n";
    }
}
void removeCustomer() {
    string nationalID;
    cout << "Enter National Id of customer to remove: ";
    cin >> nationalID;
    bool found = false;
    int index = -1;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i]->getNationalID() == nationalID) {
            found = true;
            index = i;
            break;
        }
    }
    if (found) {
        delete customers[index];
        for (int i = index; i < customerCount - 1; i++) {
            customers[i] = customers[i + 1];
        }
        
        customerCount--;
        cout << "Customer removed successfully ; ) \n";
        for (int i = 0; i < purchaseCount; i++) {
            if (purchases[i]->getCustomerId() == nationalID) {
                delete purchases[i];
                for (int j = i; j < purchaseCount - 1; j++) {
                    purchases[j] = purchases[j + 1];
                }
                purchaseCount--;
                i--;
            }
        }
    } else {
        cout << "Customer not found!\n";
    }
}
void addDealer() {
    string dealerName, dealerID, fName, lName, province, city,EconomicCode;
    int establishedYear;
    cout << "Enter Dealer Name: ";
    cin.ignore();
    getline(cin, dealerName);
    cout << "Enter Established Year: ";
    cin >> establishedYear;
    cout << "Enter Dealer ID: ";
    cin >> dealerID;
    cout << "Enter Owner First Name: ";
    cin >> fName;
    cout << "Enter Owner Last Name: ";
    cin >> lName;
    cout << "Enter Province: ";
    cin >> province;
    cout << "Enter City: ";
    cin >> city;
    cout<< "Enter EconomicCode : ";
    cin>>EconomicCode;
    bool isDealerIDUnique = true;
    for (int i = 0; i < dealerCount; i++) {
        if (dealers[i]->getDealerID() == dealerID) {
            isDealerIDUnique = false;
            break;
        }
    }

    if (isDealerIDUnique) {
        if (dealerCount < 100) {
            dealers[dealerCount++] = new Dealer(dealerID,dealerName , establishedYear,EconomicCode,
                                              fName, lName,
                                              province, city);
            cout << "Dealer added successfully!\n";
        } else {
            cout << "Maximum dealers limit reached!\n";
        }
    } else {
        cout << "Dealer ID already exists!\n";
    }
}
void removeDealer() {
    string dealerID;
    cout << "Enter Dealer ID to remove: ";
    cin >> dealerID;
    bool found = false;
    int index = -1;
    for (int i = 0; i < dealerCount; i++) {
        if (dealers[i]->getDealerID() == dealerID) {
            found = true;
            index = i;
            break;
        }
    }
    if (found) {
        delete dealers[index];
        for (int i = index; i < dealerCount - 1; i++) {
            dealers[i] = dealers[i + 1];
        }
        dealerCount--;
        cout << "Dealer removed successfully!\n";
        for (int i = 0; i < purchaseCount; i++) {
            if (purchases[i]->getDealerId() == dealerID) {
                delete purchases[i];
                for (int j = i; j < purchaseCount - 1; j++) {
                    purchases[j] = purchases[j + 1];
                }
                purchaseCount--;
                i--; 
            }
        }
    } else {
        cout << "Dealer not found!\n";
    }
}
void recordPurchase() {
    Customer* customer = nullptr;
    Product* product = nullptr;
Dealer* dealer = nullptr;
    string nationalID, productID, dealerID, purchaseDate;
    int quantity;
    cout << "Enter Customer National ID: ";
    cin >> nationalID;
    cout << "Enter Product ID: ";
    cin >> productID;
    cout << "Enter Dealer ID: ";
    cin >> dealerID;
    //finding entities from id 
    for (int i = 0; i < customerCount; ++i) {
        if (customers[i]->getNationalID() == nationalID) {
            customer = customers[i];
            break;
        }
    }
    for (int i = 0; i < productCount; ++i) {
        if (products[i]->getProductID() == productID) {
            product = products[i];
            break;
        }
    }
    for (int i = 0; i < dealerCount; ++i) {
        if (dealers[i]->getDealerID() == dealerID) {
            dealer = dealers[i];
            break;
        }
    }
    //validation
    if (!customer) {
        cout << "Customer not found ;( \n";
        return;
    }
  
    if (!product) {
        cout << "Product not found ;( \n";
        return;
    }
  
    if (!dealer) {
        cout << "Dealer not found ;( \n";
        return;
    }
    cout << "Enter Quantity: ";
    cin >> quantity;
    if (quantity <= 0) {
        cout << "Quantity must be greater than 0 ;( \n";
        return;
    }
    cout << "Enter Purchase Date: ";
    cin >> purchaseDate;
    if (purchaseCount < 100) {
        purchases[purchaseCount++] = new Purchase(customer, product, dealer, quantity, purchaseDate);
        cout << "Purchase recorded successfully ; )  \n";
    } else {
        cout << "Purchase list is full ;(\n";
    }
}

void showMenu() {
    cout <<"⚙️  enter your intended number : \n";
    cout << " 🔘 1. Add a Product  \n"; 
    cout << " 🔘 2. Remove a Product  \n"; 
    cout << " 🔘 3. Add a Customer  \n"; 
    cout << " 🔘 4. Remove a Customer  \n"; 
    cout << " 🔘 5. Add a Dealer  \n"; 
    cout << " 🔘 6. Remove a Dealer  \n";
    cout << " 🔘 7. Record a Purchase  \n"; 
    cout << " 🔘 8. Calculate and display the total purchase amount for a specific Customer  \n"; 
    cout << " 🔘 9. Display the list of Customers who purchased a specific Product  \n"; 
    cout << " 🔘 10. Display the list of Products sold by a specific Dealer  \n";  
    cout << " 🔘 11. Display the total number of units sold for a specific Product \n";  
    cout << " 🔘 12. Display the list of Products purchased by a specific Customer  \n";  
    cout << " 🔘 13. Display a report of all Dealers along with their total sales \n";   
    cout << " 🔘 14. Exit the Program  \n";  
}
void totalPrice(){
        string nId;
        cout << "Enter Customer NationalID : ";
        cin >> nId;
        bool customerExist = false;
        float totalPrice = 0;
        for (int i = 0; i < purchaseCount; i++) {
            if (purchases[i]->getCustomerId() == nId) {
                Product* product = purchases[i]->getProduct();
                totalPrice += product->getPrice() * purchases[i]->getQuantity();
                customerExist = true;
            }
        }
    
        if (customerExist) {
            cout << "total Price : " << totalPrice << endl;
        } else {
            cout << "No purchases found ; (\n\n";
        }
    }
    void productscustomers(){
        string pId;
        cout << "Enter ProductID: ";
        cin >> pId;
        bool productExists = false;
        //checking products existance
        for (int i = 0; i < productCount; ++i) {
            if (products[i]->getProductID() == pId) {
                productExists = true;
                break;
            }
        }
        if (!productExists) {
            cout << "product not found ; ( \n\n" ;
            return;
        }
        string uniqueCustomerIDs[100];
        int uniqueCuCount = 0;
        for (int i = 0; i < purchaseCount; ++i) {
            if (purchases[i]->getProductId() == pId) {
                string currentID = purchases[i]->getCustomerId();
                bool isUnique = true;
                // checking to be unique 
                for (int j = 0; j < uniqueCuCount; ++j) {
                    if (uniqueCustomerIDs[j] == currentID) {
                        isUnique = false;
                        break;
                    }
                }
                if (isUnique && uniqueCuCount < 100) {
                    uniqueCustomerIDs[uniqueCuCount++] = currentID;
                }
            }
        }
        if (uniqueCuCount == 0) {
            cout << "no customers found ; ( " << endl;
            return;
        }
         cout<<"customers List : \n";
        for (int i = 0; i < uniqueCuCount; ++i) {
            for (int j = 0; j < customerCount; ++j) {
                if (customers[j]->getNationalID() == uniqueCustomerIDs[i]) {
                    cout << "customer "<<i+1<<" : \n";
                    customers[j]->showInfo();
                }
            }
        }
    }
    void dealersProducts(){
        string diD;
        cout << "Enter DealerId : ";
        cin >> diD;
        bool dealerExists = false;
        for (int i = 0; i < dealerCount; ++i) {
            if (dealers[i]->getDealerID() == diD) {
                dealerExists = true;
                break;
            }
        }
        if (!dealerExists) {
            cout << "Dealer with ID " << diD << " not found!" << endl;
            return;
        }
        string uniqueProductIDs[100];
        int uniqueCount = 0;
        for (int i = 0; i < purchaseCount; ++i) {
            if (purchases[i]->getDealerId() == diD) {
                string currentProductID = purchases[i]->getProductId();
                bool isUnique = true;
                for (int j = 0; j < uniqueCount; ++j) {
                    if (uniqueProductIDs[j] == currentProductID) {
                        isUnique = false;
                        break;
                    }
                }
                if (isUnique && uniqueCount < 100) {
                    uniqueProductIDs[uniqueCount++] = currentProductID;
                }
            }
        }
        if (uniqueCount == 0) {
            cout << "dealer didn't sell anything ; ( \n\n" ;
            return;
        }
        cout << "\n products List : \n" ;
        for (int i = 0; i < uniqueCount; ++i) {
            for (int j = 0; j < productCount; ++j) {
                if (products[j]->getProductID() == uniqueProductIDs[i]) {
                 products[j]->showInfo();
                    break;
                }
            }
        }
    }
    void saleCount(){
            string pId;
            int totalSales = 0;
            cout << "Enter ProductId: ";
            cin >> pId;
            bool productExists = false;
            for (int i = 0; i < productCount; ++i) {
                if (products[i]->getProductID() == pId) {
                    productExists = true;
                    break;
                }
            }
            if (!productExists) {
                cout << "Product not found ; ( \n";
                return;
            }
            for (int i = 0; i < purchaseCount; ++i) {
                if (purchases[i]->getProductId() == pId) {
                    totalSales += purchases[i]->getQuantity();
                }
            }
            cout << "Total sales : " << totalSales << endl;
        }
        void customersProducts(){
            string nId;
    cout << "Enter Customer NationalId : ";
    cin >> nId;
    bool customerExists = false;
    for (int i = 0; i < customerCount; ++i) {
        if (customers[i]->getNationalID() == nId) {
            customerExists = true;
            break;
        }
    }
    if (!customerExists) {
        cout << "Customer not found ; ( \n";
        return;
    }
    bool hasPurchases = false;
    for (int i = 0; i < purchaseCount; ++i) {
        if (purchases[i]->getCustomerId() == nId) {
            hasPurchases = true;
            int i =1;
            cout << "Purchase " << i++<<" : \n";
            purchases[i]->showInfo();
        }
    }
    if (!hasPurchases) {
        cout << "No purchases found ; ( \n" ;
    }
}
void dealerSalesReport(){
        if (dealerCount == 0) {
            cout << "there is no dealer ; ( \n" ;
            return;
        }
        cout << "\n Report : \n\n";
        for (int i = 0; i < dealerCount; ++i) {
            double totalSales = 0;
            int totalTransactions = 0;
            for (int j = 0; j < purchaseCount; ++j) {
                if (purchases[j]->getDealerId() == dealers[i]->getDealerID()) {
                    Product* product = purchases[j]->getProduct();
                    totalSales += product->getPrice() * purchases[j]->getQuantity();
                    totalTransactions++;
                }
            }
            cout<< "dealer name : "<<dealers[i]->getDealerName()<<endl;
            cout<< "dealer Id : "<<dealers[i]->getDealerID()<<endl;
            cout<<"sum of sales : "<<totalSales<<endl<<endl;
        }
    }