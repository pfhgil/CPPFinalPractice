//
// Created by stuka on 18.06.2023.
//

#include "ChooseProductWindow.h"

#include "Product/ProductsManager.h"

std::shared_ptr<FinalPractice::Main::Windows::IWindow> FinalPractice::Main::SysAdmin::ChooseProductWindow::show()
{
    int productNum = 0;
    for(const auto& product : Product::ProductsManager::getProducts())
    {
        std::cout << std::to_string(productNum) << ") ID: " << product->m_id << ", Имя: " << product->m_name << std::endl;
    }

    std::cout << "Выберите продукт: ";

    int chosenProduct = getPoint(0, Product::ProductsManager::getProducts().size());

    productNum = 0;
    for(const auto& product : Product::ProductsManager::getProducts())
    {
        if(productNum == chosenProduct)
        {
            //return product;
            break;
        }
        productNum++;
    }

    return std::shared_ptr<IWindow>();
}
