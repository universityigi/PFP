object E8Main extends App{
	println(E8.isSorted(List(1,2,3))+"[Corretto:true]");
	println(E8.isSorted(List(1,3,2))+"[Corretto:false]");
	println(E8.isSorted(List(3,2,1))+"[Corretto:false]");
	println(E8.isSorted(List(45,89,100))+"[Corretto:true]");
	
	println("Ricorsiva");
	
	println(E8.isSortedRic(List(1,2,3))+"[Corretto:true]");
	println(E8.isSortedRic(List(1,3,2))+"[Corretto:false]");
	println(E8.isSortedRic(List(3,2,1))+"[Corretto:false]");
	println(E8.isSortedRic(List(45,89,100))+"[Corretto:true]");
	
	
	println("Iterativa");
	
	println(E8.isSortedIt(List(1,2,3))+"[Corretto:true]");
	println(E8.isSortedIt(List(1,3,2))+"[Corretto:false]");
	println(E8.isSortedIt(List(3,2,1))+"[Corretto:false]");
	println(E8.isSortedIt(List(45,89,100))+"[Corretto:true]");
	
}
