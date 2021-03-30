from PySimpleGUI import PySimpleGUI as sg

from Plot import Plot
from Cfunction import Cfunction


class View:
    def __init__(self):
        self.__tamanho = 1
        self.__c = Cfunction()

        sg.theme('Reddit')
        layout = [
            [sg.Text('Informe a quantidade de dígitos a ser utilizado. \n'
                     'Valor numérico entre 1 e 18, inclusive.\n\n')],
            [
                sg.Text('Quantidade de dígitos'),
                sg.Spin(
                    [i for i in range(1, 18)],
                    initial_value=5,
                    size=(10, 1),
                    key='qnt'
                )
            ],
            [sg.Button('Testar',     size=(23, 1), pad=((80, 80), (15, 0)))],
            [sg.Button('Resultados', size=(23, 1), pad=((80, 80), (15, 0)))],
        ]
        self.__window = sg.Window('Comparação', layout, size=(300, 210))

    def run(self):

        while True:
            events, values = self.__window.read()

            if events == sg.WINDOW_CLOSED:
                break

            if events == 'Testar' or events == 'Resultados':
                try:
                    self.__tamanho = int(values['qnt'])
                except ValueError:
                    continue

                if self.__tamanho <= 0 or self.__tamanho >= 19:
                    continue

                if events == 'Testar':
                    for i in range(1000, 2000, 100):
                        self.__c.execute(i, self.__tamanho, i)
                    plot = Plot(self.__tamanho, 1000, 2000, 100)
                    plot.render()

                if events == 'Resultados':
                    plot = Plot(self.__tamanho, 1000, 2000, 100)
                    plot.render()
