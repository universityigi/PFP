object E13Main extends App{
	println(E13.equal(List(1,2,3,4),List(1,2,3,4))+"[Corretto: true]")
	println(E13.equal(List(1,2,3,4),List(1,2,3))+"[Corretto: false]")
}
