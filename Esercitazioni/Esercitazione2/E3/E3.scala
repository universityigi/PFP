object E3{
	def maxPrefisso(l:List[Int],x:Int):Int ={
		def aux(valore:Int,tmp:List[Int],i:Int):Int={
			if(valore>x) 0
			else 1+aux(valore+tmp(i+1),tmp,i+1)
		}
		aux(l(0),l,0)
	}
}
