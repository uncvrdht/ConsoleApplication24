#include <iostream>
#include <string>

using namespace std;

// Базовый класс
class Device {
protected:
    string manufacturer;
    string model;
    string name;
    int capacity;
    int quantity;
public:
    Device(string manufacturer, string model, string name, int capacity, int quantity) : manufacturer(manufacturer), model(model), name(name), capacity(capacity), quantity(quantity) {}

    virtual void print() {
        cout << "Device: " << manufacturer << " " << model << " " << name << " " << capacity << " " << quantity << "\n";
    }

    virtual void load() {
        cout << "Loading device\n";
    }

    virtual void save() {
        cout << "Saving device\n";
    }
};

// Производный класс
class FlashDrive : public Device {
public:
    FlashDrive(string manufacturer, string model, string name, int capacity, int quantity) : Device(manufacturer, model, name, capacity, quantity) {}

    void print() override {
        cout << "Flash Drive: " << manufacturer << " " << model << " " << name << " " << capacity << " " << quantity << "\n";
    }

    void load() override {
        cout << "Loading flash drive\n";
    }

    void save() override {
        cout << "Saving flash drive\n";
    }
};

int main() {
    Device* devices[2];
    devices[0] = new Device("Generic", "Model1", "Device1", 100, 5);
    devices[1] = new FlashDrive("Samsung", "A1", "Flash Drive", 64, 10);

    for (int i = 0; i < 2; i++) {
        devices[i]->print();
        devices[i]->load();
        devices[i]->save();
    }

    for (int i = 0; i < 2; i++) {
        delete devices[i];
    }

    return 0;
}