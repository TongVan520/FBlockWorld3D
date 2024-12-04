//
// Created by FireFlower on 2024/11/16.
//

#include "FBlockWorld3D.h"

using namespace godot;

namespace fireflower {
	FBlockWorld3D::FBlockWorld3D() {
		// 自动更新 忽略区块大小
		this->loadChunkSizeChanged->connect(
			FSlot1::makeFromLambda(
				[this](const Variant& new_chunk_size) {
					auto new_chunk_sizeVec3i = VariantCaster<Vector3i>::cast(new_chunk_size);
					// 忽略区块边长 = 加载区块边长 + 2
					this->ignore_chunk_sizeVec3i = new_chunk_sizeVec3i + Vector3i(2, 2, 2);
				}
			)
		);
		
		// 自动更新 区块状态
		this->currentChunkPositionChanged->connect(
			FSlot1::makeFromLambda(
				[this](const Variant& new_current_chunk_position) {
					auto new_current_chunk_positionVec3i = VariantCaster<Vector3i>::cast(new_current_chunk_position);
					
					// 计算加载区域
					auto loadRegion3i = FRegion3i::makeFromCenterSize(
						new_current_chunk_positionVec3i,
						this->load_chunk_sizeVec3i
					);
					// 请求加载区块
					for (const auto& chunk_positionVec3i: static_cast<vector<Vector3i>>(loadRegion3i)) {
						this->chunk_manager.requestLoadChunk(chunk_positionVec3i);
					}
					
					// 计算当前忽略区域
					auto ignoreRegion3i = FRegion3i::makeFromCenterSize(
						new_current_chunk_positionVec3i,
						this->ignore_chunk_sizeVec3i
					);
					// 卸载区块集合 = 上一忽略区域区块集合 - 上一忽略区域 与 当前忽略区域 的重合区域区块集合
					auto unload_chunkVec3iArr = this->last_ignoreRegion3i.exclude(
						this->last_ignoreRegion3i.intersect(ignoreRegion3i)
					);
					// 请求卸载区块
					for (int64_t i = 0; i < unload_chunkVec3iArr.size(); i++) {
						this->chunk_manager.requestUnloadChunk(unload_chunkVec3iArr[i]);
					}
					
					// 更新上一忽略区域
					this->last_ignoreRegion3i = ignoreRegion3i;
				}
			)
		);
	}
	
	void FBlockWorld3D::sayHello() {
		UtilityFunctions::print(L"FBlockWorld3D");
		UtilityFunctions::print(L"方块世界3D");
	}
	
	void FBlockWorld3D::_ready() {
		this->initRefGridMap();
		UtilityFunctions::print(L"this->getGridMap() == ", this->getGridMap());
	}
	
	void FBlockWorld3D::setChunkSize(const Vector3i& new_chunk_sizeVec3i) {
		if (this->chunk_sizeVec3i == new_chunk_sizeVec3i) {
			return;
		}
		this->chunk_sizeVec3i = new_chunk_sizeVec3i;
		this->chunkSizeChanged->emit(new_chunk_sizeVec3i);
	}
	
	Vector3i FBlockWorld3D::getChunkSize() const {
		return this->chunk_sizeVec3i;
	}
	
	Ref<FSignal1> FBlockWorld3D::getChunkSizeChangedSignal() const {
		return this->chunkSizeChanged;
	}
	
	void FBlockWorld3D::setLoadChunkSize(const Vector3i& new_load_chunk_sizeVec3i) {
		if (this->load_chunk_sizeVec3i == new_load_chunk_sizeVec3i) {
			return;
		}
		this->load_chunk_sizeVec3i = new_load_chunk_sizeVec3i;
		this->loadChunkSizeChanged->emit(new_load_chunk_sizeVec3i);
	}
	
	Vector3i FBlockWorld3D::getLoadChunkSize() const {
		return this->load_chunk_sizeVec3i;
	}
	
	Ref<FSignal1> FBlockWorld3D::getLoadChunkSizeChangedSignal() const {
		return this->loadChunkSizeChanged;
	}
	
	void FBlockWorld3D::setCurrentChunkPosition(const Vector3i& new_current_chunk_positionVec3i) {
		if (this->current_chunk_positionVec3i == new_current_chunk_positionVec3i) {
			return;
		}
		// this->last_chunk_positionVec3i = this->current_chunk_positionVec3i;
		this->current_chunk_positionVec3i = new_current_chunk_positionVec3i;
		this->currentChunkPositionChanged->emit(new_current_chunk_positionVec3i);
	}
	
	Vector3i FBlockWorld3D::getCurrentChunkPosition() const {
		return this->current_chunk_positionVec3i;
	}
	
	Ref<FSignal1> FBlockWorld3D::getCurrentChunkPositionChangedSignal() const {
		return this->currentChunkPositionChanged;
	}
	
	void FBlockWorld3D::_bind_methods() {
		ClassDB::bind_static_method(FBlockWorld3D::get_class_static(), D_METHOD("sayHello"), &FBlockWorld3D::sayHello);
		
		// chunk_sizeVec3i
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
			ClassDB::bind_method(D_METHOD("getChunkSizeChangedSignal"), &FBlockWorld3D::getChunkSizeChangedSignal);
			ClassDB::add_property(
				FBlockWorld3D::get_class_static(),
				PropertyInfo(
					Variant::OBJECT,
					"chunkSizeChanged",
					PROPERTY_HINT_NONE,
					"",
					PROPERTY_USAGE_DEFAULT,
					FSignal1::get_class_static()
				),
				"",
				"getChunkSizeChangedSignal"
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
			ClassDB::bind_method(
				D_METHOD("getLoadChunkSizeChangedSignal"),
				&FBlockWorld3D::getLoadChunkSizeChangedSignal
			);
			ClassDB::add_property(
				FBlockWorld3D::get_class_static(),
				PropertyInfo(
					Variant::OBJECT,
					"loadChunkSizeChanged",
					PROPERTY_HINT_NONE,
					"",
					PROPERTY_USAGE_DEFAULT,
					FSignal1::get_class_static()
				),
				"",
				"getLoadChunkSizeChangedSignal"
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
			
			// 信号 currentChunkPositionChanged
			ClassDB::bind_method(
				D_METHOD("getCurrentChunkPositionChangedSignal"),
				&FBlockWorld3D::getCurrentChunkPositionChangedSignal
			);
			ClassDB::add_property(
				FBlockWorld3D::get_class_static(),
				PropertyInfo(
					Variant::OBJECT,
					"currentChunkPositionChanged",
					PROPERTY_HINT_NONE,
					"",
					PROPERTY_USAGE_DEFAULT,
					FSignal1::get_class_static()
				),
				"",
				"getCurrentChunkPositionChangedSignal"
			);
		}
	}
}
