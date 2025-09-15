# Super Trunfo – Nível Mestre

Este projeto é a versão **Nível Mestre** do jogo **Super Trunfo**, implementado em linguagem **C**.  
Ele amplia as funcionalidades anteriores, permitindo comparar dois atributos diferentes entre as cartas de países, com menus dinâmicos, soma de atributos e regras especiais.

---

## Funcionalidades

- Comparação entre **duas cartas de países**.
- O jogador escolhe **dois atributos diferentes** para comparar.
- Regras de vitória:
  - Para a **Densidade Demográfica**, vence o menor valor.
  - Para os demais atributos, vence o maior valor.
- **Soma dos atributos escolhidos** determina o vencedor final.
- **Menus dinâmicos**: após escolher o primeiro atributo, ele não aparece como opção no segundo menu.
- Tratamento de **empates**.
- Saída detalhada e organizada, mostrando valores e resultado final.

---

## Como compilar e executar no Windows

 Instale o compilador [MinGW](http://mingw-w64.org) ou utilize o `gcc` via WSL/PowerShell.  
 Clone este repositório no seu computador:

   
   git clone https://github.com/SEU_USUARIO/super-trunfo-mestre.git
   cd super-trunfo-mestre

---

## Compile o programa

gcc super_trunfo.c -o super_trunfo.exe

---

## Execute:

super_trunfo.exe

---

## Exemplo de execução

Comparando cartas: Brasil vs Argentina

Escolha um atributo:
1 - População
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
Opção: 1

Escolha um atributo:
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
Opção: 5

===== RESULTADO =====
Brasil - População: 214000000 | Densidade Demográfica: 25.13 | Soma = 214000025.13
Argentina - População: 46000000 | Densidade Demográfica: 16.55 | Soma = 46000016.55
Vencedor: Brasil
