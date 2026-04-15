
with open("day4_input.txt","r") as f:
  
  inp = f.readlines()
  sum = 0
  games = []
  for row in inp:
    matching = 0
    winning, cards = [v.split() for v in row.split(":")[1].split("|")]
    
    winning = set(map(int,winning))
    cards = list(map(int,cards))

    for c in cards:
      if c in winning:
        matching += 1
    
    if matching > 0:
      sum += 1 << (matching - 1)
  
  print(sum)

