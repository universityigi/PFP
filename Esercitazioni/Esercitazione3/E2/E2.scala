object E2{
	def myFor(ini: Unit)(cond : => Boolean)(inc : => Unit)( body : => Unit):Unit={
		if(cond){
			body
			inc
			myFor(ini)(cond)(inc)(body)
		}
		else{
			()
		}
	}
}
