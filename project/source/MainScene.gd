extends Node

func _ready() -> void:
	self.connectSignal()
	self.testSignalAndCallable()
	
	# FBlockWorld3D.sayHello()
	# var bw = FBlockWorld3D.new()
	# bw.chunk_sizeVec3i = Vector3i(5, 5, 5)
	# # print("bw.chunk_sizeVec3i == ", bw.chunk_sizeVec3i)
	# bw.chunkSizeChanged.connect(
	# 	func(new_size: Vector3i):
	# 		print("chunkSizeChanged(", "new_size == ", new_size, ")")
	# 		pass
	# )
	# bw.chunk_sizeVec3i = Vector3i(7, 7, 7)
	
	# self.add_child(bw)
	
	# print(FSignal.getSignalName())
	# print(FSignal.getSignalName())
	
	# var sgnl0 := FSignal0.new()
	# sgnl0.connectSignal(
	# 	func():
	# 		print("Hello FSignal0")
	# 		pass
	# )
	# sgnl0.emitSignal()
	
	# var sgnl1 := FSignal1.new()
	# sgnl1.connectSignal(
	# 	func(textStr: String):
	# 		print("textStr == ", textStr)
	# 		pass
	# )
	# sgnl1.emitSignal("Hello FSignal1")
	
	# var callable0 := FCallable0.make(
	# 	func():
	# 		print("Hello FCallable0")
	# 		pass
	# )
	
	# if callable0.isValid():
	# 	callable0.invoke()
	# 	pass
	
	# var cllbl0 := callable0.toCallable()
	# if cllbl0.is_valid():
	# 	cllbl0.call()
	# 	pass
	
	
	# var callable1 := FCallable1.make(
	# 	func(textStr: String):
	# 		print("textStr == ", textStr)
	# 		pass
	# )
	# var textStr := "Hello FCallable1"
	# if callable1.isValid():
	# 	callable1.invoke(textStr)
	# 	pass
	
	# var cllbl1 := callable1.toCallable()
	# if cllbl1.is_valid():
	# 	cllbl1.call(textStr)
	# 	pass
	
	pass

func connectSignal():
	# var f := FCallable1.make(
	# 	func(textStr: String):
	# 		print(textStr);
	# 		pass
	# )
	# self.said.connect(f)
	
	self.said.connect(
		FCallable1.make(
			(func(textStr: String):
				print(textStr);
				pass )
		)
	)
	# print("isConnected == ", self.said.isConnected(f))
	for s in self.said.get_signal_list():
		print(s["name"], self.said.get_signal_connection_list(s["name"]))
		pass
	pass

static var said := FSignal1.new()

func testSignalAndCallable() -> void:
	for s in self.said.get_signal_list():
		print(s["name"], self.said.get_signal_connection_list(s["name"]))
		pass
	
	self.said.emit("Hello static FSignal1! 哈哈哈")
	pass
