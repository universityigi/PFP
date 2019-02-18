object E3{
	def primo(x:Int):Boolean={
		if(x==1) true
		else if(x==2) true
		else List.range(2, x).forall(y=>(x%y!=0))	
	}
}
