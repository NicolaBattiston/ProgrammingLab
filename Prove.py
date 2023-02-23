import math

class Funzione:
    
    def eval(self, x): 
        pass

    def calcola_integrale(self, a, b, m):
        h = (b - a)/m
        integrale = 0
        for i in range(m):
            integrale += self.eval(a + i * h)

        return h * integrale

class Function1(Funzione):

    def eval(self, x):
        return x * (x - 2)

    def calcola_integrale(self, a, b, m):
        return super().calcola_integrale(a, b, m)

class Function2(Funzione):
        
    def eval(self, x):
        return pow(math.e, 2 * x)
    
    def calcola_integrale(self, a, b, m):
        return super().calcola_integrale(a, b, m)

class Function3(Funzione):

    def eval(self, x):
        return x/(1 + x * x)

    def calcola_integrale(self, a, b, m):
        return super().calcola_integrale(a, b, m)


f = Function2()
print(f.calcola_integrale(0, 1, 1000))