object Prof {
    def profila[T](body: =>T):(T,Long) = {
        val start = System.nanoTime
        val v = body
        val t = System.nanoTime - start
        (v,t)
    }
}
