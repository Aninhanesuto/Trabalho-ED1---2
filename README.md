# Estrutura de Dados I – Trabalho Prático

**Prazo para envio: 09/03/2025, 23:59 – via [AVA](https://ava.ufes.br)**

---

## 1. Descrição do Problema

Vianne Rochele está abrindo uma loja de varejo online com os seguintes departamentos:
- Chocolates
- Vinhos
- Livros
- Streaming de Filmes

O sistema precisa:
- Gerenciar produtos **de forma independente por categoria**
- Permitir **adições, remoções e reorganizações**
- Suportar **reversão de alterações** com `undo` e `redo`
- Ser **flexível e seguro**, mantendo controle de versão e integridade dos dados

### Estrutura de Dados por Produto:

#### Chocolate
- Nome (chave)
- Marca
- Tipo (ao leite, amargo ou branco)
- Porcentagem de cacau (se for amargo)
- Origem
- Peso
- Data de fabricação
- Validade

#### Vinho
- Nome (chave)
- Vinícola
- Tipo (tinto, branco, rosé, espumantes)
- País
- Uva
- Região
- Ano de fabricação

#### Livro
- Título (chave)
- Autor
- Editora
- Data de publicação
- Idioma
- Número de páginas

#### Filme
- Título (chave)
- Diretor
- Gênero
- Distribuidor
- Duração
- País de origem

A estrutura deve ser **genérica**, com reutilização para todos os departamentos por meio de uma **Lista Reversível**.

---

## 2. Lista Reversível

A **Lista Reversível** é:
- **Linear, simplesmente encadeada**, sem nós sentinelas
- Ordenada por **chave de busca**
- Suporta:
  - Busca
  - Inserção
  - Exclusão
  - `undo`: desfaz a última operação de edição
  - `redo`: refaz a operação desfeita
- Deve armazenar apenas um **número finito de versões**
- Reutiliza nós para economizar memória

### Exemplo visual:

