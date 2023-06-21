//
// Created by stuka on 21.06.2023.
//

#include "MainWindow.h"

#include "Warehouse/WarehouseManager.h"
#include "Restaurant.h"
#include "Warehouse/ProductsSet.h"
#include "Accountant/AccountantLog.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Provider::MainWindow::show()
{
    // вывод всех заказов
    std::cout << "Заказы:\n";
    int num = 0;
    for(const auto& order : FinalPractice::Main::Warehouse::WarehouseManager::m_orderedProducts)
    {
        std::cout << std::to_string(num + 1) << ") ID: " << order->m_product->m_id << ", название: " << order->m_product->m_name
                  << ", стоимость (шт.): " << order->m_product->m_cost << ", кол-во: " << order->m_count << std::endl;

        num++;
    }

    std::cout << "Выберите пункт для отправки продуктов\n";
    int chosenOrder = getPoint(1, num);

    std::shared_ptr<Warehouse::ProductsSet> curProductSet;
    num = 1;
    // поиск нужного продукта по номеру
    for(const auto& order : FinalPractice::Main::Warehouse::WarehouseManager::m_orderedProducts)
    {
        // если номера совпадают
        if(chosenOrder == num)
        {
            curProductSet = order;

            // проверка на то, что денег хватает
            float sum = ((float) order->m_count * order->m_product->m_cost);
            if(sum <= Restaurant::m_money)
            {
                std::cout << "Заказ на сумму '" << std::to_string(((float) order->m_count * order->m_product->m_cost))
                          << " отправлен на склад!" << std::endl;
                // вычет суммы продуктов
                Restaurant::m_money -= ((float) order->m_count * order->m_product->m_cost);

                break;
            }
            else // когда не хватает денег
            {
                std::cout << "Заказ не может быть отправлен! Не хватает: '" << std::to_string(sum - Restaurant::m_money) << "' денег" << std::endl;

                return WindowsManager::getWindow(PROVIDER_MAIN_WND_NAME);
            }
        }

        num++;
    }

    // перекидываем продукт из листа с заказанными продуктами в лист с отправленными продуктами
    FinalPractice::Main::Warehouse::WarehouseManager::m_orderedProducts.remove(curProductSet);
    FinalPractice::Main::Warehouse::WarehouseManager::m_productsInWarehouse.push_back(curProductSet);

    // добавление нового отправленного продукта в лог к бухгалтеру
    Accountant::AccountantLog::addAcceptedProductDelivery(curProductSet);

    // сохраняем склад
    FinalPractice::Main::Warehouse::WarehouseManager::save("warehouse.txt");

    return WindowsManager::getWindow(PROVIDER_MAIN_WND_NAME);
}
