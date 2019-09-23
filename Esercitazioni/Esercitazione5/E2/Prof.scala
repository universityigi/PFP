object Prof {
    def profila[T](body: =>T):(T,Double) = {
        val start = System.nanoTime
        val v = body                        // il body passato come parametro per nome viene valutato qui
        val t = System.nanoTime - start
        (v,t*1E-9)
    }
}
