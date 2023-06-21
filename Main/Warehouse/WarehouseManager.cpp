//
// Created by stuka on 20.06.2023.
//

#include <json.hpp>
#include <fstream>
#include <cmath>

#include "WarehouseManager.h"
#include "ProductsSet.h"

void FinalPractice::Main::Warehouse::WarehouseManager::save(const std::string_view& path)
{
    std::ofstream warehouseFStream(path.data());

    auto warehouse = nlohmann::json();

    warehouse["productsInWarehouseCount"] = m_productsInWarehouse.size();
    warehouse["orderedProductsCount"] = m_orderedProducts.size();

    int currentProductNum = 0;
    for(const auto& productInWarehouse : m_productsInWarehouse)
    {
        warehouse["productsInWarehouse"][currentProductNum]["count"] = productInWarehouse->m_count;

        warehouse["productsInWarehouse"][currentProductNum]["id"] = productInWarehouse->m_product->m_id;
        warehouse["productsInWarehouse"][currentProductNum]["name"] = productInWarehouse->m_product->m_name;
        warehouse["productsInWarehouse"][currentProductNum]["cost"] = productInWarehouse->m_product->m_cost;

        currentProductNum++;
    }

    currentProductNum = 0;
    for(const auto& orderedProduct: m_orderedProducts)
    {
        warehouse["orderedProducts"][currentProductNum]["count"] = orderedProduct->m_count;

        warehouse["orderedProducts"][currentProductNum]["id"] = orderedProduct->m_product->m_id;
        warehouse["orderedProducts"][currentProductNum]["name"] = orderedProduct->m_product->m_name;
        warehouse["orderedProducts"][currentProductNum]["cost"] = orderedProduct->m_product->m_cost;

        currentProductNum++;
    }

    warehouseFStream << warehouse.dump(4);
}

void FinalPractice::Main::Warehouse::WarehouseManager::load(const std::string_view& path)
{
    if(!std::filesystem::exists(path)) return;

    std::ifstream warehouseFStream(path.data());
    auto warehouse = nlohmann::json::parse(warehouseFStream);

    int productsInWarehouseCount = warehouse["productsInWarehouseCount"];
    int orderedProductsCount = warehouse["orderedProductsCount"];

    for(int i = 0; i < productsInWarehouseCount; i++)
    {
        std::shared_ptr<ProductsSet> newProductsSet = std::make_shared<ProductsSet>();
        newProductsSet->m_product = std::make_shared<Product::Product>();

        newProductsSet->m_count = warehouse["productsInWarehouse"][i]["count"];

        newProductsSet->m_product->m_id = warehouse["productsInWarehouse"][i]["id"];
        newProductsSet->m_product->m_name = warehouse["productsInWarehouse"][i]["name"];
        newProductsSet->m_product->m_cost = warehouse["productsInWarehouse"][i]["cost"];

        m_productsInWarehouse.push_back(newProductsSet);
    }

    for(int i = 0; i < orderedProductsCount; i++)
    {
        std::shared_ptr<ProductsSet> newProductsSet = std::make_shared<ProductsSet>();
        newProductsSet->m_product = std::make_shared<Product::Product>();

        newProductsSet->m_count = warehouse["orderedProducts"][i]["count"];

        newProductsSet->m_product->m_id = warehouse["orderedProducts"][i]["id"];
        newProductsSet->m_product->m_name = warehouse["orderedProducts"][i]["name"];
        newProductsSet->m_product->m_cost = warehouse["orderedProducts"][i]["cost"];

        m_orderedProducts.push_back(newProductsSet);
    }
}

std::shared_ptr<FinalPractice::Main::Warehouse::ProductsSet> FinalPractice::Main::Warehouse::WarehouseManager::takeProduct(const int& id) noexcept
{
    // поиск продукта по id
    for(const auto& productSet : m_productsInWarehouse)
    {
        if(productSet->m_product->m_id == id)
        {
            if(productSet->m_count - 1 < 0)
            {
                std::cout << "Недостаточно продуктов на складе!" << std::endl;
                return nullptr;
            }

            // убираем продукт, если больше нет на складе
            if(productSet->m_count - 1 == 0)
            {
                m_productsInWarehouse.remove(productSet);
            }

            // вычитаем один продукт
            productSet->m_count = productSet->m_count - 1 < 0 ? 0 : productSet->m_count - 1;

            return productSet;
        }
    }

    std::cout << "Продукт не найден!" << std::endl;
    return nullptr;
}
