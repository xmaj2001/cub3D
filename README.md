Cub3D
Visão Geral
Cub3D é um projeto desenvolvido como parte do currículo da 42, inspirado no clássico jogo Wolfenstein 3D. Utilizando a técnica de raycasting, este jogo renderiza um ambiente 3D a partir de um mapa 2D definido em um arquivo .cub. O projeto permite ao jogador explorar um labirinto com paredes texturizadas, chão e teto coloridos, usando controles intuitivos para movimentação e rotação. O objetivo é criar uma experiência imersiva de exploração 3D, demonstrando habilidades em programação em C, manipulação de gráficos e parsing de arquivos.
Este projeto foi uma oportunidade de aprofundar conhecimentos em algoritmos gráficos, gerenciamento de eventos de teclado e mouse, e desenvolvimento de jogos, conectando-se à minha experiência em projetos interativos como o MapaZZZ (desenvolvido no hackathon da 42 Luanda), onde trabalhei com mapas dinâmicos e interatividade.
Funcionalidades

Raycasting 3D: Renderização de um mapa 2D em um ambiente 3D com perspectiva realista.
Movimentação do Jogador: Controle com teclas WASD (movimento) e setas (rotação).
Texturas e Cores: Paredes com texturas personalizadas, chão e teto com cores configuráveis.
Parsing de Mapa: Leitura de arquivos .cub para carregar configurações do mapa, texturas e cores.
Validação de Mapa: Garante que o mapa seja válido (cercado por paredes, com posição inicial do jogador).
Interatividade: Suporte a eventos de teclado para uma experiência fluida.
Tela Inicial: Interface inicial para introduzir o jogo (mostrada em screenshot1.png).

Tecnologias Utilizadas

C: Linguagem principal para lógica do jogo e raycasting.
MiniLibX: Biblioteca gráfica para renderização de janelas, imagens e eventos.
Makefile: Automação da compilação do projeto.
Bibliotecas Padrão do C: Para manipulação de arquivos, memória e entrada/saída.

Estrutura do Projeto
├── Makefile              # Arquivo para compilação
├── src/                  # Código-fonte em C
│   ├── main.c            # Ponto de entrada do programa
│   ├── parsing.c         # Lógica de parsing do arquivo .cub
│   ├── raycasting.c      # Algoritmo de raycasting
│   ├── events.c          # Gerenciamento de eventos de teclado/mouse
│   └── utils.c           # Funções auxiliares
├── includes/             # Arquivos de cabeçalho (.h)
├── textures/             # Imagens para texturas das paredes
├── maps/                 # Arquivos .cub com mapas
├── screenshots/          # Screenshots do projeto
│   ├── screenshot1.png   # Tela inicial
│   ├── screenshot2.png   # Jogo em execução
└── README.md             # Documentação do projeto

Instalação

Pré-requisitos:

Sistema operacional Linux ou macOS (MiniLibX é compatível com esses sistemas).
Compilador GCC ou Clang.
Biblioteca X11 (para Linux) ou framework Cocoa (para macOS).
MiniLibX instalado (veja instruções abaixo).


Instalar MiniLibX:
# No Linux
sudo apt-get install libx11-dev libxext-dev
# Clone e compile MiniLibX (ajuste o caminho conforme necessário)
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make


Passos para Instalação:
# Clone o repositório
git clone https://github.com/seu-usuario/cub3d.git
cd cub3d

# Compile o projeto
make

# Execute o jogo com um mapa
./cub3D maps/example.cub


Acesse o Jogo:

Use as teclas WASD para mover o jogador e as setas para rotacionar.
Pressione ESC para sair.



Demonstração
Tela Inicial
A tela inicial apresenta a interface do Cub3D, preparando o jogador para entrar no ambiente 3D.

Jogo em Execução
Abaixo está uma captura do jogo em ação, mostrando o ambiente 3D renderizado com raycasting.

Nota: Certifique-se de que os arquivos screenshot1.png e screenshot2.png estão na pasta screenshots/ do repositório para exibição correta no GitHub.
Como Usar

Executar o Jogo:
./cub3D maps/example.cub


Substitua example.cub por um arquivo de mapa válido.


Controles:

W: Mover para frente.
S: Mover para trás.
A: Mover para a esquerda.
D: Mover para a direita.
Seta Esquerda/Direita: Rotacionar a câmera.
ESC: Sair do jogo.


Configurar Mapas:

Crie ou edite arquivos .cub na pasta maps/.
Formato do arquivo:R 1280 720
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
F 220,100,0
C 225,30,0

111111
100001
10N001
100001
111111





Contribuição

Faça um fork do repositório.
Crie uma branch para sua feature (git checkout -b feature/nova-funcionalidade).
Commit suas alterações (git commit -m 'Adiciona nova funcionalidade').
Push para a branch (git push origin feature/nova-funcionalidade).
Abra um Pull Request.

Licença
Este projeto está licenciado sob a MIT License.
Conexão com Outros Projetos
O desenvolvimento do Cub3D reflete minha experiência em projetos interativos com mapas, como o MapaZZZ, criado durante o hackathon da 42 Luanda. No MapaZZZ, implementei um mapa interativo com frontend e backend, usando uma matriz semelhante à do Cub3D para representar o ambiente. Essa experiência foi essencial para entender parsing de mapas e renderização dinâmica, habilidades aplicadas aqui.
Contato
Para dúvidas ou sugestões, entre em contato via email@example.com.

Desenvolvido com 💻 e paixão por gráficos 3D e jogos.
