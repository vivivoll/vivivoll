fun validatePassword(password: String): Boolean {
    for (c in password) {
        if (password.length < 8) return false
    }

    fun hasDigit(): Boolean {
        return password.any { it.isDigit() }
    }

    fun hasUppercase(): Boolean {
        return password.any { it.isUpperCase() }
    }
    return hasDigit() && hasUppercase()
}

fun main(){
    print(validatePassword("324234324987kjsdfKJH#"))
}

