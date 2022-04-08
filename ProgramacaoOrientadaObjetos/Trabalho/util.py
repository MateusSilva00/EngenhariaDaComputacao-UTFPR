import os

def clearConsole():
    command = 'clear'
    if os.name in ('nt', 'dos'):  # Verifica se máquina é um ruindows
        command = 'cls'
    os.system(command)

