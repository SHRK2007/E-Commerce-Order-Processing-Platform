#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <iostream>
#include <string>
using namespace std;

// Class 1: Stores user contact details and notification preferences
class UserContact {
private:
    string userName;
    string email;
    string phone;
    string preferredChannel;

public:
    UserContact(string name = "User", string mail = "user@example.com",
                string ph = "0300-0000000", string pref = "Email") {
        userName = name;
        email = mail;
        phone = ph;
        preferredChannel = pref;
    }

    string getUserName() { return userName; }
    string getEmail() { return email; }
    string getPhone() { return phone; }
    string getPreferredChannel() { return preferredChannel; }
};

// Class 2: Represents the notification event and message content
class NotificationMessage {
private:
    string eventType;
    string messageBody;

public:
    NotificationMessage(string event = "OrderUpdate", string body = "Your order status changed.") {
        eventType = event;
        messageBody = body;
    }

    string getFormattedMessage() {
        return "[" + eventType + "] " + messageBody;
    }
};

// Class 3: Handles sending Email notifications
class EmailChannel {
private:
    string smtpServer;

public:
    EmailChannel(string server = "smtp.ecommerce.com") {
        smtpServer = server;
    }

    void sendEmail(UserContact user, NotificationMessage msg) {
        cout << "[Email via " << smtpServer << "] To: " << user.getEmail()
             << " | " << msg.getFormattedMessage() << endl;
    }
};

// Class 4: Handles sending SMS notifications
class SMSChannel {
private:
    string gatewayName;

public:
    SMSChannel(string gateway = "TwilioPK") {
        gatewayName = gateway;
    }

    void sendSMS(UserContact user, NotificationMessage msg) {
        cout << "[SMS via " << gatewayName << "] To: " << user.getPhone()
             << " | " << msg.getFormattedMessage() << endl;
    }
};

// Class 5: Handles sending mobile app Push notifications
class PushChannel {
private:
    string appName;

public:
    PushChannel(string app = "ShopEase App") {
        appName = app;
    }

    void sendPush(UserContact user, NotificationMessage msg) {
        cout << "[Push - " << appName << "] User: " << user.getUserName()
             << " | " << msg.getFormattedMessage() << endl;
    }
};

// Demo function to be called from main.cpp
inline void runNotificationsDemo() {
    cout << "\n================ NOTIFICATION ENGINE MODULE ================" << endl;
    UserContact user("Taimoor", "taimoorahmadwork69@gmail.com", "0300-1234567", "All");
    NotificationMessage msg("OrderDispatched", "Your Order #1001 has been dispatched!");

    EmailChannel email;
    SMSChannel sms;
    PushChannel push;

    email.sendEmail(user, msg);
    sms.sendSMS(user, msg);
    push.sendPush(user, msg);
}

#endif
