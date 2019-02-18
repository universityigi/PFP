object C1Main extends App {
    val t:Tree = T(T(E(),5,T(E(),7,E())),10,T(E(),15,T(E(),17,E())))

    val p1:(Int,Int,Int) = t.minMax            /*    10     */
    println(p1+" [corretto: (5,17,5)]")        /*   /  \    */
                                               /*  5   15   */
    val p2:(Int,Int,Int) = T(t,25,E()).minMax  /*   \    \  */
    println(p2+" [corretto: (5,25,4)]")        /*    7   17 */

    val p3:(Int,Int,Int) = T(E(),9,E()).minMax
    println(p3+" [corretto: (9,9,2)]")
}
