//
// Created by FireFlower on 2024/11/21.
//

#include "ChunkManager.h"

using namespace godot;

namespace fireflower {
	ChunkManager::ChunkManager() :
		onChunkLoadedSlot(
			FSlot1::makeFromLambda(
				[this](const Variant& chunk_position) {
					auto chunk_positionVec3i = VariantCaster<Vector3i>::cast(chunk_position);
					this->onChunkLoaded(chunk_positionVec3i);
				}
			)
		),
		onChunkUnloadedSlot(
			FSlot1::makeFromLambda(
				[this](const Vector3i& chunk_position) {
					auto chunk_positionVec3i = VariantCaster<Vector3i>::cast(chunk_position);
					this->onChunkUnloaded(chunk_positionVec3i);
				}
			)
		) {
		
	}
	
	ChunkState ChunkManager::getChunkState(const Vector3i& chunk_positionVec3i) const {
		auto p_chunk_state = this->chunk_stateMap.getptr(chunk_positionVec3i);
		return p_chunk_state ? *p_chunk_state : ChunkState::Unloaded;
	}
	
	void ChunkManager::requestLoadChunk(const Vector3i& chunk_positionVec3i) {
		auto state = this->getChunkState(chunk_positionVec3i);
		if (state == ChunkState::Loading || state == ChunkState::Loaded) {
			return;
		}
		this->chunkLoadRequested->emit(chunk_positionVec3i);
	}
	
	void ChunkManager::requestUnloadChunk(const Vector3i& chunk_positionVec3i) {
		auto state = this->getChunkState(chunk_positionVec3i);
		if (state == ChunkState::Unloading || state == ChunkState::Unloaded) {
			return;
		}
		this->chunkUnloadRequested->emit(chunk_positionVec3i);
	}
	
	void ChunkManager::setChunkLoadedSignal(const Ref<FSignal1>& chunk_loadedSignal) {
		this->chunkLoaded->disconnect(this->onChunkLoadedSlot);
		this->chunkLoaded = chunk_loadedSignal;
		this->chunkLoaded->connect(this->onChunkLoadedSlot);
	}
	
	void ChunkManager::setChunkUnloadedSignal(const Ref<FSignal1>& chunk_unloadedSignal) {
		this->chunkUnloaded->disconnect(this->onChunkUnloadedSlot);
		this->chunkUnloaded = chunk_unloadedSignal;
		this->chunkUnloaded->connect(this->onChunkUnloadedSlot);
	}
	
	void ChunkManager::onChunkLoaded(const Vector3i& chunk_positionVec3i) {
		this->chunk_stateMap[chunk_positionVec3i] = ChunkState::Loaded;
	}
	
	void ChunkManager::onChunkUnloaded(const Vector3i& chunk_positionVec3i) {
		this->chunk_stateMap[chunk_positionVec3i] = ChunkState::Unloaded;
		
		// 从 区块状态映射图中 移除 已卸载的区块
		this->chunk_stateMap.erase(chunk_positionVec3i);
	}
} // fireflower