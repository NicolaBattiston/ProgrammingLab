from datetime import date

# Classe per creare eccezioni per il mio programma(adattatate da Exception)
class ExamException(Exception):
    pass

class CSVTimeSeriesFile():
    # Inizializzatore parametro: file name
    def __init__(self, name=None):
        self.name = name

    def get_data(self):
        my_reader_file = self.open_file()
        data_file = self.read_file(my_reader_file)
        data_file = self.analize_data(data_file)
        return self.check_order_duplicates(data_file)

    def open_file(self):
        # raise: file impossibile da aprire o inesistente
        try:
            open_file = open(self.name)
        except:
            raise ExamException("Can't open this File or this File not Exist")

        return open_file

    def read_file(self, my_reader_file):
        # raise: file impossibile da leggere
        try:
            data_file = my_reader_file.read()
        except:
            raise ExamException("Can't read this File")
        return data_file.split("\n")

    def analize_data(self, rows_data):
        result = []

        this_year = date.today().year
        this_month = date.today().month

        for item in rows_data:
            row_data = item.split(",")

            # considero solo le linee con almeno 2 elementi e che nel primo contengono il "-" (altrimenti sono dati non conformi)
            if len(row_data) >= 2 and ("-" in row_data[0]):
                valid_row = True

                row_date = row_data[0].split("-")

                try:
                    row_year = int(row_date[0])
                    row_month = int(row_date[1])
                    n_passeggeri = int(row_data[1])

                    # Aerei inesistenti prima del 1900
                    if row_year < 1900:
                        valid_row = False

                    # Aerei inesistenti prima del 1900
                    if row_month < 1 or row_month > 12:
                        valid_row = False

                    # Anno o mese maggiore della data corrente  
                    if row_year > this_year:
                        valid_row = False
                    elif row_year == this_year and row_month > this_month:
                        valid_row = False

                    # Numero passeggeri deve essere positivo
                    if n_passeggeri < 0:
                        valid_row = False

                except:
                    valid_row = False

                # I dati esistono siccome valid_row = True
                if valid_row == True:
                    row = [row_data[0], n_passeggeri]
                    result.append(row)

        return result

    def check_order_duplicates(self, data_list):
        if not (len(data_list) < 2):
            date = data_list[0][0]

            #Controllo che ogni data sia maggiore della successiva
            for item in data_list[1:]:
                if item[0] < date:
                    raise ExamException("Dates are not ordered")
                elif item[0] == date:
                    raise ExamException("There are duplicates in Dates")
                date = item[0]

        return data_list
    
def detect_similar_monthly_variations(time_series, years):
    #Controllo che gli anni siano Interi e Positivi
    for item in years:
        if not isinstance(item, int):
            raise ExamException("Years List is not correct")
        if item < 0:
            raise ExamException("Years List is not correct")
        
        #Controllo se gli anni sono presenti nel File
        presente = False
        for item2 in time_series:
            if int(item2[0].split("-")[0]) == item:
                presente = True
                break

        if not presente:
            raise ExamException("Selected Date is not found in the File")

    #Controllo che gli anni si susseguano
    if not years[0] + 1 == years[1]:
        raise ExamException("Years List is not correct")

    #Controllo ulteriore visto che i dati potrebbero non provenire dalla funzione get_data()
    time_series = CSVTimeSeriesFile.check_order_duplicates(None, time_series)

    anno1 = [None for i in range(12)]
    anno2 = [None for i in range(12)]

    year1 = years[0]
    year2 = years[1]

    #Prendo dal File i dati degli anni e li inserisco nelle liste di riferimento
    for item in time_series:
        if year1 == int(item[0].split("-")[0]):
            anno1[int(item[0].split("-")[1]) - 1] = item[1]
        elif year2 == int(item[0].split("-")[0]):
            anno2[int(item[0].split("-")[1]) - 1] = item[1]

    result = []
    for index in range(1, 12):
        is_in_range = False

        #Controllo che non ci siano elementi nulli e che la differenza sia in un range di 2
        if anno1[index] != None and anno2[index] != None and anno1[index - 1] != None and anno2[index - 1] != None:
            if abs(anno1[index] - anno1[index - 1] - anno2[index] + anno2[index - 1]) <= 2 :
                is_in_range = True

        result.append(is_in_range)

    return result