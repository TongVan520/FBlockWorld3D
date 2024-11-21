//
// Created by FireFlower on 2024/11/21.
//

#include "ChunkManager.h"

namespace fireflower {
	ChunkState ChunkManager::getChunkState(const Vector3i& chunk_positionVec3i) const {
		auto p_chunk_state = this->chunk_stateMap.getptr(chunk_positionVec3i);
		return p_chunk_state ? *p_chunk_state : ChunkState::Unloaded;
	}
} // fireflower