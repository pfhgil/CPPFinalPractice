//
// Created by stuka on 20.06.2023.
//

#ifndef FINAL_PRACTICE_WAREHOUSEMANAGER_H
#define FINAL_PRACTICE_WAREHOUSEMANAGER_H

#include <list>
#include <memory>
#include "ProductsSet.h"

namespace FinalPractice::Main::Warehouse
{
    class WarehouseManager
    {
    public:
        static inline std::list<std::shared_ptr<ProductsSet>> m_productsInWarehouse;
        static inline std::list<std::shared_ptr<ProductsSet>> m_orderedProducts;

        static void save(const std::string_view&);
        static void load(const std::string_view&);

        // забирает продукт из склада
        static std::shared_ptr<ProductsSet> takeProduct(const int& id) noexcept;
    };
}

#endif //FINAL_PRACTICE_WAREHOUSEMANAGER_H
