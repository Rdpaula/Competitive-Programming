import datetime  as da

ad = da.date(2018,10,27);

li = []
n = int(raw_input())
for i in range(0,n):
	name,a = (raw_input().split(" "))
	a,b = map(int,a.split('-'))
	li.append(da.date(2018,a,b))
li.sort()
maior=da.timedelta(0)
dif=da.timedelta(0)
ans = da.date(2018,10,20)
for i in range(0,len(li)-1):
	# print li[i+1]
	lact = da.date(li[i + 1].year, li[i + 1].month,li[i + 1].day) - da.timedelta(1)
	# print lact
	# print lact-li[i]
	lactconf =  da.date(li[i + 1].year, li[i + 1].month,li[i + 1].day) - da.timedelta(1)
	if lact<ad:
		lactconf = da.date(li[i + 1].year+1, li[i + 1].month,li[i + 1].day) - da.timedelta(1)
	if lact-li[i]>maior:
		ans = lact
		maior = lact-li[i]
		dif = lactconf-ad
	elif lact-li[i] == maior and ((lactconf - ad < dif and lactconf - ad !=da.time(0)) or dif == da.timedelta(0)):
		ans = lact
		dif = lactconf-ad
	# print maior
lact = da.date(li[0].year+1,li[0].month,li[0].day) - da.timedelta(1)
# print dif
lactconf =  da.date(li[0].year, li[0].month,li[0].day) - da.timedelta(1)
if lactconf<ad:
	lactconf = da.date(li[0].year+1, li[0].month,li[0].day) - da.timedelta(1)
# print lactconf
# print lact-li[len(li)-1]
if lact-li[len(li)-1] > maior:
	ans = lact
elif lact-li[len(li)-1]==maior and ((lactconf - ad < dif and lactconf - ad!=da.time(0)) or dif == da.timedelta(0)):
	ans = lact
amais=""
amais2=""
if(ans.month<10):
	amais="0"
if(ans.day<10):
	amais2="0"
print "{}{}-{}{}".format(amais,ans.month,amais2,ans.day)
