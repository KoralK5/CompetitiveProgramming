#----------------------------------------------
p = 131052114360702045124590183255994762656619199735249535595584576189433831217063554460411328124131583182550346560926925160498149379216442318939260253148179776131274669358880311256595170467109949361229085696186281524216960337055092798404104419557497546926615552390467209477035904656450289254897714380316674157667
q = 95083374650997701825495702975538193996336577136000931396919403621939890232520511874814758757200119975398319285588359163845575443474809874504800714053625580066093081882534983335154185505390296378339787005820402189374454050557796448956331528203487300285343610236214366467194705172455767452698268943235530255623
#----------------------------------------------

from Crypto.Util.number import isPrime

Primes = [prime for prime in range(200000) if isPrime(prime)]

p_phi_factor = [prime for prime in Primes if not (p - 1) % prime]
q_phi_factor = [prime for prime in Primes if not (q - 1) % prime]

p_phi_Euler, q_phi_Euler = 1, 1

for P in p_phi_factor:
    p_phi_Euler *= P
for Q in q_phi_factor:
    q_phi_Euler *= Q

assert p - 1 == p_phi_Euler and q - 1 == q_phi_Euler

print(p_phi_factor)
print(q_phi_factor)

# p_phi_factor = [2, 20611, 30971, 32987, 33107, 33151, 33289, 33457, 33679, 34123, 34897, 35023, 35671, 36151, 37049, 37139, 39313, 39541, 40087, 40237, 40787, 41257, 41333, 41351, 41999, 42083, 42239, 43177, 43627, 44789, 45179, 46381, 46619, 46861, 47111, 48883, 49157, 50359, 50527, 50773, 50777, 50857, 50951, 51307, 51361, 51383, 51593, 52889, 52967, 53047, 54037, 54673, 56479, 56569, 57301, 58963, 59651, 61027, 61441, 61507, 62347, 62929, 62969, 63587, 64171, 64621, 65497]
# q_phi_factor = [2, 35227, 44617, 66343, 67559, 67651, 67759, 67801, 68239, 71633, 73421, 74159, 74821, 77347, 78977, 79813, 82129, 82301, 82787, 84047, 87181, 87959, 88117, 88241, 89137, 89203, 90583, 91873, 92623, 93557, 93601, 94253, 94649, 95369, 97813, 97849, 98017, 99431, 100459, 101377, 101929, 103217, 103549, 106591, 106979, 111697, 112061, 112253, 112397, 114013, 116107, 116881, 117617, 118739, 119159, 119503, 120847, 121843, 121909, 124471, 126127, 126241, 130729]
# phi_factor = 
