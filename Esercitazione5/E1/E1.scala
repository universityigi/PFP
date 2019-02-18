// Scrivere un metodo scalarProd che, date due vettori rappresentati come
// sequenze di Double, ne calcola il prodotto scalare. Se i vettori
// hanno lunghezze diverse, limitare il prodotto scalare al range di
// indici validi comuni. Ad esempio: scalarProd(Seq(3,4), Seq(2,9,1)) ==
// 3*2 + 4*9 == 42

// _Suggerimento:_ usare i metodi delle collezioni

object E1 {
    def scalarProd(a:Seq[Double], b:Seq[Double]):Double = {
		if(a==Nil || b==Nil) 0.0
		else{
				def aux(i:Int):Double={
					if(a.size<b.size){
						if(i==a.size-1) a(i)*b(i)
						else{
							a(i)*b(i)+ aux(i+1)
						}
					}
					else if(a.size>b.size){
						if(i==b.size-1) a(i)*b(i)
						else{
							a(i)*b(i)+ aux(i+1)
						}
					}
					else{
						if(i==a.size-1) a(i)*b(i)
						else{
							a(i)*b(i)+ aux(i+1)
						}
					}
				}
				aux(0)
			}
			
		
	}
}
