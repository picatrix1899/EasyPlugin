#pragma once

#include "EasyPlugin/AppObjectStoreIntern.h"

namespace EasyPlugin {

	class AppObjectStore {
	public:
		static AppObjectStoreIntern* s_Internal;

	public:
		template <typename T>
		static inline void Add(const T* value) {
			AppObjectStore::s_Internal->Add(value);
		}

		template <typename T>
		static inline T* Get() {
			return AppObjectStore::s_Internal->Get<T>();
		}
	};

}