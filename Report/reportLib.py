from reportClass import *

def convertDate(date):
	month = ["Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"]
	subDate = date.split("-")
	return subDate[2] + " " + month[int(subDate[1]) - 1] + " " + subDate[0]
	
	
def newDirReport(string):
	#string = string[16:len(string)-5]
	string = string[16:]
	words = string.split(", ")
	return directReport(words[2], convertDate(words[0]), words[1])


def sringIsHeader(string):
	if "Пинск" in string:
		return True
	else: return False


def stringIsSubHeader(string):
	if "свободно" in string:
		return True
	else: return False
	

def stringIsRecervedCount(string):
	if "width=\"25px\"" in string :
		return True
	else: return False


def getRecervCntValFromStr(string):
	return int(string[17:])


def getRemarkFromString(string):
	return string[16:]


def stringIsRemark(string):
	if "<td colspan=\"5\">" in string:
		if not "</tr>" in string: return True
		elif not "Пинск" in string: return True
		elif not "свободно" in string: return True
	else: return False


def stringIsFulfilledStatus(string):
	if "selected=\"\">" in string:
		return True
	else: return False


def getFulfilledStatus(string):
	if "Поехал" in string:
		return True
	else: return False

		
def isGetString(string):
	words = ["Пинск", "свободно", "д.к.", "дк", "Дк", "Д.К.", "безнал", "б/н", "17р", "ребенок", "width=\"25px\"", "selected=\"\">Поехал", "<td colspan=\"5\">"]
	for word in words:
		if word in string and not "</tr>" in string: return True
	return False

