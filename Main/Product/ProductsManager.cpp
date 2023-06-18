//
// Created by stuka on 18.06.2023.
//

#include "ProductsManager.h"

std::shared_ptr<FinalPractice::Main::Product::Product> FinalPractice::Main::Product::ProductsManager::createProduct() noexcept
{
    std::shared_ptr<Product> newProduct = std::make_shared<Product>();

    int maxID = 0;
    for(const auto& product : m_products)
    {
        if(product->m_id > maxID)
        {
            maxID = product->m_id;
        }
    }

    newProduct->m_id = maxID + 1;

    m_products.push_back(newProduct);

    return newProduct;
}

bool FinalPractice::Main::Product::ProductsManager::isProductExists(const std::uint16_t& productID) noexcept
{
    return *std::find_if(m_products.begin(), m_products.end(), [&](const std::shared_ptr<Product>& product)
                        { return product->m_id == productID; }) != nullptr;
}

std::list<std::shared_ptr<FinalPractice::Main::Product::Product>> FinalPractice::Main::Product::ProductsManager::getProducts() noexcept
{
    return m_products;
}
