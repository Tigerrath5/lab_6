/*
 * =============================================================
 * TND012: lab 6
 * Authors: Romeo Dahlström 
 * =============================================================
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

// Define new data type Date
struct Date {
    int year = 0; 
    int month = 0;
    int day = 0;
};

// Define new data type Product_sale
struct Product_sale {
    std::string product_code; 
    Date date; 
    int unit = 0; 
};

/* ************************************** */

// Read a date from stream is
Date read_date(std::ifstream& is);

// Write date d to stream os
void write_date(std::ofstream& os, const Date& d);

// Read a product sale from stream is
Product_sale read_sale(std::ifstream& is);

// Write a product sale p to stream os
void write_sale(std::ofstream& os, const Product_sale& p);

// Define read_sales_file function
std::vector<Product_sale> read_sales_file(std::ifstream& is); 

//Sorts by number of sales
void swap_unit(int& product_sale); 
 
//Sorts by date 
void swap_date(int& product_date); 

//compares product code lexicographically
void sort_lexicographically(std::string& product_code); 

//Sorts the whole vector with the functions above
void sorts_sales(std::vector<Product_sale>& product); 

/* ************************************** */

int main() {
    std::cout << "Enter k: ";
    int k;
    std::cin >> k;

    std::string path = "X:/lab6/code/"; // Replace this path, if needed

    std::cout << "Enter name of product sales file: ";
    std::string input_file_name;
    std::cin >> input_file_name;
    std::ifstream sales_file(path + input_file_name);

    std::cout << "Enter name of top-k sales file: ";
    std::string output_file_name;
    std::cin >> output_file_name;
    std::ofstream top_sold_file(path + output_file_name);

    if (!sales_file || !top_sold_file) {
        std::cout << "File error!!\n\n";
        return 0;
    }

    Product_sale p = read_sale(sales_file);
    write_sale(top_sold_file, p);

    return 0; 
}

/* ************************************** */

Date read_date(std::ifstream& is) {
    Date d; 
    char dash = '-'; 

    is >> d.year >> dash >> d.month >> dash >> d.day; 

    return d; 
}

void write_date(std::ofstream& os, const Date& d) {
    os << d.year << "-" << d.month << "-" << d.day; 
}

Product_sale read_sale(std::ifstream& is) {
    Product_sale p; 
    std::getline(is, p.product_code); 
    p.date = read_date(is); 
    is >> p.unit;

    return p; 
}

void write_sale(std::ofstream& os, const Product_sale& p) {
    os << p.product_code << "\n"; 

    write_date(os, p.date); 
        
    os << "\n" << p.unit << "\n";
}

std::vector<Product_sale> read_sales_file(std::ifstream& is) {
    Product_sale p = read_sale(is); 
    std::vector<Product_sale> sales; 

    while (is) {
        sales.push_back(p); 

        p = read_sale(is);
    }
    return sales; 
}

void swap_unit(int& unit_A, int& unit_B) {
    int temp = unit_A; 
    unit_A = unit_B; 
    unit_B = temp; 
}

void sorts_sales(std::vector<Product_sale>& products) {
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].unit > products[i + 1].unit) {
            break; 
        }

        if (products[i].unit < products[i + 1].unit) {
            swap_unit(products[i].unit, products[i + 1].unit); 
        }
        else if (products[i].unit == products[i + 1].unit) {
            if (products[i].date > products[i + 1].date) {
                //swap 
            }
            if (/*compares date if bigger swap*/) {
                //swap
            }
            else if 
        }
        

    }
}