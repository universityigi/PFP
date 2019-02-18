object E5 {
    def somma(f:Int=>Int) = {
        def funzioneDaRestituire(a:Int,b:Int):Int= {
			if(a>b) 0
			else f(a)+funzioneDaRestituire(a+1,b)
		} 
		funzioneDaRestituire _
    }	
}
