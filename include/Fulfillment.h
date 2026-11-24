#ifndef FULFILLMENT_H
#define FULFILLMENT_H

#include <iostream>
#include <string>
using namespace std;

// Class 1: Represents the warehouse where the order is packed
class Warehouse {
private:
    string warehouseName;
    string city;

public:
    Warehouse(string name = "Central Hub", string loc = "Lahore") {
        warehouseName = name;
        city = loc;
    }

    void packOrder(int orderId) {
        cout << "[Warehouse] Order #" << orderId << " packed at "
             << warehouseName << " (" << city << ")." << endl;
    }
};

// Class 2: Stores physical details of the shipment package
class Package {
private:
    double weightKg;
    string dimensions;

public:
    Package(double weight = 1.0, string dim = "20x15x10 cm") {
        weightKg = weight;
        dimensions = dim;
    }

    double getWeight() { return weightKg; }

    void showPackageInfo() {
        cout << "[Package] Weight: " << weightKg << " kg | Size: " << dimensions << endl;
    }
};

// Class 3: Calculates shipping fee based on transport mode (Air, Sea, Road)
class ShippingCalculator {
private:
    string shippingMode;

public:
    ShippingCalculator(string mode = "Road") {
        shippingMode = mode;
    }

    double calculateFee(double weightKg) {
        double rate = 5.0; // Default Road
        if (shippingMode == "Air") rate = 15.0;
        else if (shippingMode == "Sea") rate = 3.0;

        double fee = weightKg * rate;
        cout << "[Shipping] Mode: " << shippingMode << " | Fee: $" << fee << endl;
        return fee;
    }
};

// Class 4: Represents the courier/delivery partner assigned to the order
class CourierPartner {
private:
    string courierName;
    string driverName;

public:
    CourierPartner(string company = "FastTrack Express", string driver = "Ali") {
        courierName = company;
        driverName = driver;
    }

    void assignDelivery(string trackingNumber) {
        cout << "[Courier] " << courierName << " (Driver: " << driverName
             << ") assigned to Tracking #" << trackingNumber << endl;
    }
};

// Class 5: Tracks shipment stages (Packed -> Dispatched -> Out for Delivery -> Delivered)
class ShipmentTracker {
private:
    string trackingNumber;
    string currentStage;

public:
    ShipmentTracker(string trackNo = "TRK-0000") {
        trackingNumber = trackNo;
        currentStage = "Packed";
    }

    void updateStage(string newStage) {
        currentStage = newStage;
        cout << "[Tracker " << trackingNumber << "] Status updated to: " << currentStage << endl;
    }

    void showStatus() {
        cout << "[Tracker " << trackingNumber << "] Current Status: " << currentStage << endl;
    }
};

// Demo function to be called from main.cpp
inline void runFulfillmentDemo() {
    cout << "\n================ FULFILLMENT & LOGISTICS MODULE ================" << endl;
    Warehouse wh("Lahore Main Warehouse", "Lahore");
    wh.packOrder(1001);

    Package pkg(2.5, "30x20x15 cm");
    pkg.showPackageInfo();

    ShippingCalculator calc("Air");
    calc.calculateFee(pkg.getWeight());

    CourierPartner courier("SwiftLogistics", "Usman");
    courier.assignDelivery("TRK-98451");

    ShipmentTracker tracker("TRK-98451");
    tracker.showStatus();
    tracker.updateStage("Dispatched");
    tracker.updateStage("Out for Delivery");
    tracker.updateStage("Delivered");
}

#endif
