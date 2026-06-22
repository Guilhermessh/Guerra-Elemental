# Guerra-Elemental
"Guerra Elemental" é um jogo que estou desenvolvendo em C, ele é um pouco simples e está sendo feito para praticar tudo que tenho aprendido até agora na linguagem C. 

Descrição Geral  

Guerra Elemental é um jogo de batalha por turnos onde o jogador escolhe uma criatura elemental para enfrentar uma criatura controlada pelo computador.  

Cada criatura representa um elemento da natureza e possui vantagens e desvantagens contra outros elementos.  

O objetivo é derrotar o adversário reduzindo sua vida a zero antes que sua própria vida seja esgotada.  

Cada criatura domina um elemento específico:  

Fogo   

Terra   

Raio   

Água   

Ar  

  

O jogador deverá escolher uma dessas criaturas e enfrentar batalhas contra o computador utilizando estratégia e aproveitando as vantagens elementais.  

Criaturas Criatura 	 	 	 	 	 	Elementos  

Pyronix      Fogo  

Terragor      Terra  

Voltigar      Raio  

Aquarion      Água  

Aerofin      Ar  

O jogo terá um Menu principal em que o jogador poderá escolher Jogar, Ver um guia ou sair do jogo. Se ele clicar em jogar irá para uma tela de seleção de personagem onde ele escolherá uma Criatura e a máquina irá selecionar uma aleatoriamente. Se ele selecionar guia verá uma explicação detalhada de como o jogo funciona. E se ele clicar para sair o jogo fecha.  

O sistema de turnos consistirá em 2 opções: Atacar e Defender. Atacar como o próprio nome sugere vai dar o dano máximo possível dentro das limitações de vantagens e desvantagens. Enquanto a opção defender irá diminuir o dano consideravelmente.  

Elemento 	 	 	 	Vence  

Fogo 	 	 	 	 	 	Terra  

  

Raio      Água Água      Ar  

Ar 	 	 	 	 	 	Fogo  

  

Escopo de Desenvolvimento  

Etapa 1  

Criar menu principal.  

  

Etapa 2  

Criar tela de regras.  

  

Etapa 3  

Criar seleção de criaturas.  

  

Etapa 4  

Implementar sistema de vantagens elementais.  

  

Etapa 5  

Implementar combate por turnos.  

  

Etapa 6  

Implementar condições de vitória e derrota.  

  

Etapa 7  

Implementar opção de jogar novamente.  

  

 Melhorias realizadas 22/06/2026: 

Criação de mais 20 novas criaturas (totalizando 25) 

Criação de Ataques de cada elemento, variando o dano e adicionando um novo recurso de precisão do golpe. 

Criação de sistema de estatísticas base das criaturas (Ataque, Defesa, Vida, Velocidade). Dando mais dinâmica e variedade para as batalhas. Precisando ser elaborada mais estratégias pensando em como cada criatura age. 

 

 

Melhorias Futuras: 

Criação de um modo Aventura, onde o jogador percorre um mundo aleatoriamente e eventos de encontros aleatórios acontecem periodicamente. 
 

Criação de um Sistema de XP e nível, onde a criatura começará em um determinado nível (exemplo: Pyronix lvl1) e evoluirá conforme for ganhando XP nas batalhas. 
 

Implementar um Sistema de Capturas, onde no modo aventura será possível realizar a captura de criaturas selvagens que o jogador for encontrando no caminho. Para isso terá que ser criado uma ferramenta de captura e terá que ser adicionado uma porcentagem de chance de captura, que levará em conta o nível da criatura e a quantidade de vida restante (quanto mais baixa maior a chance de capturar). 
 

Criar um Sistema de Equipes, onde será possível carregar mais de uma criatura e as criaturas que forem sendo capturadas entrarão para o time (máx de 5 no time). Paralelo a isso deverá ser criado uma função na batalha para ser possível realizar a troca de criaturas durante a batalha. Treinadores rivais também poderão ter mais de 1 criatura no time, além de também poder realizar a troca durante a batalha. 
 

Criação de ataques que causam efeitos e não necessariamente dano direto. Exemplos: Ataques de cura, Ataques que causam paralisia impedindo a criatura inimiga de se mexer, ataques que causam algum tipo de queimadura ou envenenamento causando dano ao fim de cada rodada. 
 

Aumentar a inteligência dos treinadores, fazendo eles optarem sempre que possível pelo golpe que tem vantagem contra a outra criatura. 
 

Criar uma opção de fuga ao encontrar criaturas selvagens. 
 

(CASO SEJA POSSÍVEL) Criar um sistema de salvamento para que o jogador não perca o seu avanço na jornada e tenha que recomeçar tudo. 

 

 

 

 

 

  

  

  
