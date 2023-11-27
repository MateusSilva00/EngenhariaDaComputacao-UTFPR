import hashlib
import re
from dataclasses import asdict
from datetime import timedelta
from random import choice, randint

import pandas as pd
from faker import Faker

from datatypes import (
    Admin,
    Atividade,
    CeritificadoAtividade,
    Evento,
    Participacao,
    Participante,
)

fake = Faker("pt_BR")


GRADUAÇÃO = [
    "Engenharia Civil",
    "Engenharia de Computação",
    "Engenharia de Produção",
    "Engenharia Mecânica",
    "Letras",
    "Química",
    "Matemática",
    "Análise e Desenvolvimento de Sistemas",
    "Ciência da Computação",
    "Ciências Biológicas",
    "Ciências Contábeis",
    "Ciências Econômicas",
    "Direito",
    "Enfermagem",
    "Farmácia",
]

TIPO_ATIVIDADE = [
    "Palestra",
    "Workshop",
    "Minicurso",
    "Curso",
    "Apresentação de Tcc",
]

PALESTRAS = ["Empreendedorismo", "Mercado de Trabalho", "Inovação", "Tecnologia"]
CURSOS = [
    "Python",
    "Java",
    "C++",
    "C#",
    "JavaScript",
    "SQL",
    "PHP",
    "Produção de pinga com mel e limão",
]

EMAILS = ["@gmail.com", "@hotmail.com", "@outlook.com", "@yahoo.com.br"]


def criar_admins():
    admins = Admin(
        nome=[],
        email=[],
        senha=[],
    )

    for i in range(101):
        admins.nome.append(fake.name())
        admins.email.append(
            admins.nome[i].replace(" ", "").lower() + fake.random_element(EMAILS)
        )
        ultimo_nome = admins.nome[i].split(" ")[-1].lower()
        admins.senha.append(
            ultimo_nome + "_" + str(fake.pyint(min_value=100, max_value=999))
        )

    pd.DataFrame(asdict(admins)).to_csv("admins.csv", index=False)


def criar_evento():
    eventos = Evento(
        id_admin=[],
        nome=[],
        descricao=[],
        endereco=[],
        inicio=[],
        fim=[],
    )

    for _ in range(1501):
        eventos.id_admin.append(randint(1, 100))
        nome_evento = "Semana Acadêmica de " + choice(GRADUAÇÃO)
        eventos.nome.append(nome_evento)
        eventos.descricao.append(fake.text().replace("\n", " ").strip())
        eventos.endereco.append(fake.address().replace("\n", ", ").strip())
        start_date = fake.date_between(start_date="-4y")
        eventos.inicio.append(start_date)
        eventos.fim.append(start_date + timedelta(days=randint(2, 5)))

    pd.DataFrame(asdict(eventos)).to_csv("eventos.csv", index=False)


def criar_atividade():
    atividades = Atividade(
        id_evento=[],
        tipo_atividade=[],
        nome_atividade=[],
        descricao=[],
        local=[],
        custo=[],
        horario_inicio=[],
        duracao=[],
    )

    tp_ativ_mapping = {
        "Palestra": 0,
        "Workshop": 1,
        "Minicurso": 2,
        "Curso": 3,
        "Apresentação de Tcc": 4,
    }

    for i in range(8001):
        NOME_ATIVIDADE = {
            0: choice(PALESTRAS) + " em " + choice(GRADUAÇÃO),
            1: "Workshop de " + choice(GRADUAÇÃO),
            2: "Minicurso de " + choice(CURSOS),
            3: "Curso de " + choice(CURSOS),
            4: "Apresentação de Tcc de " + fake.name() + " em " + choice(GRADUAÇÃO),
        }

        atividades.id_evento.append(randint(101, 1599))
        atividades.tipo_atividade.append(choice(TIPO_ATIVIDADE))

        atividades.nome_atividade.append(
            NOME_ATIVIDADE[tp_ativ_mapping[atividades.tipo_atividade[i]]]
        )

        atividades.descricao.append(fake.text().replace("\n", " ").strip())
        atividades.local.append(fake.address().replace("\n", ", ").strip())
        atividades.custo.append(fake.pyfloat(min_value=0, max_value=1000))
        atividades.horario_inicio.append(fake.time())
        atividades.duracao.append(randint(1, 4))

    pd.DataFrame(asdict(atividades)).to_csv("atividades.csv", index=False)


def criar_participante():
    participantes = Participante(
        nome=[],
        email=[],
        curso=[],
        ra=[],
        cpf=[],
    )

    for i in range(10001):
        participantes.nome.append(fake.name())
        participantes.email.append(
            participantes.nome[i].replace(" ", "").lower() + fake.random_element(EMAILS)
        )
        participantes.curso.append(choice(GRADUAÇÃO))
        participantes.ra.append(str(fake.pyint(min_value=10000000, max_value=99999999)))

        cpf = re.sub("[^0-9]", "", fake.cpf())

        participantes.cpf.append(cpf)

    pd.DataFrame(asdict(participantes)).to_csv("participantes.csv", index=False)


def criar_participacao():
    participacoes = Participacao(
        id_participante=[],
        id_atividade=[],
        tipo_participante=[],
    )

    for _ in range(20001):
        participacoes.id_participante.append(randint(1, 10000))
        participacoes.id_atividade.append(randint(1, 8000))
        participacoes.tipo_participante.append(
            choice(["Aluno", "Professor", "Comunidade"])
        )

    pd.DataFrame(asdict(participacoes)).to_csv("participacoes.csv", index=False)


if __name__ == "__main__":
    criar_admins()
    criar_evento()
    criar_atividade()
    criar_participante()
    criar_participacao()
