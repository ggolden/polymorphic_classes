#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Object {
    int row;
    int col;
public:
    explicit Object(int row, int col) : row(row), col(col) { cout << "+Object " << this << endl; }

    virtual ~Object() { cout << "-Object: " << this << endl; };
};

class Key : public Object {
public:
    Key(int row, int col) : Object(row, col) { cout << "+Key " << this << endl; }

    ~Key() override { cout << "-Key: " << this << endl; };
};

class Coin : public Object {
public:
    explicit Coin(int value, int row, int col) : Object(row, col), value(value) { cout << "+Coin " << this << endl; }

    ~Coin() override { cout << "-Coin: " << this << endl; };
    int value;
};

void test_object(int msg, Object *o_p) {
    cout << "[" << msg << "] ";
    if (o_p) {
        cout << "o_p is an Object";
    } else {
        cout << "o_p is not an Object";
    }
    cout << endl;
}

void test_key(int msg, Key *o_p) {
    cout << "[" << msg << "] ";
    if (o_p) {
        cout << "o_p is an Key";
    } else {
        cout << "o_p is not an Key";
    }
    cout << endl;
}

void test_coin(int msg, Coin *o_p) {
    cout << "[" << msg << "] ";
    if (o_p) {
        cout << "o_p is an Coin, value " << o_p->value;
    } else {
        cout << "o_p is not an Coin";
    }
    cout << endl;
}

int main() {
    cout << "vector<Object>" << endl;
    vector<Object> objects;
    objects.push_back(Object(0, 0));
    objects.push_back(Key(1, 1));
    objects.push_back(Coin(10, 10, 10));

    for (auto i = 0; i < objects.size(); i++) {
        test_object(i, dynamic_cast<Object *>(&objects[i]));
        test_key(i, dynamic_cast<Key *>(&objects[i]));
        test_coin(i, dynamic_cast<Coin *>(&objects[i]));
    }
    cout << endl;

    cout << "vector<Object*>" << endl;
    vector<Object *> objectPtrs;
    objectPtrs.push_back(new Object(0, 0));
    objectPtrs.push_back(new Key(1, 1));
    objectPtrs.push_back(new Coin(10, 10, 10));

    for (auto i = 0; i < objectPtrs.size(); i++) {
        test_object(i, dynamic_cast<Object *>(objectPtrs[i]));
        test_key(i, dynamic_cast<Key *>(objectPtrs[i]));
        test_coin(i, dynamic_cast<Coin *>(objectPtrs[i]));
    }

    for (auto objectPtr : objectPtrs) {
        delete objectPtr;
    }
    objectPtrs.clear();
}
