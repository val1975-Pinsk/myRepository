from reportClass import *
from reportLib import *
	
report = Report()
message = Message()

def getReportData():
	while(True):
		reportDataFile = input("Название файла отчёта: ")
		try:
			with open("./" + reportDataFile, encoding = "utf8") as file:
				data = file.readlines()
				reportData = []
				for string in data:
					if isGetString(string):
						string = string.strip()
						string = string[:len(string)-5]
						reportData.append(string)
				return reportData
		except FileNotFoundError:
			answer = input("Ошибка. Попробовать ещё раз (y/n)? ")
			if answer == "n" or answer == "н":
				return "finish"
				

'''
	Основной цикл программы.
'''
while(True):
	filesInDir = getFilesInDir()
	if len(filesInDir) == 0:
		message.list_empty()
		break
	for unit in filesInDir:
		print(unit)
	reportData = getReportData()
	if reportData == "finish":
		message.completed()
		break
	else:
		#	Составление отчёта.
		report = []
		for string in reportData:
		#	Определение содержания строки
			if sringIsHeader(string):
			#	Заголовочная строка.
				dirReport = newDirReport(string)
				report.append(dirReport)
			elif stringIsSubHeader(string):
			#	Вторая часть заголовка.
				dirReport.setSubHeader(string)
			elif stringIsRecervedCount(string):
			#	Количество заказаных мест.
				passenger = Passenger()
				passenger.recerved = getRecervCntValFromStr(string)
			elif stringIsFulfilledStatus(string):
			#	Статус заказа.
				passenger.fulfilled = getFulfilledStatus(string)
			elif stringIsRemark(string):
			#	Пояснения к заказу.
				passenger.remark = getRemarkFromString(string)
				dirReport.passengers.append(passenger)
		for report_ in report:
			report_.display()
		input("Составить ещё отчёт?(д/н) ")
		break
