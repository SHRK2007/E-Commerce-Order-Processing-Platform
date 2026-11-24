#ifndef RETURNS_REFUNDS_H
#define RETURNS_REFUNDS_H

#include <iostream>
#include <string>
using namespace std;

// Class 1: Validates whether the return falls within the allowed policy window
class ReturnPolicy {
private:
    int maxReturnDays;

public:
    ReturnPolicy(int days = 14) {
        maxReturnDays = days;
    }

    bool isEligible(int daysSincePurchase) {
        if (daysSincePurchase <= maxReturnDays) {
            cout << "[Policy] Return eligible (" << daysSincePurchase
                 << " days <= " << maxReturnDays << " days limit)." << endl;
            return true;
        }
        cout << "[Policy] Return rejected (exceeded " << maxReturnDays << " days limit)." << endl;
        return false;
    }
};

// Class 2: Represents a customer's return request and reason code
class ReturnRequest {
private:
    int requestId;
    int orderId;
    string reasonCode;
    string status;

public:
    ReturnRequest(int reqId, int ordId, string reason) {
        requestId = reqId;
        orderId = ordId;
        reasonCode = reason;
        status = "Submitted";
    }

    void updateStatus(string newStatus) {
        status = newStatus;
        cout << "[Return #" << requestId << "] Status: " << status << endl;
    }

    int getOrderId() { return orderId; }
    string getReason() { return reasonCode; }
};

// Class 3: Inspects returned item condition before approving refund
class QualityInspection {
private:
    string inspectorName;
    bool passed;

public:
    QualityInspection(string inspector = "Supervisor_1") {
        inspectorName = inspector;
        passed = false;
    }

    bool inspectItem(string itemCondition) {
        if (itemCondition == "Unopened" || itemCondition == "Defective") {
            passed = true;
            cout << "[Inspection] Passed by " << inspectorName
                 << " (Condition: " << itemCondition << ")." << endl;
        } else {
            passed = false;
            cout << "[Inspection] Failed by " << inspectorName
                 << " (Customer damaged item)." << endl;
        }
        return passed;
    }
};

// Class 4: Processes and approves the refund amount
class RefundProcessor {
private:
    double refundAmount;
    string refundStatus;

public:
    RefundProcessor(double amount = 0.0) {
        refundAmount = amount;
        refundStatus = "Pending";
    }

    double approveRefund() {
        refundStatus = "Refunded";
        cout << "[Refund] Status: " << refundStatus << " | Amount: $" << refundAmount << endl;
        return refundAmount;
    }
};

// Class 5: Credits the refunded money back into the buyer's digital wallet
class DigitalWallet {
private:
    string ownerName;
    double balance;

public:
    DigitalWallet(string owner = "Customer", double initialBalance = 0.0) {
        ownerName = owner;
        balance = initialBalance;
    }

    void creditAmount(double amount) {
        balance += amount;
        cout << "[Wallet] Credited $" << amount << " to " << ownerName
             << "'s wallet. New Balance: $" << balance << endl;
    }
};

// Demo function to be called from main.cpp
inline void runReturnsRefundsDemo() {
    cout << "\n================ RETURNS & REFUNDS MODULE ================" << endl;
    ReturnPolicy policy(14);
    ReturnRequest req(501, 1001, "DEFECTIVE_ITEM");

    if (policy.isEligible(5)) {
        req.updateStatus("Under Inspection");
        QualityInspection qc("Inspector Bilal");
        if (qc.inspectItem("Defective")) {
            req.updateStatus("Approved");
            RefundProcessor processor(45.0);
            double refunded = processor.approveRefund();

            DigitalWallet wallet("Syed Haider Raza Kazmi", 10.0);
            wallet.creditAmount(refunded);
        }
    }
}

#endif
