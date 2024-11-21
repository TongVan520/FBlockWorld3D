extends Node

func _ready() -> void:
	FBlockWorld3D.sayHello()
	var bw = FBlockWorld3D.new()
	bw.chunk_sizeVec3i = Vector3i(5, 5, 5)
	# print("bw.chunk_sizeVec3i == ", bw.chunk_sizeVec3i)
	bw.chunkSizeChanged.connect(
		func(new_size: Vector3i):
			print("chunkSizeChanged(", "new_size == ", new_size, ")")
			pass
	)
	bw.chunk_sizeVec3i = Vector3i(7, 7, 7)
	
	self.add_child(bw)
	
	print(FSignal.getSignalName())
	print(FSignal.getSignalName())
	
	var sgnl0 := FSignal0.new()
	sgnl0.connectSignal(
		func():
			print("Hello FSignal0")
			pass
	)
	sgnl0.emitSignal()
	
	var sgnl1 := FSignal1.new()
	sgnl1.connectSignal(
		func(textStr: String):
			print("textStr == ", textStr)
			pass
	)
	sgnl1.emitSignal("Hello FSignal1")
	pass
