//
// Created by stuka on 18.06.2023.
//

#include "ChooseProductWindow.h"

#include "Product/ProductsManager.h"
#include "EditProductWindow.h"
#include "Windows/WindowsManager.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::Windows::SysAdmin::ChooseProductWindow::show()
{
    int productNum = 0;
    for(const auto& product : Product::ProductsManager::getProducts())
    {
        std::cout << std::to_string(productNum) << ") ID: " << product->m_id <<
        ", Имя: " << product->m_name << ", цена: " << std::to_string(product->m_cost) << std::endl;

        productNum++;
    }

    std::cout << "Выберите продукт: ";

    int chosenProduct = getPoint(0, Product::ProductsManager::getProducts().size());

    productNum = 0;
    for(const auto& product : Product::ProductsManager::getProducts())
    {
        if(productNum == chosenProduct)
        {
            EditProductWindow::m_currentEditablePerson = product;
            break;
        }
        productNum++;
    }

    return WindowsManager::getWindow(SYS_ADMIN_EDIT_PRODUCT_WND_NAME);
}
