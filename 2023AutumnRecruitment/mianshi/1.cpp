#include <iostream>
#include <string>
#include <memory>

class Currency {
public:
    virtual double calculateTax(double faceValue) = 0;
};

class USD : public Currency {
public:
    double calculateTax(double faceValue) override {
        // 美元税收计算方式
        return faceValue * 0.05;  // 假设税率为5%
    }
};

class CNY : public Currency {
public:
    double calculateTax(double faceValue) override {
        // 人民币税收计算方式
        return faceValue * 0.1;  // 假设税率为10%
    }
};

class GBP : public Currency {
public:
    double calculateTax(double faceValue) override {
        // 英镑税收计算方式
        return faceValue * 0.08;  // 假设税率为8%
    }
};


int main() {
    std::string currencyType;
    double faceValue;

    std::cout << "请输入钞票类型（USD, CNY, GBP）: ";
    std::cin >> currencyType;
    std::cout << "请输入面值: ";
    std::cin >> faceValue;

    std::unique_ptr<Currency> currency;

    if (currencyType == "USD") {
        currency = std::make_unique<USD>();
    } else if (currencyType == "CNY") {
        currency = std::make_unique<CNY>();
    } else if (currencyType == "GBP") {
        currency = std::make_unique<GBP>();
    } else {
        std::cout << "非法的货币类型。" << std::endl;
        return 0;
    }

    double tax = currency->calculateTax(faceValue);
    std::cout << "税收金额为: " << tax << std::endl;

    return 0;
}
