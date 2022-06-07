# vector<pair<string, int>> vals = {{"Deluxe Tuna Bitz", 0}, {"Bonito Bitz", 0}, {"Sashimi", 0}, {"Ritzy Bitz", 0}};

vals = [["Deluxe Tuna Bitz", 0], ["Bonito Bitz", 0], ["Sashimi", 0], ["Ritzy Bitz", 0]]

for t in range(int(input())):
    s = input()
    for i in range(len(vals)):
        if vals[i][0] == s:
            vals[i][1] += 1
            break

vals.sort(key=lambda x : x[1], reverse=True)

for i in vals:
    if i[1]:
        print(i[0], i[1])
