import re
with open("platformio.ini", 'r', encoding="utf-8") as file_in:
    text = file_in.read()
deff = re.findall(r"default_envs = (.*)", text)
dic = {}
#dic["default_envs"] = deff[0].split(", ")
dic["include"] = []
text = re.sub(r" ", r" ", text)
deff = re.findall(r"\[\s*env:(.*?)].*?lib_deps *= *(.*?)\n[^\s].*?", text, flags=re.DOTALL)
dic["include"] = {}
for d in deff:
    dic["include"][d[0]] = re.findall(r"\n\s+([^l\s][^i\s][^b\s][^\s]+)", d[1])
for d in dic["include"]:
    for i in range(len(dic["include"][d])):
        temp = dic["include"][d][i]
        splitted = re.split("@\^|#", temp)
        try:
            dic["include"][d][i] = {}
            dic["include"][d][i][splitted[0]] = splitted[1]
        except:
            dic["include"][d][i] = splitted[0]
print("matrix: ", dic)