object E19Main extends App{
	val  studenti = List(("Paola", 21), ("Luca", 22), ("Lucia", 21), ("Matteo",22))
	val esami = List(("Paola","PFP"), ("Luca","SC"), ("Paola","DB"), ("Lucia","LTW"), ("Matteo","SO"), ("Lucia","PFP"))
	println(E19.query(studenti,esami)+"[Corretto: 21]")
}
