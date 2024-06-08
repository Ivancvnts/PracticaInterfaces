# UTAD-UI-FPS-Public
 
Para la mayoria de widgets que se muestran en pantalla use delegados, de esa manera cada que se realize una acción que le interese a cada widget estos sabran no solamente que sucedio esta acción o envento, si no que ademas se transmite en caso de ser necesario información relevante para cada widget, por ejemplo la barra de vida se le transmite la vida actual de jugador, cada que la vida cambia, independientemente si baja o sube (Aunque no hay nada que suba la vida por el momento). Otr ejemplo es el contador de munición que tambien se actualiza cada que el jugador dispara o recarga.

Para el crosshair tambien use un delegado y aqui use una UWidgetAnimation para hacer una animación que hace mas grande el crosshair y despues lo regresa a su tamaño original.

El que se suscribe a los delegados es el PlayerHUD y este mismo le pasa la información al widget que lo necesite ya que aqui tengo referencia a los widgets que se estan mostrando, de esta manera el PlayerHUD gestiona la información y los widgets solamente se actualizan con la información que les proporciona el PlayerHUD.
