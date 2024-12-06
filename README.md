
<h1 align="center"> 
  <a href="https://git.io/typing-svg">
    <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=900&size=36&duration=2500&pause=250&color=F7F7F7&background=0D111700&center=true&vCenter=true&multiline=true&width=810&height=100&lines=Beach+Pong+na+DE1-SoC;Uma+GPU+Rodando+Pong+em+Tem%C3%A1tica+Praiana" alt="Typing SVG" />
  </a> 
</h1>



<div align="center" id="sobre-o-projeto"> 
🏖️🌊🌴☀️🏐🐚🌊⛱️🦀🐬🏖️🌊🌴☀️🏐🐚🌊⛱️🦀🐬🏖️🌊🌴☀️🏐🐚🌊⛱️🦀🐬🏖️🌊🌴☀️🏐
</div>


# Sumário

- [Sobre o Projeto](#sobre-o-projeto)
- [Descrição dos Equipamentos e Software Utilizados](#equipamentos)
- [Estrutura da Placa DE1-SoC](#arq_CPU)
- [Metodologia](#metodologia)
- [Resultados e Testes](#resultados-e-testes)
- [Funcionamento do Jogo](#Funcionamento)
- [Makefile](#makefile)
- [Conclusão](#conclusao)
- [Referências](#referencia)

<div align="justify" id="sobre-o-projeto"> 
<h2> Sobre o Projeto</h2>

Este projeto se concentra na ultima atividade desenvolvida, utilizando os conhecimentos adquiridos nos projetos anteriores,das quais é importante pontuar, o uso da GPU e do acelerometro.

O problema 3 do módulo integrador TEC499 - SISTEMAS DIGITAIS do curso de Engenharia de Computação da UEFS propõe a criação de um jogo utilizando todos os recursos implementados nos dois primeiros projetos onde é necessario utilizar todas as funções implementadas na biblioteca
do Processador Gráfico e a criação de no minimo 1 novo sprite para ser usado no projeto.

Este relatório aborda a construção do jogo Pong com uma tematica praiana, onde todas as ferramentas são utilizadas, além disso aborda a utilização de um novo equipamento de Entrada/Saida, este sendo o mouse.

Os requisitos principais para elaboração do sistema são apresentados a seguir:

*Deverá utilizar todas as funções implementadas na biblioteca
do Processador Gráfico e no mínimo um novo sprite deve ser
colocado na memória e utilizado no jogo;
*Os dois jogadores devem jogar simultaneamente utilizando
obrigatoriamente o acelerômetro, e adicionalmente o mouse;
*A variação da velocidade no movimento deve ser refletida na
ação do ator do jogo. Por exemplo, no jogo breakout a barra
se move com velocidade maior se o movimento do mouse for
brusco;
*Informações do jogo (placar, vidas, etc.) devem na tela do
jogo;

<h2>  Equipe <br></h2>
<uL> 
  <li><a href="https://github.com/Oguelo">Alex da Fonseca Dantas Junior</a></li>
  <li><a href="https://github.com/BRCZ1N">Bruno Campos de Oliveira Rocha</a></li>
  <li><a href="https://github.com/duasck">Luis Eduardo Leite Azevedo</a></li>
</ul>
</div>


<div align="justify" id="equipamentos"> 
<h2> Descrição dos Equipamentos e Software Utilizados</h2>

Nesta seção, são apresentados os equipamentos e software utilizados durante o desenvolvimento do projeto.

<h3>Kit de desenvolvimento DE1-SoC</h3>

A placa DE1-SoC é um kit de desenvolvimento que integra um processador ARM Cortex-A9 dual-core com um FPGA Cyclone V da Intel, proporcionando uma poderosa plataforma para projetos que combinam software e hardware. Com uma ampla variedade de periféricos, como portas VGA, Ethernet, USB, e áudio, a DE1-SoC é ideal para aplicações em sistemas embarcados e FPGA. Devido à sua versatilidade, essa placa é amplamente utilizada em ambientes educacionais e de pesquisa, facilitando o aprendizado e o desenvolvimento de projetos em ambas as áreas.
Abaixo estão os elementos utilizados na construção desse projeto:

<h3> Linguagem C</h3>
A linguagem C foi escolhida por sua eficiência, portabilidade e ampla aplicação em sistemas embarcados. Com uma sintaxe simples, ela oferece controle preciso sobre o hardware, além de contar com bibliotecas padrão e ferramentas que facilitam o desenvolvimento de código compacto e otimizado, ideal para dispositivos com recursos limitados.

<h3> Linguagem Assembly</h3>
A linguagem assembly foi escolhida por sua capacidade de oferecer controle direto sobre o hardware, permitindo o máximo de otimização e eficiência em sistemas embarcados. Com uma sintaxe próxima ao código de máquina, o assembly possibilita o uso específico de registradores e instruções, aproveitando ao máximo os recursos da arquitetura ARMv7. Essa escolha é ideal para aplicações em que desempenho e controle absoluto sobre o processamento são essenciais, especialmente em dispositivos com recursos limitados, onde o gerenciamento preciso do hardware é fundamental.

<h3> Compilador GNU</h3>

O GCC, abreviação de "GNU Compiler Collection" (Coleção de Compiladores GNU), é uma popular distribuição de compiladores que oferece suporte a diversas linguagens de programação, como C, C++, Objective-C, Fortran e Ada. Quando executado, o GCC realiza várias etapas, incluindo pré-processamento, compilação, montagem e vinculação. Ele também disponibiliza uma ampla variedade de opções de linha de comando, permitindo que o desenvolvedor personalize o processo de compilação conforme suas necessidades específicas

<h3>Vistual Studio Code</h3>

O Visual Studio Code, conhecido como VSCode, é um ambiente de desenvolvimento amplamente usado. Desenvolvido pela Microsoft, é um editor de código gratuito e de código aberto com recursos como realce de sintaxe, conclusão de código e depuração integrada. Suporta várias linguagens e possui extensões para personalização. No projeto ele foi utilizado para desenvolver o código fonte do jogo.

<h3> Monitor CRT</h3>

O monitor utilizado no projeto foi o DELL M782p, um modelo de CRT que utiliza tubo de raios catódicos para exibição de imagens. Com uma tela de 17 polegadas e resolução máxima de 1280x1024 pixels, ele oferece uma interface VGA para conexão com computadores ou placas de desenvolvimento. Os monitores CRT, como o DELL M782p, são conhecidos por sua reprodução de cores vibrantes e tempos de resposta rápidos, tornando-os ideais para projetos que exigem interação em tempo real, como jogos e simulações.


Abaixo estão dados detalhados sobre o monitor usado:

|            Características            |      Detalhes      |
| :------------------------------------: | :----------------: |
|       **Tipo de Display**       |      Vertical      |
| **Tamanho da Tela (Horizontal)** |      32,4 cm      |
|  **Tamanho da Tela (Vertical)**  |      24,6 cm      |
|  **Tamanho da Tela (Diagonal)**  |      40,6 cm      |
|      **Varredura Vertical**      |    50 - 160 Hz    |
|     **Varredura Horizontal**     |    30 - 70 kHz    |
|  **Tamanho da Tela (Diagonal)**  |   43,2 cm (17")   |
|          **Dot Pitch**          |  0,270 x 0,270 mm  |
|     **Resolução Máxima**     | 1280 x 1024 pixels |
|    **Resolução do Display**    | 1024 x 768 pixels |

</div>


<div align="justify" id="arq_CPU">
<h2> Estrutura da Placa DE1-SoC </h2>

Nesta parte, será detalhada a arquitetura da placa DE1-SoC, incluindo o processador ARM Cortex-A9, a organização dos registradores, o mapeamento dos dispositivos de entrada/saída na memória, o uso da memória, a comunicação entre o processador e o FPGA, além do processo de compilação nativa diretamente na placa.

<h3>Resumo dos Recursos do Processador ARM Cortex-A9 </h3>

O ARM Cortex-A9 é baseado em uma arquitetura RISC (Reduced Instruction Set Computing), onde operações aritméticas e lógicas são realizadas nos registradores de propósito geral. A movimentação de dados entre memória e registradores é feita através de instruções Load e Store, com comprimento de palavra de 32 bits e endereçamento em estilo little-endian.

<h3>Organização dos Registradores</h3>

O processador ARM Cortex-A9 contém 15 registradores de propósito geral (R0 a R14), um contador de programa (R15) e um registrador de status do programa atual (CPSR), todos com 32 bits. Dois registradores têm tratamento especial: R13 é o Stack Pointer, enquanto R14 atua como registrador de link em chamadas de sub-rotina.

<h3>Instruções e Modo Thumb</h3>

As instruções têm 32 bits e são armazenadas na memória com alinhamento de palavras. O conjunto de instruções Thumb oferece uma versão reduzida com instruções de 16 bits, o que diminui os requisitos de memória, algo útil em sistemas embarcados.

<h3>Memória Utilizada</h3>

O HPS (Hard Processor System) conta com uma interface de memória que conecta o ARM MPCORE a uma memória DDR3 de 1 GB. Esta memória serve como armazenamento de dados e programas para os processadores ARM. Organizada como 256M x 32 bits, ela pode ser acessada por palavras de 32 bits, meias palavras e bytes.

<h3>Mapeamento de Dispositivos de Entrada/Saída</h3>

Os dispositivos de E/S disponíveis ao processador ARM são mapeados diretamente na memória e acessados como se fossem endereços de memória, utilizando as instruções Load e Store.

<h3>Interrupções de Hardware</h3>

Dispositivos de E/S podem gerar interrupções de hardware, ativando as linhas de solicitação de interrupção (IRQ ou FIQ) do processador. Quando ocorre uma interrupção, o processador entra no modo de exceção correspondente e salva o estado atual do programa. Antes de retornar à execução, o endereço salvo no registrador de link deve ser decrementado em 4.

<h3>Diagrama de Blocos da Placa DE1-SoC</h3>

O sistema DE1-SoC é composto pelo HPS e pelo FPGA, ambos integrados no chip Cyclone V SoC. O HPS inclui um processador ARM Cortex-A9 dual-core, uma interface de memória DDR3 e periféricos. O FPGA implementa dois processadores Intel Nios II e vários periféricos conectados.

<h3>Compilação Nativa na DE1-SoC</h3>

A compilação nativa ocorre quando o código é compilado no mesmo sistema em que será executado. Aqui, a compilação será realizada diretamente na placa, utilizando a linha de comando do Linux e as ferramentas de compilação integradas. O comando `gcc` invoca o GNU C Compiler, um compilador de código aberto muito usado para gerar executáveis no Linux.

</div>
## Metodologia

A metodologia deste projeto consistiu em desenvolver um novo jogo utilizando recursos ja anteriormente explorados, tais como a biblioteca para interação com a GPU e o acelerometro. A partir dessas bibliotecas, várias funções foram adaptadas para uso no jogo, mantendo a compatibilidade com a estrutura original e garantindo uma integração otimizada com a GPU para exibição gráfica dos elementos do jogo e o acelerometro.

As etapas do projeto serão detalhadas nas sessões posteriores, onde serão demonstrados o processo de implementação das funções, os testes realizados para validar o funcionamento das bibliotecas e a adaptação das funções gráficas para o ambiente de jogo. A otimização e os ajustes finais também serão discutidos, destacando as melhorias no desempenho gráfico e na interação com a GPU.

### Colisões

- Existem dois tipos principais de colisões implementadas no jogo:

*Colisão com as Raquetes*
A função ballRacketCollision é responsável por detectar se a bola colidiu com uma raquete. Essa detecção utiliza um sistema de intervalos para verificar se a bola está dentro da área de colisão da raquete (tanto no eixo X quanto no eixo Y). A raquete é dividida em três partes: início (esquerda), centro, e fim (direita), cada uma com um comportamento de colisão diferente.

Etapas da verificação de colisão:

Definir a faixa de colisão:

A faixa horizontal é calculada usando a posição central da raquete com uma margem para cada lado.
A faixa vertical é calculada com base na altura da raquete e uma margem acima e abaixo.
Detectar colisões específicas:

Se a bola colide com o início da raquete, ela muda de direção horizontal e vertical com um movimento mais inclinado.
Se a bola colide com o centro, ela muda apenas a direção vertical.
Se a bola colide com o fim, o comportamento é simétrico ao do início.
*Colisão com a parede*
A função ballBorderCollision verifica se a bola atingiu as bordas da tela (laterais, topo ou base).

Quando a bola atinge as bordas laterais, ela inverte sua direção horizontal (hori).
Quando a bola atinge o topo ou a base, o jogador correspondente perde uma vida, e os dados são reiniciados com a função resetData.

### As raquetes 

As raquetes são representadas como um bloco horizontal na tela feito por sprite , com coordenadas centrais e um tamanho fixo (BAR_SIZE). Sua posição no eixo X (coordX) é ajustada dinamicamente para permitir que o jogador mova a raquete lateralmente, enquanto a posição no eixo Y (coordY) permanece fixa.

#### Estrutura da Raquete
A raquete utiliza uma estrutura de dados chamada Bar, que contém:

coordX: Coordenada central no eixo X.
coordY: Coordenada fixa no eixo Y.
BAR_SIZE: Metade do tamanho total da raquete.
A raquete pode ser desenhada na tela utilizando uma função gráfica (como videoBox), mas este aspecto visual está desacoplado da lógica de movimento.

#### Movimento da Raquete
O movimento da raquete é gerenciado pela função moveBar, que ajusta a posição horizontal da raquete com base em um valor de aceleração (accelX). Este valor indica a direção e a magnitude do movimento. A função também verifica os limites da tela para impedir que a raquete ultrapasse as bordas.

Algoritmo de Movimento
A lógica do movimento é implementada em três etapas:

Definir limites da raquete:

São definidos os limites laterais (xStart e xEnd) que delimitam a área permitida para a raquete.
Esses limites correspondem às bordas visíveis do jogo.
Verificar se o movimento é permitido:

A função verifica se o movimento proposto pela aceleração (accelX) manterá a raquete dentro dos limites.
Se o movimento for válido, a coordenada coordX da raquete é atualizada.
Corrigir a posição ao atingir os limites:

Caso o movimento ultrapasse os limites laterais, a posição da raquete é ajustada automaticamente para o limite mais próximo.
### Estados do game
Um dos requisitos do game foi a necessidade de implementar estados para o game juntamente com um menu que fosse interativo para essas funções, e esses são os estados do jogo:
#### Estado 0: Tela Inicial
Descrição:

Esse é o estado inicial do jogo, exibindo a tela de boas-vindas ou menu principal.
Função associada: Fhome() (presumivelmente, exibe a tela inicial).
Dados do jogo, como posição da bola e barras, são reiniciados por meio da função resetData.
Ações:

Limpa a tela e os sprites (videoClear() e clearSprite()).
Reinicia os elementos da partida para suas posições padrão.
Aguarda entrada do jogador para avançar ao próximo estado.
#### Estado 1: Tela do Jogo
Descrição:

Representa a fase principal do jogo, onde a bola, as barras e os elementos interagem.
Contém toda a lógica do jogo, incluindo:
Movimento da bola.
Movimento das barras (controladas pelo jogador ou pela IA).
Colisões com bordas, raquetes e detecção de fim de jogo.
Ações:

Configura os limites e elementos da tela:
Bordas são desenhadas usando videoBox.
A bola e as barras são desenhadas e posicionadas via setSprite.
Atualiza as posições das barras com base nos controles do jogador e nos valores de aceleração (axis_x).
Detecta colisões:
Entre a bola e as barras (ballRacketCollision).
Entre a bola e as bordas da área de jogo (ballBorderCollision).
Monitora a vida dos jogadores (lifeJ1 e lifeJ2) e verifica se o jogo terminou com checkEndGame.
#### Estado 2: Pausa
Descrição:

Coloca o jogo em estado de pausa, permitindo ao jogador acessar opções de menu ou simplesmente pausar a partida.
Função associada: Fpause(currentOption + 1).
Ações:

Limpa a tela e os sprites.
Exibe um menu de pausa, permitindo ao jogador navegar pelas opções com os botões.
Opções no menu podem incluir "Continuar", "Reiniciar" ou "Sair", embora as ações específicas não sejam detalhadas no código.
Estado 3: Reiniciar o Jogo
Descrição:

Reinicia os elementos da partida, como vidas dos jogadores, posição da bola e das barras.
Útil para reiniciar o jogo após uma rodada ou ao selecionar "Reiniciar" no menu de pausa.
Ações:

Limpa a tela e os sprites.
Reinicia vidas e reposiciona a bola e as barras por meio da função resetData.
Atualiza a flag flagReset para indicar que o jogo foi reiniciado.
#### Estado 4: Game Over
Descrição:

Exibe a tela de "Game Over" quando o jogo termina.
Determina o vencedor ou perdedor com base em flagGameOver.
Ações:

Limpa a tela e os sprites.
Reinicia as vidas e os elementos do jogo.
Se flagGameOver não for -1 (ou seja, há um resultado do jogo), exibe a tela de Game Over com a função Fover.
Controle dos Estados
A lógica do jogo alterna entre os estados com base em eventos e condições específicas. Por exemplo:

O estado inicial (stateGame == 0) leva ao estado de jogo (stateGame == 1) quando o jogador inicia a partida.
Durante o jogo, o jogador pode pausar (stateGame == 2) ou terminar a partida por vitória ou derrota, o que leva ao estado de Game Over (stateGame == 4).
O menu de pausa permite reiniciar (stateGame == 3) ou retornar ao jogo (stateGame == 1).
