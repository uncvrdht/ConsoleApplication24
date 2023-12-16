#include <iostream>
#include <string>

using namespace std;

class Device {
private:
    string manufacturer;
    string model;
    string name;
    int capacity;
    int quantity;

public:
    Device(string manufacturer, string model, string name, int capacity, int quantity) {
        SetManufacturer(manufacturer);
        SetModel(model);
        SetName(name);
        SetCapacity(capacity);
        SetQuantity(quantity);
    }

    void SetManufacturer(const string& m) {
        manufacturer = m;
    }

    const string& GetManufacturer() const {
        return manufacturer;
    }

    void SetModel(const string& m) {
        model = m;
    }

    const string& GetModel() const {
        return model;
    }

    void SetName(const string& n) {
        name = n;
    }

    const string& GetName() const {
        return name;
    }

    void SetCapacity(int c) {
        capacity = c;
    }

    int GetCapacity() const {
        return capacity;
    }

    void SetQuantity(int q) {
        quantity = q;
    }

    int GetQuantity() const {
        return quantity;
    }

    virtual void Print() const {
        cout << "Device: " << GetManufacturer() << " " << GetModel() << " " << GetName() << " " << GetCapacity() << " " << GetQuantity() << "\n";
    }

    virtual void Load() const {
        cout << "Loading device\n";
    }

    virtual void Save() const {
        cout << "Saving device\n";
    }

    virtual ~Device() {}
};

class FlashDrive : public Device {
public:
    FlashDrive(string manufacturer, string model, string name, int capacity, int quantity)
    {
        SetManufacturer(manufacturer);
        SetModel(model);
        SetName(name);
        SetCapacity(capacity);
        SetQuantity(quantity);
    }

    void Print() const override {
        cout << "Flash Drive: " << GetManufacturer() << " " << GetModel() << " " << GetName() << " " << GetCapacity() << " " << GetQuantity() << "\n";
    }

    void Load() const override {
        cout << "Loading flash drive\n";
    }

    void Save() const override {
        cout << "Saving flash drive\n";
    }
};

int main() {
    Device* devices[2];
    devices[0] = new Device("Generic", "Model1", "Device1", 100, 5);
    devices[1] = new FlashDrive("Samsung", "A1", "Flash Drive", 64, 10);

    for (int i = 0; i < 2; i++) {
        devices[i]->Print();
        devices[i]->Load();
        devices[i]->Save();
    }

    for (int i = 0; i < 2; i++) {
        delete devices[i];
    }

    return 0;
}