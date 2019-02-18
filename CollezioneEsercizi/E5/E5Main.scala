object E5Main extends App{
	val valore=E5.concatena(x=>x-2.0,x=>x+x,x=>x-1.0,5.0,20.0);
	println(valore(4.0));
}
