//
// Created by stuka on 18.06.2023.
//

#include "EditProductWindow.h"
#include "Product/ProductsManager.h"
#include "Utils.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::SysAdmin::EditProductWindow::show()
{
    switch(m_editMode)
    {
        case CREATE:
        {
            std::uint16_t productID = 0;
            std::string productName;
            float productCost = 0;

            while(true)
            {
                productID = Utils::getInputNum<int>("Введите ID продукта: ");

                if(Product::ProductsManager::isProductExists(productID))
                {
                    std::cout << "Продукт уже существует!" << std::endl;
                    continue;
                }

                productName = Utils::getLine("Введите имя продукта: ");

                productCost = Utils::getInputNum<float>("Введите цену продукта: ");

                std::shared_ptr<Product::Product> newProduct = Product::ProductsManager::createProduct();
                newProduct->m_id = productID;
                newProduct->m_name = productName;
                newProduct->m_cost = productCost;

                std::cout << "Новый продукт добавлен!" << std::endl;

                break;
            }

            break;
        }
        case EDIT:
        {
            std::cout << "1) Изменить ID\n2) Название\n3) Стоимость\nВыберите пункт для изменения: " << std::endl;

            int point = getPoint(1, 3);

            switch(point)
            {
                case 1:
                {
                    std::uint16_t newID = 0;
                    while(true)
                    {
                        newID = Utils::getInputNum<int>("Введите новый ID: ");

                        if(Product::ProductsManager::isProductExists(newID))
                        {
                            std::cout << "Продукт с таким ID уже существует!" << std::endl;
                            continue;
                        }

                        m_currentEditableProduct->m_id = newID;

                        std::cout << "ID изменён!" << std::endl;
                        break;
                    }

                    break;
                }

                case 2:
                {
                    std::string newName;
                    while(true)
                    {
                        newName = Utils::getLine("Введите новое название: ");

                        m_currentEditableProduct->m_name = newName;

                        std::cout << "Название изменено!" << std::endl;
                        break;
                    }

                    break;
                }

                case 3:
                {
                    float newCost;
                    while(true)
                    {
                        newCost = Utils::getInputNum<float>("Введите новую стоимость: ");

                        m_currentEditableProduct->m_cost = newCost;

                        std::cout << "Стоимость изменена!" << std::endl;
                        break;
                    }

                    break;
                }
            }

            break;
        }
        case DELETE:
        {
            Product::ProductsManager::removeProduct(m_currentEditableProduct->m_id);
            std::cout << "Продукт с ID " << std::to_string(m_currentEditableProduct->m_id) << " был удалён!" << std::endl;

            break;
        }
    }

    Product::ProductsManager::save("products.txt");

    return WindowsManager::getWindow(SYS_ADMIN_MAIN_WND_NAME);
}
