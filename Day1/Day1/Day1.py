#file='small_test_input.txt'
file='input.txt'


with open(file) as f:
    lines = f.read().splitlines()
test_list = list(map(int, lines))

nr_of_increases = 0

for l1,l2 in zip(test_list[:-1], test_list[1:]):
    if l1 < l2: nr_of_increases += 1

print("PART1:" + str(nr_of_increases))

#https://adventofcode.com/2021/day/1#part2
nr_of_increases_part2 = 0
for l1,l2,l3,l4 in zip(test_list, test_list[1:], test_list[2:], test_list[3:]):
    # not necessary to compare l2,l3 same sum but whatever
    if sum([l1,l2,l3]) < sum([l4,l2,l3]): nr_of_increases_part2 += 1

print("PART2:" + str(nr_of_increases_part2))