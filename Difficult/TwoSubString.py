


x = input();
ba = x.rfind("BA")
bar = x.find("BA")
ab = x.find("AB")
abr = x.rfind("AB")
if((abs(ab-ba)>=2 and ab!=-1 and ba!=-1) or (abs(ab-bar)>=2 and ab!=-1 and bar!=-1) or (abs(ba-abr)>=2 and ba!=-1 and abr!=-1) or (abs(abr-bar)>=2) and abr!=-1 and bar!=-1):
    print("YES")

else:
    print("NO")

print(ba,bar,ab,abr)