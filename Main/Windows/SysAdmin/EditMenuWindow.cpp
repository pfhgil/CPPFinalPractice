//
// Created by stuka on 19.06.2023.
//

#include "EditMenuWindow.h"
#include "Menu/MenuManager.h"
#include "Product/ProductsManager.h"
#include "Utils.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::SysAdmin::EditMenuWindow::show()
{
    switch(m_editMode)
    {
        case CREATE:
        {
            std::shared_ptr<Menu::Menu> newMenu = Menu::MenuManager::createMenu();

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
                chosenProduct = getPoint(0, productsNum);

                if(chosenProduct == 0)
                {
                    break;
                }

                productsNum = 1;
                for(auto const& product : Product::ProductsManager::getProducts())
                {
                    if(chosenProduct == productsNum)
                    {
                        newMenu->getProducts().push_back(product);

                        std::cout << "Продукт '" << product->m_name << "' (ID: " << std::to_string(product->m_id) << ") был добавлен в блюдо!" << std::endl;
                        break;
                    }

                    productsNum++;
                }
            }

            std::cin.sync();
            // ввод имени
            std::cout << "Введите имя нового блюда: ";
            std::getline(std::cin, newMenu->m_name);

            std::cin.sync();
            // ввод описания
            std::cout << "Введите описание нового блюда: ";
            std::getline(std::cin, newMenu->m_description);

            // ввод граммовки
            newMenu->m_gram = Utils::getInputNum<int>("Введите граммовку блюда: ");;

            // ввод времени приготовления блюда
            newMenu->m_cookingTimeSeconds = Utils::getInputNum<int>("Введите время приготовления блюда: ");

            // ввод стоимости
            newMenu->m_cost = Utils::getInputNum<float>("Введите стоимость блюда: ");

            Menu::MenuManager::save("menus.txt");

            break;
        }
        case EDIT:break;
        case DELETE:
        {


            break;
        }
    }

    return WindowsManager::getWindow(SYS_ADMIN_MAIN_WND_NAME);
}
