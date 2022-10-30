from time import sleep
import os, serial

if __name__ == '__main__':
	
	
	outPath = "pytoc"
	inPath = "ctopy"
	try:
		try:
			os.mkfifo(outPath, 0o600)
			print(f"Pipe named '{outPath}' is created successfully.\n")
		except:
			print(f"Pipe '{outPath}' already exists\n" )
		try:
			os.mkfifo(inPath, 0o600)
			print(f"Pipe named '{inPath}' is created successfully.\n")
		except:
			print(f"Pipe '{inPath}' already exists\n" )
		sleep(0.01)
		out = os.open(outPath, os.O_WRONLY)
		infile = os.open(inPath, os.O_RDONLY)
	except:
		try:
			os.unlink(outPath)
			os.unlink(inPath)
		except:
			print("Files already deleted\n")
		exit()
	#os.write(out, b'hello\n')
	#os.close(out)
	
	while True:
		try:
			os.write(out, bytes("0.0,0.0,0.0\n","utf-8"))
			print(os.read(infile, 512).decode("utf-8"))
		except:
			try:
				os.close(out)
				os.close(infile)
				os.unlink(outPath)
				os.unlink(inPath)
			except:
				print("Files already deleted\n")
			exit()