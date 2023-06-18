#pragma once

#ifndef FINAL_PRACTICE_PRODUCTSMANAGER_H
#define FINAL_PRACTICE_PRODUCTSMANAGER_H

#include <list>
#include <memory>

#include "Product.h"

namespace FinalPractice::Main::Product
{
    class ProductsManager
    {
    private:
        static std::list<std::shared_ptr<Product>> m_products;

    public:
        static std::shared_ptr<Product> createProduct() noexcept;

        static bool isProductExists(const std::uint16_t& productID) noexcept;

        static std::list<std::shared_ptr<Product>> getProducts() noexcept;
    };
}

#endif //FINAL_PRACTICE_PRODUCTSMANAGER_H
