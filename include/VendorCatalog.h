#ifndef VENDOR_CATALOG_H
#define VENDOR_CATALOG_H

#include <iostream>
#include <string>
using namespace std;

// Class 1: Represents a marketplace vendor/seller
class Vendor {
private:
    int vendorId;
    string vendorName;
    double rating;

public:
    Vendor(int id = 1, string name = "TechZone Official", double rate = 4.8) {
        vendorId = id;
        vendorName = name;
        rating = rate;
    }

    int getVendorId() { return vendorId; }
    string getVendorName() { return vendorName; }
    double getRating() { return rating; }
};

// Class 2: Represents a product category in the catalog
class Category {
private:
    int categoryId;
    string categoryName;

public:
    Category(int id = 10, string name = "Electronics") {
        categoryId = id;
        categoryName = name;
    }

    string getCategoryName() { return categoryName; }
};

// Class 3: Represents a catalog product item
class CatalogItem {
private:
    int sku;
    string title;
    double price;
    Vendor vendor;
    Category category;

public:
    CatalogItem(int itemSku = 5001, string itemTitle = "Wireless Mechanical Keyboard",
                double itemPrice = 8500.0, Vendor v = Vendor(), Category c = Category()) {
        sku = itemSku;
        title = itemTitle;
        price = itemPrice;
        vendor = v;
        category = c;
    }

    int getSku() { return sku; }
    string getTitle() { return title; }
    double getPrice() { return price; }
    Vendor getVendor() { return vendor; }
    Category getCategory() { return category; }
};

// Class 4: Tracks stock availability for a catalog item
class InventoryStock {
private:
    int sku;
    int availableUnits;

public:
    InventoryStock(int itemSku = 5001, int units = 25) {
        sku = itemSku;
        availableUnits = units;
    }

    bool reserveUnits(int qty) {
        if (qty <= availableUnits) {
            availableUnits -= qty;
            return true;
        }
        return false;
    }

    int getAvailableUnits() { return availableUnits; }
};

// Class 5: Searches and displays catalog listings
class CatalogManager {
public:
    void displayListing(CatalogItem item, InventoryStock stock) {
        cout << "[Catalog] SKU #" << item.getSku() << ": " << item.getTitle()
             << " (" << item.getCategory().getCategoryName() << ")" << endl;
        cout << "          Vendor: " << item.getVendor().getVendorName()
             << " (Rating: " << item.getVendor().getRating() << "/5.0)"
             << " | Price: Rs. " << item.getPrice()
             << " | In Stock: " << stock.getAvailableUnits() << " units" << endl;
    }
};

// Demo function to be called from main.cpp
inline void runVendorCatalogDemo() {
    cout << "\n================ VENDOR CATALOG MODULE ================" << endl;
    Vendor vendor(101, "TechZone Official", 4.9);
    Category category(1, "Computer Accessories");
    CatalogItem item(5001, "Wireless Mechanical Keyboard", 8500.0, vendor, category);
    InventoryStock stock(5001, 20);
    CatalogManager manager;

    manager.displayListing(item, stock);
    if (stock.reserveUnits(2)) {
        cout << "[Inventory] Reserved 2 units. Remaining stock: " << stock.getAvailableUnits() << endl;
    }
}

#endif
