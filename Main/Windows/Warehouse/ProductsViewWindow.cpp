//
// Created by stuka on 20.06.2023.
//

#include "ProductsViewWindow.h"
#include "Warehouse/WarehouseManager.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::Warehouse::ProductsViewWindow::show()
{
    std::cout << "1) Посмотреть отправленные заявки\n2) Посмотреть продукты на складе" << std::endl;

    int point = getPoint(1, 2);

    switch(point)
    {
        case 1:
        {
            std::cout << "Заказано:\n";
            int num = 0;
            for(const auto& order : FinalPractice::Main::Warehouse::WarehouseManager::m_orderedProducts)
            {
                std::cout << std::to_string(num) << ") ID: " << order->m_product->m_id << ", название: " << order->m_product->m_name
                << ", стоимость (шт.): " << order->m_product->m_cost << ", кол-во: " << order->m_count << std::endl;

                num++;
            }

            break;
        }
        case 2:
        {
            std::cout << "На складе:\n";
            int num = 0;
            for(const auto& order : FinalPractice::Main::Warehouse::WarehouseManager::m_productsInWarehouse)
            {
                std::cout << std::to_string(num) << ") ID: " << order->m_product->m_id << ", название: " << order->m_product->m_name
                          << ", стоимость (шт.): " << order->m_product->m_cost << ", кол-во: " << order->m_count << std::endl;

                num++;
            }

            break;
        }
    }

    return WindowsManager::getWindow(WAREHOUSE_MAIN_WND_NAME);
}
