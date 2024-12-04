//
// Created by FireFlower on 2024/11/16.
//

#ifndef FBLOCKWORLD3D_FBLOCKWORLD3D_H
#define FBLOCKWORLD3D_FBLOCKWORLD3D_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/vector3i.hpp>
#include <godot_cpp/classes/grid_map.hpp>
#include <godot_cpp/classes/ref.hpp>

#include <FSignal/FSignal.h>

#include "../GodotHelper/GodotHelper.h"
#include "ChunkManager.h"
#include "FRegion3i.h"

using godot::Node3D, godot::GridMap, godot::Vector3i;

namespace fireflower {
	/// @类名 3D方块世界
	/// @描述 自动生成、加载、保存地形的方块世界类
	class FBlockWorld3D : public Node3D {
	GDCLASS(FBlockWorld3D, Node3D);
	
	DirectChildNodeRef(GridMap, GridMap, "GridMap");
	
	private:
		/// @名称 区块大小
		/// @描述 默认为 16 * 16 * 16
		Vector3i chunk_sizeVec3i = Vector3i(16, 16, 16);
		
		/// @名称 加载区块大小
		/// @描述 加载区块时，以当前区块为中心向外扩展，由该大小作为边长可以确定一个六面体，被其<b>完全</b>覆盖的区块会被加载\n
		/// 单位：区块\n
		/// 默认为 1 * 1 * 1
		Vector3i load_chunk_sizeVec3i = Vector3i(1, 1, 1);
		
		/// @名称 忽略区块大小
		/// @描述 卸载区块时，以当前区块为中心向外扩展，由该大小作为边长可以确定一个六面体，被其<b>完全</b>覆盖的区块会被卸载\n
		/// 单位：区块\n
		/// 默认为 3 * 3 * 3
		Vector3i ignore_chunk_sizeVec3i = Vector3i(3, 3, 3);
		
		/// @名称 当前区块位置
		/// @描述 单位：区块\n
		/// 默认为 <code>Vector3i(0, 0, 0)</code>
		Vector3i current_chunk_positionVec3i = Vector3i(0, 0, 0);
		// Vector3i last_chunk_positionVec3i;
		
		/// @名称 区块管理器
		ChunkManager chunk_manager;
		
		/// @名称 上一忽略区域
		/// @描述 在<i>当前区块位置</i>改变前的忽略区域
		FRegion3i last_ignoreRegion3i;
	
	public:
		Ref<FSignal1> chunkSizeChanged;
		Ref<FSignal1> loadChunkSizeChanged;
		Ref<FSignal1> currentChunkPositionChanged;
	
	public:
		FBlockWorld3D();
		
		/// @名称 SayHello
		/// @描述 测试用，静态函数
		static void sayHello();
		
		void _ready() override;
		
		void setChunkSize(const Vector3i& new_chunk_sizeVec3i);
		Vector3i getChunkSize() const;
		Ref<FSignal1> getChunkSizeChangedSignal() const;
		
		void setLoadChunkSize(const Vector3i& new_load_chunk_sizeVec3i);
		Vector3i getLoadChunkSize() const;
		Ref<FSignal1> getLoadChunkSizeChangedSignal() const;
		
		void setCurrentChunkPosition(const Vector3i& new_current_chunk_positionVec3i);
		Vector3i getCurrentChunkPosition() const;
		Ref<FSignal1> getCurrentChunkPositionChangedSignal() const;
	
	protected:
		static void _bind_methods();
		
	};
}

#endif //FBLOCKWORLD3D_FBLOCKWORLD3D_H
