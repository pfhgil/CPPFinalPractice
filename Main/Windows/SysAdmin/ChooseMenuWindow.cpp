//
// Created by stuka on 19.06.2023.
//

#include "ChooseMenuWindow.h"

#include "Menu/MenuManager.h"
#include "Utils.h"
#include "EditMenuWindow.h"
#include "Product/ProductsManager.h"
#include "Warehouse/WarehouseManager.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::SysAdmin::ChooseMenuWindow::show()
{
    int menuNum = 0;
    for(const auto& menu : Menu::MenuManager::getMenus())
    {
        std::cout << std::to_string(menuNum + 1) << ") Название: " << menu->m_name << ", граммовка: " << std::to_string(menu->m_gram)
        << ", описание: " << menu->m_description << ", время приготовления: " << std::to_string(menu->m_cookingTimeSeconds)
        << ", стоимость: " << menu->m_cost << std::endl;

        menuNum++;
    }

    std::cout << "Выберите пункт (номер): ";
    int point = getPoint(1, menuNum);
    std::shared_ptr<Menu::Menu> chosenMenu;

    // поиск соответствующего блюда
    menuNum = 1;
    for(const auto& menu: Menu::MenuManager::getMenus())
    {
        if(point == menuNum)
        {
            chosenMenu = menu;
        }
        menuNum++;
    }

    switch(EditMenuWindow::m_editMode)
    {
        case EDIT:
        {
            std::cout << "1) Состав\n2) Название\n3) Граммовка\n4) Описание\n5) Время приготовления\n6) Стоимость" << std::endl;
            int editPoint = getPoint(1, 6);

            switch(editPoint)
            {
                case 1:
                {
                    chosenMenu->getProducts().clear();

                    // вывод существующих продуктов
                    int productsNum = 1;
                    for(const auto& product : Product::ProductsManager::getProducts())
                    {
                        std::cout << std::to_string(productsNum) << ") ID: " << product->m_id << ", название: " << product->m_name << ", цена: " << product->m_cost << std::endl;

                        productsNum++;
                    }

                    // добавление продуктов в меню
                    std::int16_t chosenProduct = 0;
                    while(true)
                    {
                        std::cout << "Выберите продукт, который хотите добавить в блюдо (введите 0, чтобы продолжить): ";
                        chosenProduct = getPoint(0, productsNum + 1);

                        if(chosenProduct == 0)
                        {
                            break;
                        }

                        productsNum = 1;
                        for(auto& product : Warehouse::WarehouseManager::m_productsInWarehouse)
                        {
                            if(chosenProduct == productsNum)
                            {
                                // забираем продукт
                                auto takenProduct = Warehouse::WarehouseManager::takeProduct(product->m_product->m_id);

                                if(!takenProduct)
                                {
                                    break;
                                }

                                chosenMenu->getProducts().push_back(takenProduct->m_product);

                                std::cout << "Продукт '" << takenProduct->m_product->m_name << "' (ID: " << std::to_string(takenProduct->m_product->m_id) << ") был добавлен в блюдо!" << std::endl;
                                break;
                            }

                            productsNum++;
                        }
                    }

                    break;
                }
                case 2:
                {
                    chosenMenu->m_name = Utils::getLine("Введите новое название блюда: ");

                    break;
                }
                case 3:
                {
                    chosenMenu->m_gram = Utils::getInputNum<int>("Введите новую граммовку блюда: ");

                    break;
                }
                case 4:
                {
                    chosenMenu->m_description = Utils::getLine("Введите новое описание блюда: ");

                    break;
                }
                case 5:
                {
                    chosenMenu->m_cookingTimeSeconds = Utils::getInputNum<int>("Введите новое время приготовления блюда: ");

                    break;
                }
                case 6:
                {
                    chosenMenu->m_cost = Utils::getInputNum<int>("Введите новую стоимость блюда: ");

                    break;
                }
            }

            break;
        }
        case DELETE:
        {
            Menu::MenuManager::removeMenu(chosenMenu->m_name);

            std::cout << "Блюдо удалено!" << std::endl;

            break;
        }
    }

    Menu::MenuManager::save("menus.txt");

    return WindowsManager::getWindow(SYS_ADMIN_MAIN_WND_NAME);
}
