//
// Created by FireFlower on 2024/11/21.
//

#ifndef FBLOCKWORLD3D_CHUNKMANAGER_H
#define FBLOCKWORLD3D_CHUNKMANAGER_H

#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/vector3i.hpp>
#include <FSignal/FSignal.h>
#include <godot_cpp/classes/ref.hpp>

namespace fireflower {
	using namespace godot;
	
	/// @类名 区块状态
	enum class ChunkState {
		/// @名称 已卸载
		/// @描述 表示<i>区块未加载</i>或<i>区块已卸载</i>
		Unloaded = 0,
		
		/// @名称 加载中
		/// @描述 表示<i>区块正在加载</i>
		Loading,
		
		/// @名称 已加载
		/// @描述 表示<i>区块已完成加载</i>
		Loaded,
		
		/// @名称 卸载中
		/// @描述 表示<i>区块正在卸载</i>
		Unloading,
	};
	
	/// @类名 区块管理器
	/// @描述 根据区块的状态决定对区块的操作
	class ChunkManager {
	private:
		/// @名称 区块下标-区块状态映射图
		/// @描述 键：区块下标\n
		/// 值：区块状态
		HashMap<Vector3i, ChunkState> chunk_stateMap;
		
		/// @名称 区块加载完成信号
		Ref<FSignal1> chunkLoaded;
		
		/// @名称 区块卸载完成信号
		Ref<FSignal1> chunkUnloaded;
	
	public:
		/// @名称 区块加载请求
		/// @描述 当区块真正需要加载时发出
		FSignal1 chunkLoadRequested;
		
		/// @名称 区块卸载请求
		/// @描述 当区块真正需要卸载时发出
		FSignal1 chunkUnloadRequested;
	
	private:
		void onChunkLoaded(const Vector3i& chunk_positionVec3i);
		void onChunkUnloaded(const Vector3i& chunk_positionVec3i);
		
	public:
		/// @名称 获取区块状态
		/// @参数名称 chunk_positionVec3i
		/// @参数描述 区块下标位置
		/// @返回值 区块状态
		ChunkState getChunkState(const Vector3i& chunk_positionVec3i) const;
		
		/// @名称 加载区块
		/// @描述 根据区块状态决定是否真正地加载区块
		/// @参数名称 chunk_positionVec3i
		/// @参数描述 区块下标位置
		void loadChunk(const Vector3i& chunk_positionVec3i);
		
		/// @名称 卸载区块
		/// @描述 根据区块状态决定是否真正地卸载区块
		/// @参数名称 chunk_positionVec3i
		/// @参数描述 区块下标位置
		void unloadChunk(const Vector3i& chunk_positionVec3i);
		
		void setLoadedSignal(const Ref<FSignal1>& loadedSignal);
		void setUnloadedSignal(const Ref<FSignal1>& unloadedSignal);
	};
	
} // fireflower

#endif //FBLOCKWORLD3D_CHUNKMANAGER_H
