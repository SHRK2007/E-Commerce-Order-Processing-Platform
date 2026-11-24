#ifndef CART_CHECKOUT_H
#define CART_CHECKOUT_H

#include <iostream>
#include <string>
using namespace std;

// Class 1: Represents a single item in the cart
class CartItem {
private:
    string productName;
    double unitPrice;
    int quantity;

public:
    CartItem(string name = "", double price = 0.0, int qty = 0) {
        productName = name;
        unitPrice = price;
        quantity = qty;
    }

    void setQuantity(int qty) { quantity = qty; }
    string getName() { return productName; }
    double getSubtotal() { return unitPrice * quantity; }

    void displayItem() {
        cout << " - " << productName << " | Price: $" << unitPrice
             << " | Qty: " << quantity << " | Subtotal: $" << getSubtotal() << endl;
    }
};

// Class 2: Manages the customer's shopping cart
class ShoppingCart {
private:
    CartItem items[10];
    int itemCount;

public:
    ShoppingCart() { itemCount = 0; }

    void addItem(CartItem item) {
        if (itemCount < 10) {
            items[itemCount++] = item;
            cout << "[Cart] Added: " << item.getName() << endl;
        }
    }

    double calculateTotal() {
        double total = 0.0;
        for (int i = 0; i < itemCount; i++) {
            total += items[i].getSubtotal();
        }
        return total;
    }

    void showCart() {
        cout << "\n--- Shopping Cart ---" << endl;
        for (int i = 0; i < itemCount; i++) {
            items[i].displayItem();
        }
        cout << "Cart Total: $" << calculateTotal() << endl;
    }
};

// Class 3: Handles discount coupons at checkout
class DiscountCoupon {
private:
    string code;
    double discountPercent;

public:
    DiscountCoupon(string c = "NONE", double percent = 0.0) {
        code = c;
        discountPercent = percent;
    }

    double applyDiscount(double total) {
        double discount = total * (discountPercent / 100.0);
        cout << "[Coupon] Applied '" << code << "' (-$" << discount << ")" << endl;
        return total - discount;
    }
};

// Class 4: Tracks checkout state (Pending, Confirmed, Cancelled)
class CheckoutState {
private:
    string status;

public:
    CheckoutState() { status = "Pending"; }

    void confirmOrder() {
        status = "Confirmed";
        cout << "[Checkout] Order Status: " << status << endl;
    }

    void cancelOrder() {
        status = "Cancelled";
        cout << "[Checkout] Order Status: " << status << endl;
    }

    string getStatus() { return status; }
};

// Class 5: Generates and displays the final order receipt
class OrderReceipt {
private:
    int orderId;
    string customerName;
    double finalAmount;

public:
    OrderReceipt(int id, string customer, double amount) {
        orderId = id;
        customerName = customer;
        finalAmount = amount;
    }

    void printReceipt() {
        cout << "\n=== ORDER RECEIPT ===" << endl;
        cout << "Order ID: #" << orderId << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Total Paid: $" << finalAmount << endl;
        cout << "=====================" << endl;
    }
};

// Demo function to be called from main.cpp
inline void runCartCheckoutDemo() {
    cout << "\n================ CART & CHECKOUT MODULE ================" << endl;
    ShoppingCart cart;
    CartItem item1("Wireless Mouse", 25.0, 2);
    CartItem item2("Mechanical Keyboard", 70.0, 1);

    cart.addItem(item1);
    cart.addItem(item2);
    cart.showCart();

    DiscountCoupon coupon("SAVE10", 10.0);
    double finalTotal = coupon.applyDiscount(cart.calculateTotal());

    CheckoutState state;
    state.confirmOrder();

    OrderReceipt receipt(1001, "Syed Haider Raza Kazmi", finalTotal);
    receipt.printReceipt();
}

#endif
