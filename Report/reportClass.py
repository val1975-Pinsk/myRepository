class Message:
    def __init__(self):
        self.programm_completed = "Программа завершает работу..."
        self.list_is_empty = "Нет файлов для отчёта..."
    
    def completed(self):
        print(self.programm_completed)
    
    def list_empty(self):
        print(self.list_is_empty)


class Passenger:
	def __init__(self):
		self.recerved = 0
		self.fulfilled = False
		self.remark = "undefined"
	
	def display(self):
		print(f"recerved: {self.recerved}\nfulfilled: {self.fulfilled}\nremark: {self.remark}")
	
	
	def getFullyPriceCount(self):
		count = 0
		count += self.getDiscountedCount()
		count += self.getHalfTheCostCount()
		return self.recerved - count		
	
	def getHalfTheCostCount(self):
		words = ["17р", "Ивацевич", "Ивацевичи", "до ивац"]
		remark = self.remark
		count = 0
		for unit in words:
			if unit in remark:
				return self.recerved
		return count
		
	def getDiscountedCount(self):
		words = ["дк", "Д.К.", "Д к ", "Дк"]
		remark = self.remark
		count = 0
		found = 0
		while(found != -1):
			for unit in words:
				found = remark.find(unit)
				if found != -1: 
					count += 1
					remark = remark[found + 1:]
					break
		return count
					
	def getPayment(self):
		count = 0
		response = {
			"discounted":0,
			"fullyPrice":0,
			"halfTheCost":0
			}
		if not self.fulfilled: return response
		response["discounted"] = self.getDiscountedCount()
		if self.recerved - response["discounted"] == 0:
			return response
		response["halfTheCost"] = self.getHalfTheCostCount()
		if self.recerved - (response["discounted"]+response["halfTheCost"]) == 0:
			return response
		response["fullyPrice"] = self.getFullyPriceCount()
		return response
	
	
class Report:
	def __init__(self):
		self.body = []


class directReport:
	def __init__(self, direction, date, time):
		self.direction = direction
		self.date = date
		self.time = time
		self.auto = "undefined"
		self.occupied = 0
		self.freely = 0
		self.passengers = []
		self.fullyPrice = Payment("Полная стоимость", 35)
		self.discounted = Payment("По дисконту", 30)
		self.halfTheCost = Payment("Пол стоимости", 17)
	
	def display(self):
		print("\n")
		print(f"Направление:{self.direction}\nДата: {self.date}\nВремя отправления: {self.time}")
		print(f"Занято мест: {self.occupied}\nСвободных мест: {self.freely}\nАвтомобиль: {self.auto}")
		print("\n")
		for unit in self.passengers:
			pay = unit.getPayment()
			self.fullyPrice.addCount(pay["fullyPrice"])
			self.discounted.addCount(pay["discounted"])
			self.halfTheCost.addCount(pay["halfTheCost"])
		self.fullyPrice.display()
		self.discounted.display()
		self.halfTheCost.display()
		print("Итого: ",self.fullyPrice.getTotal() + self.discounted.getTotal() + self.halfTheCost.getTotal())
		print("===============================================")

	def setSubHeader(self, string):
		string = string[16:]
		words = string.split(", ")
		self.occupied = int(words[0][:len(words[0])-2])
		self.freely = int(words[1][:len(words[0])-12])
		self.auto = words[2]
	
		
class Payment:
	def __init__(self, name, value):
		self.name = name
		self.value = value
		self.count = 0
		
	def addCount(self, value):
		self.count += value

	def display(self):
		print(f"{self.name}: {self.count}x{self.value} {self.count*self.value}")
		
	def getTotal(self):
		return self.value * self.count

