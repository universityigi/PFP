object C2Main extends App {
    val p1:Int = C2.countSpaces("hi there!")
    println(p1+" [corretto: 1]")
    val p2:Int = C2.countSpaces(" one two three ")
    println(p2+" [corretto: 4]")
    val p3:Int = C2.countSpaces("zero")
    println(p3+" [corretto: 0]")
}
