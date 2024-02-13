hex_arr=['80','C0','E0','F0','F8','FC','FE','FF']
for j in range(14):
    for i in range(8):
        with open('data.txt','a') as f:
            f.write(f'arr_red[{j}]=0x{hex_arr[i]};\n')
            f.write("rgb_clm();\n")
            f.write("delay(25);\n")
            
hex_arr2=['FE','FC','F8','F0','E0','C0','80','0']
hex_arr3=['1','3','7','F','1F','3F','7F','FF']
k=14
while k>0:
    for n in range(8):
        with open('data.txt','a') as f:
            f.write(f'arr_red[{k}]=0x{hex_arr2[n]};\n')
            f.write(f'arr_green[{k}]=0x{hex_arr3[n]};\n')
            f.write("rgb_clm();\n")
            f.write("delay(25);\n")
            
    k=k-1
    