//
// Created by stuka on 20.06.2023.
//

#include "ProductsOrderWindow.h"
#include "Windows/WindowsManager.h"
#include "Utils.h"
#include "Product/ProductsManager.h"
#include "Warehouse/WarehouseManager.h"
#include "Warehouse/ProductsSet.h"
#include "Restaurant.h"
#include "Accountant/AccountantLog.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Warehouse::ProductsOrderWindow::show()
{
    // вывод существующих продуктов
    int productsNum = 0;
    for(const auto& product : Product::ProductsManager::getProducts())
    {
        std::cout << std::to_string(productsNum + 1) << ") ID: " << product->m_id << ", название: " << product->m_name << ", цена: " << product->m_cost << std::endl;

        productsNum++;
    }

    std::cout << "Выберите продукт, который хотите заказать: ";
    int chosenProductNum = getPoint(1, productsNum);

    std::shared_ptr<Product::Product> chosenProduct;
    productsNum = 1;
    // поиск продукта по номеру
    for(auto& product : Product::ProductsManager::getProducts())
    {
        if(chosenProductNum == productsNum)
        {
            chosenProduct = product;
            break;
        }

        productsNum++;
    }

    // создание продукта и настройка
    std::shared_ptr<Product::Product> newProduct = std::make_shared<Product::Product>();
    newProduct->m_id = chosenProduct->m_id;
    newProduct->m_name = chosenProduct->m_name;
    newProduct->m_cost = chosenProduct->m_cost;

    int productsCount = Utils::getInputNum<int>("Введите кол-во продуктов: ");

    // проверка на, то что денег у ресторана недостаточно
    if((float) productsCount * chosenProduct->m_cost > Restaurant::m_money)
    {
        std::cout << "Недостаточно '" << std::to_string(((float) productsCount * chosenProduct->m_cost - Restaurant::m_money)) << "' денег для покупки" << std::endl;

        return WindowsManager::getWindow(WAREHOUSE_MAIN_WND_NAME);
    }

    auto newProductSet = std::make_shared<FinalPractice::Main::Warehouse::ProductsSet>(newProduct, productsCount);

    // добавление нового заказа
    FinalPractice::Main::Warehouse::WarehouseManager::m_orderedProducts.push_back(newProductSet);

    // добавление заказанного продукта в лог для бухглатера
    Accountant::AccountantLog::addOrderedProduct(newProductSet);

    // сохранение склада
    FinalPractice::Main::Warehouse::WarehouseManager::save("warehouse.txt");

    return WindowsManager::getWindow(WAREHOUSE_MAIN_WND_NAME);
}
