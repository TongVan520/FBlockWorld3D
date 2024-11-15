//
// Created by FireFlower on 2024/11/16.
//

#include "FBlockWorld3D.h"
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot {
	void FBlockWorld3D::_bind_methods() {
		ClassDB::bind_method(D_METHOD("sayHello"), &FBlockWorld3D::sayHello);
	}
	
	void FBlockWorld3D::sayHello() const {
		UtilityFunctions::print(L"FBlockWorld3D");
		UtilityFunctions::print(L"方块世界3D");
	}
} // godot