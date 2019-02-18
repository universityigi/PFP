object E22Main extends App{
	val studenti = List(("Paola", 19), ("Luca", 23), ("Lucia", 21), ("Matteo",22), ("Francesca",23))
    val esami = List(("Paola","PFP"), ("Luca","SC"), ("Paola","DB"), ("Lucia","SC"), ("Matteo","LTW"), ("Lucia","PFP"), ("Francesca","SC"))
	val e = 22
	println(E22.query(studenti,esami,e)+"[Corretto: PFP]")
}
