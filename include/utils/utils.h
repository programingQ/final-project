#ifndef UTILS_H
#define UTILS_H
#include "../entities/customer.h"
#include "../entities/product.h"
#include "../entities/dealer.h"
#include "../entities/purchase.h"
#include "../entities/person.h"
#include "../../src/entities/customer.cpp" // best practice is not to include c++ files in cpp file and tell compiler to compile them together
#include "../../src/entities/product.cpp"
#include "../../src/entities/dealer.cpp"
#include "../../src/entities/purchase.cpp"
#include "../../src/entities/person.cpp"
//max size is 100 
extern Customer* customers[100];
extern Product* products[100];
extern Dealer* dealers[100];
extern Purchase* purchases[100];
extern int customerCount  ;
extern int productCount ;
extern int dealerCount ;
extern int purchaseCount ;
void freeMemory();
void addProduct();
void removeProduct();
void addCustomer();
void removeCustomer();
void addDealer();
void removeDealer();
void recordPurchase();
void showMenu();
void totalPrice();
void productscustomers();
void dealersProducts();
void saleCount();
void customersProducts();
void dealerSalesReport();
#endif