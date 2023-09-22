
#include <iostream>
#include <cmath>

using namespace std;



namespace Trio {
    class Number {
    private:
        int value;

    public:
        Number(int val = 0) : value(val) {}

        int get() const {
            return value;
        }

        // Toplama operatörü
        Number operator+(const Number& other) const {
            return Number(value + other.value);
        }

        // Çıkartma operatörü
        Number operator-(const Number& other) const {
            return Number(value - other.value);
        }

        // Çarpma operatörü
        Number operator*(const Number& other) const {
            return Number(value * other.value);
        }

        // Bölme operatörü
        Number operator/(const Number& other) const {
            if (other.value == 0) {
                cerr << "Hata: Bölme sıfıra bölünemez!" << endl;
                return *this;
            }
            return Number(value / other.value);
        }

        // Mod operatörü
        Number operator%(const Number& other) const {
            if (other.value == 0) {
                cerr << "Hata: Mod alma işlemi sıfıra bölünemez!" << endl;
                return *this;
            }
            return Number(value % other.value);
        }

        // Üs alma operatörü (^ işareti üs alma operatörü olmadığı için ** işaretini kullanıyoruz)
        Number operator^(const Number& other) const {
            double result = pow(static_cast<double>(value), static_cast<double>(other.value));
            return Number(static_cast<int>(result));
        }

        // Ön ek arttırma operatörü
        Number& operator++() {
            value += 10;
            return *this;
        }

        // Ön ek azaltma operatörü
        Number& operator--() {
            value -= 10;
            return *this;
        }

        // Negatif işaretleme operatörü
        Number operator-() const {
            return Number(-value);
        }
        operator int() const {
            return value;
        }
    };
}

int main() {
    using namespace Trio;

    int first, second;
    std::cout << "Enter first number to do operation: ";
    std::cin >> first;
    std::cout << "Enter second number to do operation: ";
    std::cin >> second;

    Number num1(first);
    Number num2(second);

        // İşlemleri gerçekleştiriyoruz, ancak sonuçları farklı değişkenlere atıyoruz
    Number sum(num1+num2);
    cout << "Sum of two numbers: " << sum.get() << endl;
    Number difference(num1 - num2);
    cout << "Difference of two numbers: " << difference.get() << endl;
    Number product(num1 * num2);
    cout << "Product of two numbers: " << product.get() << endl;
    Number division(num1 / num2);
    cout << "Division of two numbers: " << division.get() << endl;
    cout << "\n";
    Number power(num1 ^ num2);
    cout << "Number 1 to the power of number 2: " << num1.get() << " ^ " << num2.get() << " = " << power.get() << endl;
    Number mode(num1 % num2);
    cout << "Mode operation: " << num1.get() << " % " << num2.get() << " = " << mode.get() << endl;
    cout << "\n";
    Number inc1(++num1);
    cout << "10 more than number 1: " << inc1.get() << endl;
    --num1;
    Number dec1(--num1);
    cout << "10 less than number 1: " << dec1.get() << endl;
    ++num1;
    Number inc2(++num2);
    cout << "10 more than number 2: " << inc2.get() << endl;
    --num2;
    Number dec2(--num2);
    cout << "10 less than number 2: " << dec2.get() << endl;
    ++num2;
    Number neg1(-num1);
    cout << "Negative form of number 1: " << neg1.get() << endl;
    -num1;
    Number neg2(-num2);
    cout << "Negative form of number 2: " << neg2.get() << endl;
    -num2;
    return 0;
}
