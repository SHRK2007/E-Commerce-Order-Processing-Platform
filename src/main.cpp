#include <iostream>
#include "../include/VendorCatalog.h"
#include "../include/CartCheckout.h"
#include "../include/Fulfillment.h"
#include "../include/Notifications.h"
#include "../include/ReturnsRefunds.h"

using namespace std;

int main() {
    cout << "==================================================================" << endl;
    cout << "         E-COMMERCE ORDER PROCESSING PLATFORM (C++ OOP)           " << endl;
    cout << "==================================================================" << endl;

    // 1. Vendor Catalog Module (Muhammad Abdullah)
    runVendorCatalogDemo();

    // 2. Cart & Checkout Module (Syed Haider Raza Kazmi)
    runCartCheckoutDemo();

    // 3. Fulfillment & Logistics Module (Habib Ullah Jaan)
    runFulfillmentDemo();

    // 4. Notification Engine Module (Taimoor)
    runNotificationsDemo();

    // 5. Returns & Refunds Module (Taha)
    runReturnsRefundsDemo();

    cout << "\n==================================================================" << endl;
    cout << "          ALL 5 MODULES EXECUTED SUCCESSFULLY!                    " << endl;
    cout << "==================================================================" << endl;

    return 0;
}
