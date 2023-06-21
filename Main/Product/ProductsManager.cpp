//
// Created by stuka on 18.06.2023.
//

#include "ProductsManager.h"
#include "fstream"
#include "json.hpp"

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

void FinalPractice::Main::Product::ProductsManager::save(const std::string_view& path)
{
    std::ofstream productsFStream(path.data());

    auto products = nlohmann::json();

    products["productsNum"] = m_products.size();

    int cur = 0;
    for(auto& product : m_products)
    {
        products["products"][cur]["id"] = product->m_id;
        products["products"][cur]["name"] = product->m_name;
        products["products"][cur]["cost"] = product->m_cost;

        cur++;
    }

    productsFStream << products.dump(4);
}

void FinalPractice::Main::Product::ProductsManager::load(const std::string_view& path)
{
    if(!std::filesystem::exists(path)) return;

    std::ifstream productsFStream(path.data());
    auto products = nlohmann::json::parse(productsFStream);

    int productsNum = products["productsNum"];

    for(int i = 0; i < productsNum; i++)
    {
        std::shared_ptr<Product> newProduct = createProduct();

        newProduct->m_id = products["products"][i]["id"];
        newProduct->m_name = products["products"][i]["name"];
        newProduct->m_cost = products["products"][i]["cost"];
    }
}


bool FinalPractice::Main::Product::ProductsManager::isProductExists(const std::uint16_t& productID) noexcept
{
    return std::find_if(m_products.begin(), m_products.end(), [&](const std::shared_ptr<Product>& product)
                        { return product->m_id == productID; }) != m_products.end();
}

std::list<std::shared_ptr<FinalPractice::Main::Product::Product>>& FinalPractice::Main::Product::ProductsManager::getProducts() noexcept
{
    return m_products;
}

void FinalPractice::Main::Product::ProductsManager::removeProduct(const uint16_t& ID) noexcept
{
    m_products.remove_if([&](const std::shared_ptr<Product>& product){ return product->m_id == ID; });
}

std::shared_ptr<FinalPractice::Main::Product::Product> FinalPractice::Main::Product::ProductsManager::getProduct(const uint16_t& ID) noexcept
{
    return *std::find_if(m_products.begin(), m_products.end(), [&](const std::shared_ptr<Product>& product)
    { return product->m_id == ID; });
}
