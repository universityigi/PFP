object E6Main extends App{
	println(E6.equalInRange(x=>x*x,x=>x+1,2,3) + " [Corretto: false]");
	println(E6.equalInRange(x=>x*x,x=>x*x,2,3) + " [Corretto: true]");
}
