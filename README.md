# E-Commerce Order Processing Platform

A modular Object-Oriented C++ project demonstrating an end-to-end E-Commerce Order Processing workflow across 5 independent modules (25 classes total).

## Project Structure
~~~
E-Commerce-Order-Processing-Platform/
├── include/
│   ├── VendorCatalog.h     # Vendor & Product Catalog Module (5 classes)
│   ├── CartCheckout.h      # Shopping Cart & Checkout Module (5 classes)
│   ├── Fulfillment.h       # Fulfillment & Logistics Module (5 classes)
│   ├── Notifications.h     # Notification Engine Module (5 classes)
│   └── ReturnsRefunds.h    # Returns & Refunds Module (5 classes)
├── src/
│   └── main.cpp            # Integrated system entry point
└── README.md
~~~

## Team Members & Modules
| Member | Role / Module | Header File | Classes |
| :--- | :--- | :--- | :---: |
| **Syed Haider Raza Kazmi** | Team Lead — Cart & Checkout | `include/CartCheckout.h` | 5 |
| **Habib Ullah Jaan** | Fulfillment & Logistics | `include/Fulfillment.h` | 5 |
| **Taha** | Returns & Refunds | `include/ReturnsRefunds.h` | 5 |
| **Taimoor** | Notification Engine | `include/Notifications.h` | 5 |
| **Muhammad Abdullah** | Vendor Catalog | `include/VendorCatalog.h` | 5 |

## How to Compile & Run
~~~bash
g++ -Iinclude src/main.cpp -o platform
./platform
~~~
