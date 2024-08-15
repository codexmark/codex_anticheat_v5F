O projeto apresenta diversas abordagens heurísticas para realizar buscas específicas em sistemas operacionais. Abaixo estão as descrições detalhadas de cada abordagem, suas funcionalidades e instruções de uso.

## Abordagens Heurísticas

### Heuristic Class - HC-Scan

**Descrição**: Uma heurística para encontrar uma classe de janela específica em um sistema operacional.

**Funcionalidades**:
- Encontra uma classe de janela específica no sistema operacional.
- Não é case sensitive, ou seja, não diferencia maiúsculas de minúsculas.
- Utiliza uma única string por vez, sem espaços.
- Usa a função `_tcsstr(y,"xxxx")` para realizar a busca.

**Uso**: Para usar o código, chame a função `_tcsstr(y,"xxxx")`, passando a string da classe de janela que deseja encontrar como parâmetro. A função retornará um ponteiro para a primeira ocorrência da string encontrada na memória.

---

### Heuristic Scan - HNC-Scan (Bad Words)

**Descrição**: Projetada para realizar uma varredura heurística em busca de palavras indesejadas em strings.

**Funcionalidades**:
- Realiza a busca de palavras indesejadas em strings.
- **Case sensitive**: diferencia maiúsculas de minúsculas.
- Ignora buscas em navegadores.
- Utiliza um formato de busca baseado em expressões como `{{"xxx"}}`, onde "xxx" representa a palavra ou expressão a ser encontrada.

**Uso**: Para usar o HNC-Scan, passe a string que deseja analisar e as palavras indesejadas no formato especificado. O código verificará a presença das palavras na string fornecida.

---

### Heuristic Window Name Scan - HW-scan

**Descrição**: Realiza uma varredura heurística para encontrar nomes de janelas em um sistema operacional, podendo encontrar janelas tanto através de seu nome quanto utilizando o código do [Handler 1.5 by Oliver Bock].

**Funcionalidades**:
- Realiza a busca de nomes de janelas em um sistema operacional.
- **Case-sensitive**: diferencia maiúsculas de minúsculas.
- Permite a busca de janelas usando a função `_tcsstr(x,"xxx")`, onde "xxx" é a palavra a ser encontrada.
- Aceita apenas uma palavra por vez, sem espaços vazios.

**Uso**: Para utilizar o HW-scan, chame a função `_tcsstr(x,"xxx")`, passando a string do nome da janela que deseja encontrar como parâmetro. O código retornará um ponteiro para a primeira ocorrência da string encontrada.

---

### Scanner Heurístico Bruto - H-Scan (Palavras-chave)

**Descrição**: O modo "Scanner Heurístico - H-Scan" é projetado para detectar palavras-chave que podem acionar eventos ou ações específicas no sistema.

**Funcionalidades**:
- Realiza a busca de palavras mágicas em strings.
- **Case-sensitive**: diferencia maiúsculas de minúsculas.
- Utiliza a função `strstr(t,"xxxx")` para encontrar as palavras desejadas.
- Permite a configuração de múltiplas strings para busca.

**Uso**: Para utilizar o H-Scan, defina as palavras mágicas que deseja detectar e chame a função `strstr(t,"xxxx")`, onde "xxxx" representa a palavra chave a ser encontrada.

---

### Window Name Scan - w-scan

**Descrição**: O modo "Window Name Scan - w-scan" permite a busca de nomes de janelas no sistema operacional. Ele pode encontrar janelas tanto através de seu nome quanto utilizando o código do [Handler 1.5 by Oliver Bock].

**Funcionalidades**:
- Realiza a busca de nomes de janelas em um sistema operacional.
- **Case-sensitive**: diferencia maiúsculas de minúsculas.
- Permite a busca de janelas usando a função `TitleWindow("xxxx")`, onde "xxxx" é o nome da janela a ser encontrada.

**Uso**: Para utilizar o w-scan, chame a função `TitleWindow("xxxx")`, passando o nome da janela que deseja encontrar como parâmetro. O código retornará um resultado que indica se a janela foi encontrada.

---

## Importante - Personalização de Nomes de Arquivos

Este projeto requer que você personalize os nomes dos arquivos em ambos os lados, tanto no código principal quanto no arquivo DLL do launcher. Isso é necessário para garantir a segurança e o funcionamento adequado do sistema.

### Instruções:
1. **Defina seus próprios nomes de arquivo e extensão** no código, em ambos os lados:
   - No arquivo `char * Create/readFileName` no launcher e no DLL do código principal.
   - Os nomes de arquivo devem ser os mesmos em ambos os lados.

2. **Se você usar apenas o nome do arquivo, como por exemplo: "x.fdp"**, tanto o arquivo do launcher quanto o arquivo principal precisam estar dentro da mesma pasta. Caso contrário, o sistema não iniciará, pois não conseguirá encontrar o arquivo para leitura.

3. **Personalize o nome do arquivo/endereço para maior segurança**, usando caminhos e nomes de arquivo exclusivos.

**Exemplo**:
```c
char * CreateFileName   = "c://1.fdp";  //1 //PERSONALIZE Name file/address FOR MORE SECURITY
char * ReadFileName     = "c://2.fdp";  //2 //PERSONALIZE Name file/address FOR MORE SECURITY
```

Neste exemplo, os nomes de arquivo são "1.fdp" e "2.fdp", respectivamente, e o caminho é "c://". Certifique-se de que esses arquivos existam nos locais especificados em ambos os lados do sistema.

### Observação
Personalizar os nomes de arquivo e caminhos adicionará um nível extra de segurança ao seu projeto, pois os arquivos não poderão ser acessados facilmente por terceiros.

---

### Créditos
Este projeto utiliza o código do [Handler 1.5 by Oliver Bock] para facilitar a busca de janelas. Agradecimentos a Oliver Bock.

### Licença
Este projeto está licenciado sob a [Licença MIT](LICENSE).

### Fontes
[1] https://www.sciencedirect.com/science/article/pii/S0004370224001085
[2] https://www.ajogmfm.org/article/S2589-9333%2823%2900324-5/pdf
[3] https://link.springer.com/chapter/10.1007/978-3-540-87477-5_24
[4] https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3193077/
[5] https://www.researchgate.net/publication/221451795_A_Performance_Study_of_Task_Scheduling_Heuristics_in_HC_Environment
