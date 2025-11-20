#include <iostream>
using namespace std;

// aбстрактний продукт //
class IMessage {
public:
    virtual void show() const = 0;
    virtual ~IMessage() = default;
};

// конкретні продукти //
class HelloMessage : public IMessage {
public:
    void show() const override {
        cout << "hello" << endl;
    }
};

class ByeMessage : public IMessage {
public:
    void show() const override {
        cout << "goodbye" << endl;
    }
};
class IMessageFactory {
public:
    virtual IMessage* createMessage() const = 0;
    virtual ~IMessageFactory() = default;
};

class HelloFactory : public IMessageFactory {
public:
    IMessage* createMessage() const override {
        return new HelloMessage();
    }
};

class ByeFactory : public IMessageFactory {
public:
    IMessage* createMessage() const override {
        return new ByeMessage();
    }
};

int main() {
    HelloFactory hello;
    ByeFactory bye;

    IMessage* msg1 = hello.createMessage();
    IMessage* msg2 = bye.createMessage();

    msg1->show();
    msg2->show();

    return 0;
}