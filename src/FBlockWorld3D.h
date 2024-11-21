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

#include "GodotHelper/GodotHelper.h"

namespace godot {
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
		/// @描述 加载区块时，以当前区块为中心向外扩展，被其<b>完全</b>覆盖的区块会被加载\n
		/// 单位：区块\n
		/// 默认为 1 * 1 * 1
		Vector3i load_chunk_sizeVec3i = Vector3i(1, 1, 1);
		
		/// @名称 忽略区块大小
		/// @描述 卸载区块时，以当前区块为中心向外扩展，被其<b>完全</b>覆盖的区块会被卸载\n
		/// 单位：区块\n
		/// 默认为 2 * 2 * 2
		Vector3i ignore_chunk_sizeVec3i = Vector3i(2, 2, 2);
		
		/// @名称 当前区块位置
		Vector3i current_chunk_positionVec3i = Vector3i(0, 0, 0);
	
	public:
		FBlockWorld3D() = default;
		virtual ~FBlockWorld3D() = default;
		FBlockWorld3D(const FBlockWorld3D&) = delete;
		
		// FBlockWorld3D& operator=(const FBlockWorld3D&) = delete;
		
		/// @名称 SayHello
		/// @描述 测试用，静态函数
		static void sayHello();
		
		void _ready() override;
		
		void setChunkSize(const Vector3i& new_chunk_sizeVec3i);
		Vector3i getChunkSize() const;
		void emitChunkSizeChanged(const Vector3i& new_chunk_sizeVec3i);
		
		void setLoadChunkSize(const Vector3i& new_load_chunk_sizeVec3i);
		Vector3i getLoadChunkSize() const;
		void emitLoadChunkSizeChanged(const Vector3i& new_load_chunk_sizeVec3i);
		
		void setIgnoreChunkSize(const Vector3i& new_ignore_chunk_sizeVec3i);
		Vector3i getIgnoreChunkSize() const;
		void emitIgnoreChunkSizeChanged(const Vector3i& new_ignore_chunk_sizeVec3i);
		
		void setCurrentChunkPosition(const Vector3i& new_current_chunk_positionVec3i);
		Vector3i getCurrentChunkPosition() const;
		void emitCurrentChunkChanged(const Vector3i& new_current_chunk_positionVec3i);
		
		/// @名称 请求加载区块
		/// @描述 当区块即将被加载时调用
		/// @参数名称 <code>chunk_positionVec3i</code>
		/// @参数描述 区块位置
		/// @返回值
		// virtual void requestLoadChunk(const Vector3i& chunk_positionVec3i);
		// virtual void requestUnloadChunk(const Vector3i& chunk_positionVec3i);
	
	protected:
		static void _bind_methods();
	};
} // godot

#endif //FBLOCKWORLD3D_FBLOCKWORLD3D_H
