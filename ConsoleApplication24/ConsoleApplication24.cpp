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
    Device(string m, string mo, string n, int c, int q) {
        setManufacturer(m);
        setModel(mo);
        setName(n);
        setCapacity(c);
        setQuantity(q);
    }

    void setManufacturer(string m) { manufacturer = m; }
    string getManufacturer() { return manufacturer; }

    void setModel(string mo) { model = mo; }
    string getModel() { return model; }

    void setName(string n) { name = n; }
    string getName() { return name; }

    void setCapacity(int c) { capacity = c; }
    int getCapacity() { return capacity; }

    void setQuantity(int q) { quantity = q; }
    int getQuantity() { return quantity; }

    virtual void print() {
        cout << "Device: " << getManufacturer() << " " << getModel() << " " << getName() << " " << getCapacity() << " " << getQuantity() << "\n";
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
    FlashDrive(string m, string mo, string n, int c, int q) : Device(m, mo, n, c, q) {}

    void print() override {
        cout << "Flash Drive: " << getManufacturer() << " " << getModel() << " " << getName() << " " << getCapacity() << " " << getQuantity() << "\n";
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