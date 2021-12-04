
#file='input_small.txt'
file='input.txt'

with open(file) as f:
    lines = f.read().splitlines()

# read input
chosen_numbers = list(map(int, lines[0].split(",")))

#test_list = list(map(int, lines))

bingo_fields = []
bingo_single = []

for x in lines[2:]:
    # next array
    if x == "":
        bingo_fields.append(bingo_single)
        bingo_single = []
        continue

    #parse in array
    data = list(filter(lambda x : len(x) > 0 , x.split(" ")))
    entry = list(map(int, data))
    bingo_single.append(entry)
    pass

if len(bingo_single) > 0:
    bingo_fields.append(bingo_single)

#for x in bingo_fields:
#    print(x)

bingo_row = -1
def CheckBingo(field):
    # check bingo x
    for entry in field:
        if all(x==None for x in entry):
            return True
                
    # check bingo y
    for x in range(len(field[0])):
        found = True
        for y in range(len(field)):
            if field[y][x] == None:
                continue
            else:
                found = False
                break
        
        if found == True:
            return True
    
    return False

first_win = False
first_chosen = -1;
first_field = None

last_win = False
last_chosen = -1;
last_field = None

list_finished = list([1] * len(bingo_fields))

for chosen in chosen_numbers:

    # replace all apperances with 0
    for i in range(len(bingo_fields)):
        # replace all apperances with 0
        if(list_finished[i] == 0):
            continue

        for j in range(len(bingo_fields[i])):
            bingo_fields[i][j] = list(map(lambda x: None if x == chosen else x, bingo_fields[i][j]))
        
        if chosen == 13:
            print("finished: " + str(chosen))
            pass
        if CheckBingo(bingo_fields[i]):
            list_finished[i] = 0
            print("finished: " + str(i))

        if list_finished[i] == 0 and first_win == False:   
            first_win = True
            first_field = list(bingo_fields[i])
            first_chosen = chosen
            #print(first_field)

        if sum(list_finished) == 0:
            last_win = True
            last_field = list(bingo_fields[i])
            last_chosen = chosen
            print("last: " + str(i))

    pass

print("Winner Part1: " + str(first_chosen))
print(first_field)

bingo_sum = 0
for entry in first_field:
    bingo_sum += sum(list(map(lambda x: 0 if x == None else x, entry)))

print(bingo_sum * first_chosen)

print("Winner Part2: " + str(last_chosen))
print(last_field)

bingo_sum = 0
for entry in last_field:
    bingo_sum += sum(list(map(lambda x: 0 if x == None else x, entry)))
print(bingo_sum)

print(bingo_sum * last_chosen)

