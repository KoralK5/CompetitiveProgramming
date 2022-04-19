#--------------------------------------------------------
n = 12460877288564028727335358383983114542341731051548022154034572491197792306193631973075953054981914244972901364570026538015436620745240063350590274031644056900432709397316305570897203361086754488845958051126465417658968484281328161365661685893889073543245641885219392835341114971676623000455528550121577059201133263120601958976737603233507194269119045288269691908582132306697727786774654514376870525616655205178159918358857865468390016722443872424371236141894314463542566640524517054586357683087662030214815870012212922169583417159962678976416791080548477646303068353009493394710675105136107796547980740025506715311541
#--------------------------------------------------------

# from Crypto.Util.number import long_to_bytes
from gmpy2 import gcd

factorial = 1
for i in range(1, 100000):
    factorial *= i
 
p = gcd(pow(2, factorial, n) - 1, n)
q = n//p

print(p, q)

# p = 99755582215898641407852705728849845011216465185285211890507480631690828127706976150193361900607547572612649004926900810814622928574610545242732025536653312012118816651110903126840980322976744546241025457578454651121668690556783678825279039346489911822502647155696586387159134782652895389723477462451243655239
# q = 145188107204395996941237224511021728827449781357154531339825069878361330960402058326626961666006203200118414609080899168979077514608109257635499315648089844975963420428126473405468291778331429276352521506412236447510500004803301358005971579603665229996826267172950505836678077264366200199161972745420872759627