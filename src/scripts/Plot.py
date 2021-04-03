from pandas import read_csv
from pandas import DataFrame
import matplotlib.pyplot as plt


class Plot:
    def __init__(self, t, low, high, incr):
        self.__data = []
        self.__filter = []

        self.__digitos = t

        self.__dataframe = read_csv(f'./../../tmp/log_{t}.csv', delimiter=';')

        for i in range(low, high+1, incr):
            self.__filter.append(self.__dataframe['quantidade'] == i)

        for i in range(len(self.__filter)):
            self.__data.append(self.__dataframe.where(self.__filter[i]).mean())

    def render(self, bubble=True, quick=True, digital=True):
        legends = []

        plt.grid(True)

        plt.title(
            f'Comparação entre métodos de ordenação para {self.__digitos} dígitos'
        )

        plt.ylabel('Tempo de execução (s)')
        plt.xlabel('Tamanho da entrada')

        if quick:
            legend_quick, = plt.plot(
                DataFrame(self.__data)['quantidade'],
                DataFrame(self.__data)['quick'],
                marker='o',
                markersize=4,
                color='blue',
                linestyle='--',
                label='Quick Sort'
            )
            legends.append(legend_quick)

        if bubble:
            legend_bubble, = plt.plot(
                DataFrame(self.__data)['quantidade'],
                DataFrame(self.__data)['bubble'],
                marker='o',
                markersize=4,
                color='red',
                linestyle='--',
                label='Bubble Sort'
            )
            legends.append(legend_bubble)

        if digital:
            legend_digital, = plt.plot(
                DataFrame(self.__data)['quantidade'],
                DataFrame(self.__data)['digital'],
                marker='o',
                markersize=4,
                color='green',
                linestyle='--',
                label='Ordenação digital'
            )
            legends.append(legend_digital)

        plt.legend(handles=legends)

        plt.show()
