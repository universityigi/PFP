object E34{
	def search[T <%Ordered[T]](v:Vector[T], e:T):Boolean={
		def aux(v:Vector[T],e:T,start:Int,end:Int):Boolean={
			if(start>end || start <0 || end<0 ) false
			else{
				var mid=(start+end)/2
				if(e<v(mid)) aux(v,e,start,mid-1)
				else if(e>v(mid)) aux(v,e,mid+1,end)
				else true
			}
		}
		aux(v,e,0,v.length-1)
	}
}
