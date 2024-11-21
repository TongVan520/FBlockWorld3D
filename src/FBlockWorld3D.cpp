//
// Created by FireFlower on 2024/11/16.
//

#include "FBlockWorld3D.h"

namespace godot {
	void FBlockWorld3D::_bind_methods() {
		ClassDB::bind_static_method(FBlockWorld3D::get_class_static(), D_METHOD("sayHello"), &FBlockWorld3D::sayHello);
		
		// chunk_size
		{
			// 属性 chunk_sizeVec3i
			ClassDB::bind_method(D_METHOD("setChunkSize", "new_chunk_sizeVec3i"), &FBlockWorld3D::setChunkSize);
			ClassDB::bind_method(D_METHOD("getChunkSize"), &FBlockWorld3D::getChunkSize);
			ClassDB::add_property(
				FBlockWorld3D::get_class_static(),
				PropertyInfo(Variant::VECTOR3I, "chunk_sizeVec3i"),
				"setChunkSize",
				"getChunkSize"
			);
			
			// 信号 chunkSizeChanged
			ClassDB::add_signal(
				FBlockWorld3D::get_class_static(),
				MethodInfo(
					"chunkSizeChanged",
					PropertyInfo(Variant::VECTOR3I, "new_chunk_sizeVec3i")
				)
			);
		}
		
		// load_chunk_sizeVec3i
		{
			// 属性 load_chunk_sizeVec3i
			ClassDB::bind_method(
				D_METHOD("setLoadChunkSize", "new_load_chunk_sizeVec3i"),
				&FBlockWorld3D::setLoadChunkSize
			);
			ClassDB::bind_method(D_METHOD("getLoadChunkSize"), &FBlockWorld3D::getLoadChunkSize);
			ClassDB::add_property(
				FBlockWorld3D::get_class_static(),
				PropertyInfo(Variant::VECTOR3I, "load_chunk_sizeVec3i"),
				"setLoadChunkSize",
				"getLoadChunkSize"
			);
			
			// 信号 loadChunkSizeChanged
			ClassDB::add_signal(
				FBlockWorld3D::get_class_static(),
				MethodInfo(
					"loadChunkSizeChanged",
					PropertyInfo(Variant::VECTOR3I, "new_load_chunk_sizeVec3i")
				)
			);
		}
		
		// ignore_chunk_sizeVec3i
		{
			// 属性 ignore_chunk_sizeVec3i
			ClassDB::bind_method(
				D_METHOD("setIgnoreChunkSize", "new_ignore_chunk_sizeVec3i"),
				&FBlockWorld3D::setIgnoreChunkSize
			);
			ClassDB::bind_method(D_METHOD("getIgnoreChunkSize"), &FBlockWorld3D::getIgnoreChunkSize);
			ClassDB::add_property(
				FBlockWorld3D::get_class_static(),
				PropertyInfo(Variant::VECTOR3I, "ignore_chunk_sizeVec3i"),
				"setIgnoreChunkSize",
				"getIgnoreChunkSize"
			);
		}
		
		// current_chunk_positionVec3i
		{
			// 属性 current_chunk_positionVec3i
			ClassDB::bind_method(
				D_METHOD("setCurrentChunkPosition", "new_current_chunk_positionVec3i"),
				&FBlockWorld3D::setCurrentChunkPosition
			);
			ClassDB::bind_method(D_METHOD("getCurrentChunkPosition"), &FBlockWorld3D::getCurrentChunkPosition);
			ClassDB::add_property(
				FBlockWorld3D::get_class_static(),
				PropertyInfo(Variant::VECTOR3I, "current_chunk_positionVec3i"),
				"setCurrentChunkPosition",
				"getCurrentChunkPosition"
			);
			
			// 信号 currentChunkChanged
			ClassDB::add_signal(
				FBlockWorld3D::get_class_static(),
				MethodInfo(
					"currentChunkChanged",
					PropertyInfo(Variant::VECTOR3I, "new_chunk_positionVec3i")
				)
			);
		}
	}
	
	void FBlockWorld3D::sayHello() {
		UtilityFunctions::print(L"FBlockWorld3D");
		UtilityFunctions::print(L"方块世界3D");
	}
	
	void FBlockWorld3D::setChunkSize(const Vector3i& new_chunk_sizeVec3i) {
		this->chunk_sizeVec3i = new_chunk_sizeVec3i;
		this->emitChunkSizeChanged(new_chunk_sizeVec3i);
	}
	
	Vector3i FBlockWorld3D::getChunkSize() const {
		return this->chunk_sizeVec3i;
	}
	
	void FBlockWorld3D::emitChunkSizeChanged(const Vector3i& new_chunk_sizeVec3i) {
		this->emit_signal("chunkSizeChanged", new_chunk_sizeVec3i);
	}
	
	void FBlockWorld3D::setCurrentChunkPosition(const Vector3i& new_current_chunk_positionVec3i) {
		this->current_chunk_positionVec3i = new_current_chunk_positionVec3i;
		this->emitCurrentChunkChanged(new_current_chunk_positionVec3i);
	}
	
	Vector3i FBlockWorld3D::getCurrentChunkPosition() const {
		return this->current_chunk_positionVec3i;
	}
	
	void FBlockWorld3D::emitCurrentChunkChanged(const Vector3i& new_current_chunk_positionVec3i) {
		this->emit_signal("currentChunkChanged", new_current_chunk_positionVec3i);
	}
	
	void FBlockWorld3D::setLoadChunkSize(const Vector3i& new_load_chunk_sizeVec3i) {
		this->load_chunk_sizeVec3i = new_load_chunk_sizeVec3i;
		this->emitLoadChunkSizeChanged(new_load_chunk_sizeVec3i);
	}
	
	Vector3i FBlockWorld3D::getLoadChunkSize() const {
		return this->load_chunk_sizeVec3i;
	}
	
	void FBlockWorld3D::emitLoadChunkSizeChanged(const Vector3i& new_load_chunk_sizeVec3i) {
		this->emit_signal("loadChunkSizeChanged", new_load_chunk_sizeVec3i);
	}
	
	void FBlockWorld3D::setIgnoreChunkSize(const Vector3i& new_ignore_chunk_sizeVec3i) {
		this->ignore_chunk_sizeVec3i = new_ignore_chunk_sizeVec3i;
		this->emitIgnoreChunkSizeChanged(new_ignore_chunk_sizeVec3i);
	}
	
	Vector3i FBlockWorld3D::getIgnoreChunkSize() const {
		return this->ignore_chunk_sizeVec3i;
	}
	
	void FBlockWorld3D::emitIgnoreChunkSizeChanged(const Vector3i& new_ignore_chunk_sizeVec3i) {
		this->emit_signal("ignoreChunkSizeChanged", new_ignore_chunk_sizeVec3i);
	}
	
	// void FBlockWorld3D::requestLoadChunk(const Vector3i& chunk_positionVec3i) {
	//
	// }
	//
	// void FBlockWorld3D::requestUnloadChunk(const Vector3i& chunk_positionVec3i) {
	//
	// }
	
	void FBlockWorld3D::_ready() {
		// auto p_grid_map = memnew(GridMap);
		// p_grid_map->set_name("GridMap");
		// p_grid_map->set_unique_name_in_owner(true);
		// this->add_child(p_grid_map, true, InternalMode::INTERNAL_MODE_FRONT);
		// p_grid_map->set_owner(this);
		
		// InitDirectChildNodeRef(GridMap);
		this->initRefGridMap();
		
		UtilityFunctions::print(L"this->getGridMap() == ", this->getGridMap());
	}
} // godot
