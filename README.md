# Pthreads-parte2

## Integrantes
Enrico Najjar Galdeano - 32260407
Rodrigo Mironiuc Fernandes - 32274823
Mauricio Gabriel Gutierrez Garcia - 32266601


## Instruções
instalar git e gcc
Clonar o repositório :
`https://github.com/rodmironiuc/Pthreads-parte2`
Compilar os arquivos : 
`gcc -pthread -o (novoArquivoExecutavel) pi.c`
`gcc -pthread -o (novoArquivoExecutavel) piMutex.c`
Executar os arquivo criados :
`./(novoArquivoExecutavel)`


## Explicação
A principal diferença entre os dois códigos é que a versão antiga, sem implementar o mutex, não dá o resultado correto a partir de determinada casa decimal. O que causa este problema é que nesta solução temos vários threads acessando e manipulando uma váriavel simultaneamente, e por conta disso, pode ocorrer de mais de uma thread tentar atualizar a váriavel ao mesmo tempo, fazendo consequentemente com que uma alteração sobreescreva a outra. A partir do ponto que isto acontecer, todas as casas decimais de pi vão sair trocadas. O mutex serve para impedir isso, de forma que ele bloqueia todas as outras váriaveis de atualizar a soma quando uma já estiver o fazendo. Por esse motivo a implementação utilizando o mutex se torna essencial quando procuramos um resultado preciso como esse. 
