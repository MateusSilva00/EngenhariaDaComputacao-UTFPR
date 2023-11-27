from dataclasses import dataclass
from typing import List


@dataclass
class Admin:
    nome: List[str] = None
    email: List[str] = None
    senha: List[int] = None


@dataclass
class Evento:
    id_admin: List[int] = None
    nome: List[str] = None
    descricao: List[str] = None
    endereco: List[str] = None
    inicio: List[str] = None
    fim: List[str] = None


@dataclass
class Atividade:
    id_evento: List[int] = None
    tipo_atividade: List[str] = None
    nome_atividade: List[str] = None
    descricao: List[str] = None
    local: List[str] = None
    custo: List[float] = None
    horario_inicio: List[str] = None
    duracao: List[int] = None


@dataclass
class Participante:
    nome: List[str] = None
    email: List[str] = None
    curso: List[str] = None
    ra: List[str] = None
    cpf: List[str] = None


@dataclass
class Participacao:
    id_participante: List[int] = None
    id_atividade: List[int] = None
    tipo_participante: List[str] = None
