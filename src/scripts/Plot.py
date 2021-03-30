from pandas import read_csv
from pandas import DataFrame
import matplotlib.pyplot as plt


class Plot:
    def __init__(self, t, low, high, incr):
        self.__data = []
        self.__filter = []

        self.__dataframe = read_csv(f'./../../tmp/log_{t}.csv', delimiter=';')

        for i in range(low, high, incr):
            self.__filter.append(self.__dataframe['quantidade'] == i)

        for i in range(len(self.__filter)):
            self.__data.append(self.__dataframe.where(self.__filter[i]).mean())

    def close(self):
        plt.close()

    def render(self):

        plt.grid(True)

        plt.title('Comparação entre métodos de ordenação')

        plt.ylabel('Tempo de execução (s)')
        plt.xlabel('Tamanho da entrada (adimensional)')

        legend_quick, = plt.plot(
            DataFrame(self.__data)['quantidade'],
            DataFrame(self.__data)['quick'],
            marker='o',
            markersize=4,
            color='blue',
            linestyle='--',
            label='Bubble Sort'
        )
        legend_bubble, = plt.plot(
            DataFrame(self.__data)['quantidade'],
            DataFrame(self.__data)['bubble'],
            marker='o',
            markersize=4,
            color='red',
            linestyle='--',
            label='Quick Sort'
        )
        legend_digital, = plt.plot(
            DataFrame(self.__data)['quantidade'],
            DataFrame(self.__data)['digital'],
            marker='o',
            markersize=4,
            color='green',
            linestyle='--',
            label='Ordenação digital'
        )

        plt.legend(handles=[legend_bubble, legend_quick, legend_digital])

        plt.show()
