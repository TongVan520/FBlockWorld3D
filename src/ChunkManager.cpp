//
// Created by FireFlower on 2024/11/21.
//

#include "ChunkManager.h"
#include <godot_cpp/variant/callable_method_pointer.hpp>

namespace fireflower {
	ChunkState ChunkManager::getChunkState(const Vector3i& chunk_positionVec3i) const {
		auto p_chunk_state = this->chunk_stateMap.getptr(chunk_positionVec3i);
		return p_chunk_state ? *p_chunk_state : ChunkState::Unloaded;
	}
	
	void ChunkManager::loadChunk(const Vector3i& chunk_positionVec3i) {
		auto state = this->getChunkState(chunk_positionVec3i);
		if (state == ChunkState::Loading || state == ChunkState::Loaded) {
			return;
		}
		this->chunkLoadRequested.emitSignal(chunk_positionVec3i);
	}
	
	void ChunkManager::unloadChunk(const Vector3i& chunk_positionVec3i) {
		auto state = this->getChunkState(chunk_positionVec3i);
		if (state == ChunkState::Unloading || state == ChunkState::Unloaded) {
			return;
		}
		this->chunkUnloadRequested.emitSignal(chunk_positionVec3i);
	}
	
	void ChunkManager::setLoadedSignal(const Ref<FSignal1>& loadedSignal) {
		// this->chunkLoaded->disconnectSignal();
		// this->chunkLoaded = loadedSignal;
	}
	
	void ChunkManager::onChunkLoaded(const Vector3i& chunk_positionVec3i) {
		// this->
	}
} // fireflower