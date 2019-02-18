object E20{
	def longestSublist[T](p:T=>Boolean)(l:List[T])={
		def aux(tmp:List[T],curr:List[T],sub:List[T], i:Int):List[T]={
			if(i==tmp.length-1) sub
			else if(p(tmp(i))){
				aux(tmp,curr:+tmp(i),sub,i+1)
			}
			else{
					if(curr.length>sub.length) aux(tmp,List(),curr,i+1)
					else aux(tmp,List(),sub,i+1)
			}
		}
		aux(l,List(),List(),0)
	}
}
