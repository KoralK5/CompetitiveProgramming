from Crypto.Util.number import getPrime, isPrime
from random import randint
from secret import flag

TARGET = 10
MAX = 10

N = 512
key = (1406745126430834211368439581427586552128513839368079375330777422350279010233921137101818450726988691168057262732590043941337227908029133975607524811099227565909552352445605144707215821110896806246996893529617429480181978275309159546378644943189838293023417359936637918158730858640390260572101852546621557080006885599631146311721451331859138297506121887787830325952441708634953348555768257126236741528355472633852552203653607703853172417814273926846522222899266871676816812119260729815492523759602496987964348605786989031714342204638679831604162373164470163182293721312107165701819445214483716237099450544614974539548198879711577259046399009099059074121716448365481422270130752107511758789011194744135899404901773436027732204863189984525085762750748955124164661344679706185466081110635241274044828067943979807155807734417834245987985856846297320515363064556415983787996822585199472909391214500400444166487063524093463852220417, 251866275144832804117904650340467630327307547943294624162209655756270474616461710900607819308591438275651230688003685366068819577019929011011295545508703008591857050628219284845515392790910741084753577414622807247270754762645744764876490428295621665384055415418169341078308493172308733595420124097494677194540909701109028540473029950111640772713847356903605994653403284524882942147938696272647334727153364783235667527051798321928751045255353667018547182541937144110088746969503093966522873124410190902718072885783072296015671501983300880465302176711365804392810324971758586422217953992618331675795569781401468259934658957480197964961765768947303650692905269349733121910054679242628384198257734418028748045690138687732945938842986119237008185398476030495662774786539266858488404701340179841538824890075144003341024405656120021006077527899583999969175371696313982716472581754564152173971431839109213808103672177137270194321293, 64483553273707701082069119474864761484140198779195205191703146328739249301059109834572879488427582977522752237968398074099234477007409347567853933386826721350256480514485971352082469112757173139860892967355208302212485705530355135722912097053805880953171949024722427667555620087032862452781768079296554995158815516828876567603012394267057043832426850055913400184738634011058897940770332793740052856097541437613719435073303700983399040651216693590347070762778435854836393343091049891939791695541625011428952697702074527974632446661775684242393743906007656648372656188229156821538851404002436023678629327262167916731577511021273973949460144971677960025602180358558582819051788340354961452773935908279347186712893939560790345719422007545257161759661122195919915290844338488580083220257144546652115017067417618577246400854456902784137631613746604771821308217617307667192441237878580298928009539089335672831178451077104170896368, 563319099256293902032388749750654192984464733635672492304301190365077376009372065959315472009535709705316690524690985053255280177975172547678109541453117178384086871012637820496164079588145248956284229006337403549473552689324499153965206786653940143576427832191594039413565022201664029290442473764023702613866104286160734416775865036413816060437076891210506338740457628013484721477061815104356120378702637640673855794011483177921108210990626777852511385576013825)


menu = """
Options:
1 - Guess number.
2 - Send ciphertext.
> """

class MyCrypt:
    def __init__(self, import_key=None):
        if import_key:
            (self.n, self.g, self.h, self.x) = import_key
        else:
            p = 1
            q = 1
            bd = pow(2,N)
            while not isPrime(p):
                p1 = getPrime(N)
                p2 = getPrime(N)
                p = bd * p1 * p2 + 1
            while not isPrime(q):
                q1 = getPrime(N)
                q2 = getPrime(N)
                q = bd * q1 * q2 + 1

            self.n = p * q

            self.g = 1
            while pow(self.g, bd//2, self.n) == 1:
                self.g = pow(randint(2, self.n-2), p1*p2*q1*q2, self.n)
            assert pow(self.g, bd, self.n) == 1

            self.h = 1
            while pow(self.h, p1, self.n) == 1 or pow(self.h, q1, self.n) == 1:
                self.h = pow(randint(2, self.n-2), bd*p2*q2, self.n)
            assert pow(self.h, p1*q1, self.n) == 1

            self.x = (p1*q1*pow(p1*q1, -1, bd)) % self.n

        self.lookup = [pow(self.g, -(2**i), self.n) for i in range(N)]

    def encrypt(self, m, exp=False):
        if exp:
            m = pow(2, m)
        r = randint(1, pow(2,N) - 1)
        return (pow(self.g, m, self.n) * pow(self.h, r, self.n)) % self.n

    def decrypt(self, c):
        a = pow(c, self.x, self.n)
        if a == c: return -1
        x = 0
        e = 1
        for i in range(N):
            if pow(a, pow(2,N-i-1), self.n) != 1:
                x += e
                a = (a * self.lookup[i]) % self.n
            e *= 2
        return x
    
    def print_key(self):
        print((N, self.n, self.g, self.h, self.x))

def new_num(C):
    m = randint(1,N-1)
    ct = C.encrypt(m,exp=True)
    print(f"{ct = }")
    return m

def main():
    count = 0
    lookups = 0
    # C = MyCrypt(N)
    C = MyCrypt(key)

    print(f"{C.n = }\n{C.g = }")
    m = new_num(C)

    while True:
        print(menu, end="")
        op = input()

        if op == "1":
            print("What number did i encrypt?\n> ", end="")
            n = input()
            if int(n) == m:
                count += 1
                if count == TARGET:
                    print(f"Correct, here is your flag: {flag}")
                    break
                else:
                    print("Correct, onto the next one.")
                    lookups = 0
            else:
                print("Wrong, time to get a new number.")

            m = new_num(C)
        elif op == "2":
            if lookups == MAX:
                print("You've had enough, do something else for a change.")
                continue
            else:
                print("Send me something you want me to decrypt.\n> ", end="")
                ct = int(input())
                pt = C.decrypt(ct)
                if pt == -1:
                    print("Thats not encrypted, i didn't need the key at all. Try again.")
                    continue

                n = bin(pt).count("1")
                if n > 256:
                    print("Thats one fat number.")
                else:
                    print("Eh, could be bigger.")
                lookups += 1

        else:
            print("Invalid option, exiting...")
            break



C = MyCrypt(key)
main()