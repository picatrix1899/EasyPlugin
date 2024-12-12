#pragma once

#include <map>
#include <typeindex>

namespace EasyPlugin {

	class AppObjectStoreIntern {
	private:
		std::map<std::type_index,void*> m_Objects;

	public:
		virtual ~AppObjectStoreIntern() = default;

	public:
		template <typename T>
		void Add(const T* value) {
			this->m_Objects[typeid(T)] = (void*)value;
		}

		template <typename T>
		T* Get() const {
			auto iterator = this->m_Objects.find(typeid(T));
			if (iterator != this->m_Objects.end()) {
				return (T*)iterator->second;
			}

			return nullptr;
		}
	};

}