# Cálculo da potencia e rendemento térmicos dunha etapa de refrixeración ou calefacción dunha unidade de tratamento de aire (UTA)

Unha UTA é un dispositivo para recoller, renovar e axeitar as condicións do aire non local pechado, atendendo a unha serie de condicións de calidade en termos de densidade de partículas e tamaño das mesmas, temperatura e humidade de conforto, etc. Empréganse en edificios de oficinas, centros comerciais, hospitais, ou outros edificios que deban de levar un control da calidade do aire interior, sexa por afluencia ou por tipoloxía da actividade levada a cabo no interior ou por seguridade sanitaria. En xeral adoitan ser modulares ou estaren deseñadas contemplando varios módulos de tratamento do aire, en atención á demanda da instalación. Pódese ver un esquema en sección dun modelo típico na imaxe a seguir.

![modelo uta artistico](https://user-images.githubusercontent.com/26594148/126035377-07208b85-4706-46b0-a056-fa3c68813694.jpg)

Na figura aprécianse: a entrada de aire exterior, a impulsión de aire ao interior do edificio, así como a recollida do aire interior para tratalo antes de ser expulsado ao exterior. Entremedias pódese observar varias etapas de filtrado, de quecemento e enfriamento, impulsión e humectación. Ademais existe un tratamento antibacteriano mediante luz UV que pode ser tamén efectivo contra outros riscos biolóxicos como o SARS-COV19.

En moitos textos técnicos ou libros de texto dos nosos ciclos formativos aparecen esquemas menos artísticos, pero que inciden na mesma modularidade das unidades de tratamento do aire.

![esquema UTA](https://user-images.githubusercontent.com/26594148/126035413-750c6bef-f571-4441-8eab-477b2a3b2132.jpg)
 
Obsérvase que unha parte importante da UTA é a que corresponde ás baterías de refrixeración e calefacción. Nestas etapas extráese calor (refrixeración) ou engádese (calefacción), a fin de acercar os valores de temperatura aos de confort da instalación. A pesar do que poida parecer, na sensación térmica non intervén unicamente a temperatura do aire. Un factor moi importante é a humidade que transporta o fluxo do aire. Ao enfriar o aire na batería de refrixeración, este perde unha parte do vapor de auga disolto, polo que pode ser necesario engadirlle unha cantidade de auga a fin de acercar a humidade relativa á que se demanda para o confort na estancia. Algo parecido pasa cando é necesario quecer o fluxo de aire que se introduce no habitáculo: ao aumentar a temperatura do aire diminúe a súa densidade, polo que aínda contendo a mesma cantidade de vapor de auga, a humidade relativa diminúe. Neste caso tamén pode ser necesario engadir vapor para acercar o valor de humidade relativa ao necesario para o confort das persoas.

A inclusión de vapor nas condicións de acondicionamento do aire ocasiona que teñamos que xogar con dous tipos de enerxía térmica: calor sensible (empregado en aumentar ou diminuír a temperatura do fluxo de aire) e calor latente (empregado en evaporar o aire que se engade ao fluxo de aire). Non se pode pedir a un técnico que faga os cálculos de potencia térmica asociados a estes dous tipos de calor. Sen embargo, dispón dunha ferramenta gráfica (o [diagrama psicrométrico] (https://gl.wikipedia.org/wiki/Psicrometr%C3%ADa)) que facilita moito esta tarefa ou incluso [calculadoras online] (https://www.herramientasingenieria.com/onlinecalc/spa/psicrometricos/psicrometricos.html) a partir da mesma [ferramenta gráfica] (https://en.wikipedia.org/wiki/Psychrometrics#/media/File:PsychrometricChart.SeaLevel.SI.svg).

Estas tres etapas (refrixeración, calefacción e humectación) ocasionan unha parte importante do consumo da UTA, polo que é importante que os técnicos saiban como realizar unha medida axeitada da potencia térmica consumida, así como do rendemento, a fin de comprobar que a instalación está operando dentro duns parámetros razonables de funcionamento. Deseñouse un equipo portátil para que os alumnos poidan medir a temperatura e humidade do aire na entrada da etapa de calefacción/refrixeración/humectación e tamén na saída. Con estes catro valores de temperatura e humidade (IN e OUT) pódese situar dous puntos no diagrama psicrométrico. Cada un destes puntos representa unha masa de aire caracterizado por esa T e Hr. O diagrama psicrométrico permítenos obter o resto das características físicas de cada masa de aire, en particular a súa entalpía. A partir da diferenza de entalpías entre ambos puntos (entrada e impulsión), obtemos a potencia térmica consumida. A partir de aí pódense obter parámetros de rendemento da instalación (tanto térmico como eléctrico).

O equipo que deseñamos consta de dous sensores [DHT11] (https://components101.com/sensors/dht11-temperature-sensor) que miden temperatura e humidade relativa. Estes sensores van conectados a unha placa Arduino a través de dúas entradas analóxicas e proporcionan medidas de ambas magnitudes a intervalos temporais fixos. Nesta ocasión preferíuse empregar unha placa Arduino UNO no canto de ESP8266 porque o equipo vai estar montado nunha caixa portátil, de maneira que o operador a poida levar a diferentes lugares do taller ou entorno de traballo. Isto é máis fácil coas placas Arduino, xa que teñen un rango de voltaxe para alimentación maior que as ESP8266. Desta maneira non estamos tan limitados á hora de alimentalos mediante baterías ou directamente á rede eléctrica (coa súa correspondente fonte de alimentación intermeda). Por outra parte, nesta ocasión non precisamos das vantaxes de comunicación que nos proporciona o módulo WiFi do ESP8266.

A placa Arduino vai conectada cunha pantalla LCD 16x2 que mostra os valores de T e Hr a intervalos regulares (véxase o script). Cada liña da pantalla corresponde ao valores medidos por cada un dos sensores (identificados por un ID numérico). Adicionalmente, cada sensor vai identificado cunha lapela. Isto último non sería necesario, xa que en caso de mal funcionamento dun dos sensores, aparece unha mensaxe de erro na liña correspondente. Bastaría desconectar un deles para identificalos.

A seguir móstranse fotografías dos equipos montados, así como de detalle e de funcionamento.


![Medidores potencia UTA I](https://user-images.githubusercontent.com/26594148/126037025-fbe8ddc8-64d6-4a26-94b8-a4f0a282db86.jpeg)
####### Conxunto de medidores empregados polos alumnos




![Medidor potencia UTA Detalle exterior I](https://user-images.githubusercontent.com/26594148/126037079-42ff3bb5-bb1c-406d-af93-c414d0afa02b.jpeg)
####### Unidade de medición de parámetros de aire (detalle exterior da caixa, xunto cos sensores DHT11)




![Medidor potencia UTA Detalle interior II](https://user-images.githubusercontent.com/26594148/126037104-115596d4-0072-4ffc-9a07-b2ccf03f96f4.jpeg)
####### Unidade de medición de parámetros de aire (detalle interior do conexionado cos sensores e coa pantalla LCD 16x2)




![Medidor potencia UTA en funcioamento I](https://user-images.githubusercontent.com/26594148/126037203-c0edcca1-3a9c-4bdf-baa1-7ff0820aa2fa.jpeg)
####### Unidade de medición de parámetros de aire (detalle exterior da unidade en funcionamento)






