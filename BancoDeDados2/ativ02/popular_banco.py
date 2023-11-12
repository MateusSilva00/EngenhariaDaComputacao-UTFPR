import string
from dataclasses import asdict, dataclass
from random import choice, randint
from typing import List

import pandas as pd
from faker import Faker


@dataclass
class Alunos:
    nome: List[str] = None
    DataNasc: List[str] = None
    Idade: List[int] = None
    NomeMae: List[str] = None
    Cidade: List[str] = None
    Estado: List[str] = None
    Curso: List[str] = None
    periodo: List[int] = None


@dataclass
class Disciplina:
    Sigla: List[str] = None
    Nome: List[str] = None
    SiglaPreReq: List[str] = None
    NNCred: List[int] = None
    Monitor: List[str] = None
    Depto: List[str] = None


@dataclass
class Matricula:
    ra: List[int] = None
    sigla: List[str] = None
    ano: List[str] = None
    semestre: List[str] = None
    codTurma: List[int] = None
    notaP1: List[float] = None
    notaP2: List[float] = None
    notaTrab: List[float] = None
    notaFIM: List[float] = None
    frequencia: List[int] = None


fake = Faker("pt_BR")


def criar_alunos():
    alunos = Alunos(
        nome=[],
        DataNasc=[],
        Idade=[],
        NomeMae=[],
        Cidade=[],
        Estado=[],
        Curso=[],
        periodo=[],
    )

    CURSOS = [
        "Engenharia da Computação",
        "Engenharia Mecânica",
        "Engenharia Civil",
        "Engenharia Elétrica",
        "Agronomia",
        "Matemática",
        "Letras",
        "Engenharia Cartográfica",
        "Química",
    ]

    for i in range(5000):
        alunos.nome.append(fake.name())
        alunos.DataNasc.append(fake.date_of_birth(minimum_age=16, maximum_age=60))
        alunos.Idade.append(2023 - alunos.DataNasc[i].year)
        alunos.NomeMae.append(fake.name_female())
        alunos.Cidade.append(fake.city())
        alunos.Estado.append(fake.estado_sigla())
        alunos.Curso.append(fake.random_element(CURSOS).upper())
        alunos.periodo.append(fake.pyint(min_value=1, max_value=10))

    pd.DataFrame(asdict(alunos)).to_csv("alunos.csv", index=False)


def generate_random_code() -> str:
    letter = choice(string.ascii_uppercase) + choice(string.ascii_uppercase)
    number = randint(15, 30)
    sequence = choice(["EL", "CP", "EC", "EM", "AG", "MT", "LT", "CC", "QM"])
    code = f"{letter}{number}{sequence}"

    return code


def criar_disciplinas():
    disciplinas = Disciplina(
        Sigla=[], Nome=[], SiglaPreReq=[], NNCred=[], Monitor=[], Depto=[]
    )

    DEPARTAMENTOS = [
        "DAINF",
        "DAFIS",
        "DAMAT",
        "DAMEC",
        "DAGRO",
        "DAMEL",
        "DAMEC",
        "DATEC",
    ]

    for _ in range(60):
        disciplinas.Sigla.append(generate_random_code())
        disciplinas.Nome.append(fake.job())
        disciplinas.SiglaPreReq.append(generate_random_code())
        disciplinas.NNCred.append(fake.pyint(min_value=1, max_value=12))
        disciplinas.Monitor.append(fake.name())
        disciplinas.Depto.append(fake.random_element(DEPARTAMENTOS))

    pd.DataFrame(asdict(disciplinas)).to_csv("disciplinas.csv", index=False)


def criar_matriculas():
    matriculas = Matricula(
        ra=[],
        sigla=[],
        ano=[],
        semestre=[],
        codTurma=[],
        notaP1=[],
        notaP2=[],
        notaTrab=[],
        notaFIM=[],
        frequencia=[],
    )

    disciplinas = pd.read_csv("disciplinas.csv")

    for i in range(32000):
        matriculas.ra.append(fake.pyint(min_value=15000, max_value=19999))
        matriculas.sigla.append(fake.random_element(disciplinas["Sigla"]))
        matriculas.ano.append(fake.pyint(min_value=2010, max_value=2023))
        matriculas.semestre.append(fake.pyint(min_value=1, max_value=2))
        matriculas.codTurma.append(fake.pyint(min_value=1, max_value=4))
        matriculas.notaP1.append(
            fake.pyfloat(min_value=0, max_value=10, right_digits=2)
        )
        matriculas.notaP2.append(
            fake.pyfloat(min_value=0, max_value=10, right_digits=2)
        )
        matriculas.notaTrab.append(
            fake.pyfloat(min_value=0, max_value=10, right_digits=2)
        )
        nota_final = (
            (matriculas.notaP1[i] * 0.4)
            + (matriculas.notaP2[i] * 0.4)
            + (matriculas.notaTrab[i] * 0.2)
        )
        matriculas.notaFIM.append(round(nota_final, 2))
        matriculas.frequencia.append(fake.pyint(min_value=0, max_value=100))

    pd.DataFrame(asdict(matriculas)).to_csv("matriculas.csv", index=False)


if __name__ == "__main__":
    criar_alunos()
    criar_disciplinas()
    criar_matriculas()
