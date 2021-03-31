from PySimpleGUI import PySimpleGUI as sg

from Plot import Plot
from Cfunction import Cfunction


class View:
    def __init__(self):
        self.incr = 100
        self.__tamanho = 1
        self._final = 2000
        self.__inicial = 1000
        self.__c = Cfunction()

        sg.theme('Reddit')
        layout = [
            [sg.Text('Informe o intervalo de testes.\n')],
            [
                sg.Text('Tamanho inicial: '),
                sg.Input(key='inicial', pad=((18, 5), (0, 0)))
            ],
            [
                sg.Text('Tamanho final: '),
                sg.Input(key='final', pad=((28, 5), (0, 0)))
            ],
            [
                sg.Text('Incremento/passo: '),
                sg.Input(key='incr')
            ],
            [sg.Text('\n\nInforme a quantidade de dígitos a ser utilizado. \n'
                     'Valor numérico entre 1 e 18, inclusive.\n')],
            [
                sg.Text('Quantidade de dígitos'),
                sg.Spin(
                    [i for i in range(1, 18)],
                    initial_value=5,
                    size=(10, 1),
                    key='qnt'
                )
            ],
            [sg.Text('\n\nQuais gráficos quer ver?')],
            [
                sg.Checkbox('Quick sort',  default=True, key='quick'),
                sg.Checkbox('Bubble sort', default=True, key='bubble'),
                sg.Checkbox('Digital',     default=True, key='digital')
            ],
            [sg.Button('Testar',     size=(23, 1), pad=((80, 80), (30, 0)))],
            [sg.Button('Resultados', size=(23, 1), pad=((80, 80), (15, 0)))],
        ]
        self.__window = sg.Window('Comparação', layout, size=(350, 450))

    def run(self):

        while True:
            events, values = self.__window.read()

            if events == sg.WINDOW_CLOSED:
                break

            if events == 'Testar' or events == 'Resultados':
                try:
                    self.__incr = int(values['incr'])
                    self.__tamanho = int(values['qnt'])
                    self.__final = int(values['final'])
                    self.__inicial = int(values['inicial'])
                except ValueError:
                    continue

                if self.__tamanho <= 0 or self.__tamanho >= 19:
                    continue

                if self.__inicial <= 0 or self.__final <= 0 or self.__incr <= 0:
                    continue

                if events == 'Testar':
                    for i in range(self.__inicial, self.__final, self.__incr):
                        self.__c.execute(i, self.__tamanho, i)

                    plot = Plot(
                        self.__tamanho,
                        self.__inicial,
                        self.__final,
                        self.__incr
                    )
                    plot.render(
                        values['bubble'],
                        values['quick'],
                        values['digital']
                    )

                if events == 'Resultados':
                    plot = Plot(
                        self.__tamanho,
                        self.__inicial,
                        self.__final,
                        self.__incr
                    )
                    plot.render(
                        values['bubble'],
                        values['quick'],
                        values['digital']
                    )
