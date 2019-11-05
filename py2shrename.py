import os
from shutil import copyfile
lab_num = input("What lab number? ")
rootdir = 'C:/Users/Ashpan/Drive/Current/School/Second Year/COMPENG 2SH4/Labs/Lab' + lab_num

for subdir, dirs, files in os.walk(rootdir):
	for file in files:
		if(file[0] == "Q" and file[-1] == 'c'):
			# print(file)
			q_num = int(file.split('Q')[1].split('.')[0])
			# int(file.split('Q')[1].split('.')[0])
			out_txt_file_name = 'raskar_ashpan_raskara_lab'+lab_num+'_L02_question'+str(q_num)+'.txt'
			out_c_file_name = 'raskar_ashpan_raskara_lab'+lab_num+'_L02_question'+str(q_num)+'.c'
			print("Writing file:", out_txt_file_name, "&", out_c_file_name)
			copyfile(os.path.join(subdir, file), rootdir+'/files_to_submit/'+out_txt_file_name)
			copyfile(os.path.join(subdir, file), rootdir+'/files_to_submit/'+out_c_file_name)