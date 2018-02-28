//
// Created by kiva on 2018/2/27.
//

#include <unordered_map>
#include <kivm/classLoader.h>
#include <kivm/oop/klass.h>
#include <shared/lock.h>

namespace kivm {
    static Lock &get_bootstrap_lock() {
        static Lock lock;
        return lock;
    }

    static std::unordered_map<String, Klass *> &get_bootstrap_classes() {
        static std::unordered_map<String, Klass *> bootstrap_classes;
        return bootstrap_classes;
    }

    Klass *ClassLoader::require_class(ClassLoader *classLoader, const String &className) {
        if (classLoader == nullptr) {
            // This is a bootstrap class
            classLoader = BootstrapClassLoader::get();
        }

        Klass *loaded_class = classLoader == nullptr
                              ? nullptr
                              : classLoader->loadClass(className);
        if (loaded_class == nullptr) {
            // TODO: throw LinkageError
            assert(false);
            return nullptr;
        }
        return loaded_class;
    }

    BootstrapClassLoader *BootstrapClassLoader::get() {
        static BootstrapClassLoader classLoader;
        return &classLoader;
    }

    Klass *BootstrapClassLoader::loadClass(const String &class_name) {
        LockGuard guard(get_bootstrap_lock());
        auto &cache_map = get_bootstrap_classes();

        // check whether class is already loaded
        auto iter = cache_map.find(class_name);
        if (iter != cache_map.end()) {
            return iter->second;
        }

        // OK, let's find it!
        return BaseClassLoader::loadClass(class_name);
    }
}
