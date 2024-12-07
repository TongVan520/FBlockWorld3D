//
// Created by FireFlower on 2024/12/7.
//

#include "FInnateTerrianMaid.h"

#include <godot_cpp/classes/grid_map.hpp>

using namespace godot;

namespace fireflower {
	shared_ptr<FBlock> FSeedInnateTerrainMaid::getBlock(const Vector3i& positionVec3i) const {
		FBlock::IntType max_height = this->noise->get_noise_2dv(Vector2(positionVec3i.x, positionVec3i.z));
		return shared_ptr<FBlock>(new FNormalBlock(positionVec3i.y <= max_height ? 0 : GridMap::INVALID_CELL_ITEM));
	}
	
	void FSeedInnateTerrainMaid::_ready() {
		this->noise.instantiate();
	}
	
	void FInnateTerrianMaid::_bind_methods() {
	
	}
}

namespace fireflower {

}
