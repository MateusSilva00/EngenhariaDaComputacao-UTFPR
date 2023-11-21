import re
from dataclasses import asdict, dataclass
from random import choice
from typing import List

import pandas as pd
from faker import Faker


@dataclass
class Cliente:
    id_cliente: List[int] = None
    cpf: List[str] = None
    nome: List[str] = None
    data_reg: List[str] = None
    valor_max_liberado: List[float] = None


@dataclass
class Emprestimo:
    id_emprestimo: List[int] = None
    id_cliente: List[int] = None
    data_emprestimo: List[str] = None
    valor_total: List[float] = None
    nro_parcelas: List[int] = None
    quitado: List[bool] = None


fake = Faker("pt_BR")


def criar_clientes():
    clientes = Cliente(
        id_cliente=[],
        cpf=[],
        nome=[],
        data_reg=[],
        valor_max_liberado=[],
    )

    for i in range(10000):
        clientes.id_cliente.append(i + 1)
        cpf = re.sub("\D", "", fake.cpf())
        clientes.cpf.append(cpf)
        clientes.nome.append(fake.name())
        clientes.data_reg.append(fake.date())
        clientes.valor_max_liberado.append(
            fake.pyfloat(
                right_digits=2, min_value=1000, max_value=10000000, positive=True
            )
        )

    pd.DataFrame(asdict(clientes)).to_csv("clientes.csv", index=False)


def criar_emprestimos():
    emprestimos = Emprestimo(
        id_emprestimo=[],
        id_cliente=[],
        data_emprestimo=[],
        valor_total=[],
        nro_parcelas=[],
        quitado=[],
    )

    for i in range(30000):
        emprestimos.id_emprestimo.append(i + 1)
        emprestimos.id_cliente.append(choice(range(1, 10001)))
        emprestimos.data_emprestimo.append(fake.date())
        emprestimos.valor_total.append(
            fake.pyfloat(
                right_digits=2, min_value=1000, max_value=10000000, positive=True
            )
        )
        emprestimos.nro_parcelas.append(choice(range(1, 120)))
        emprestimos.quitado.append(choice([True, False]))

    pd.DataFrame(asdict(emprestimos)).to_csv("emprestimos.csv", index=False)


if __name__ == "__main__":
    criar_clientes()
    criar_emprestimos()
