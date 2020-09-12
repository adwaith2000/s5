yin=0
y=0
x1=0
x2=0

x=[]
t=[0]*4
w=[0]*2
dw=[0]*2
f=[1]*4
b=0
count=1

#Loop to enter the values in table
for i in range(4):
	print('Enter row',i+1,' of x1,x2 and t')
	x1=int(input('x1:'))
	x2=int(input('x2:'))
	l=[x1,x2]
	x.append(l)
	t[i]=int(input('t:'))
#Input for threshold value and alpha
theta = float(input("Enter threshold value for activation funtion: "))
alpha = int(input("Enter the learning rate alpha: "))


#Each iteration of while loop is for one epoch
while True:
	print('\nEpoch ',count)
	print('\nx1\tx2\tb\tt\tyin\ty\tdel(w1)\tdel(w2)\tdel(b)\tw1\tw2\tb')
	#Each iteration of for loop is for a row
	for i in range(4):
		yin=x[i][0]*w[0]+x[i][1]*w[1]+b
		#Activation function
		if yin > theta:
			y=1
		elif yin >= -1*theta:
			y=0
		else:
			y=-1
			#Finding the weight changes
		if y!=t[i]:
			dw[0]=alpha*t[i]*x[i][0]
			dw[1]=alpha*t[i]*x[i][1]
			db=alpha*t[i]
			w[0]+=dw[0]
			w[1]+=dw[1]
			b+=db
			f[i]=1
		else:
			dw[0]=0
			dw[1]=0
			db=0
			f[i]=0
		print('\n',x[i][0],'\t',x[i][1],'\t',1,'\t',t[i],'\t',yin,'\t',y,'\t',dw[0],'\t',dw[1],'\t',db,'\t',w[0],'\t',w[1],'\t',b)
	count+=1
	#if all f is 0, then there are no weight change in that epoch
	if f[0]==0 and f[1]==0 and f[2]==0 and f[3]==0:
		break
print('Finished after ',count-1,' epochs')


