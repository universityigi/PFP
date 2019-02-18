object E7Main extends App{
	println(E7.findIndices(List(1,2,3,4,5),4)+ " [Corretto : List(3)]");
	println(E7.findIndices(List(1,4,3,4,4),4)+ " [Corretto : List(1,3,4)]");
	println(E7.findIndices(List(4,3,3,3,4),4)+ " [Corretto : List(0,4)]");
	
}
