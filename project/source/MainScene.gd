extends Node

@onready var world := %FBlockWorld3D as FBlockWorld3D

func _ready() -> void:
	self.world.chunkSizeChanged.emit(Vector3i(2, 2, 2))
	
	self.world.currentChunkPositionChanged.connect(
		FSlot1.makeFromCallable(
			(func(v):
				print("new_current_chunk_positionVec3i == ", v)
				pass )
		)
	)
	
	world.current_chunk_positionVec3i = Vector3i(1, 1, 4)
	pass
