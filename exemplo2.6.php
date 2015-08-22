<?php

header ('Content-type: text/html; charset=UTF-8');

require_once('classes/classe_bancodados.inc');

$db = new mysql();

$resultado = $db->find('usuarios', 'nome', '', true);

$posicao = isset($_GET['posicao']) ? $_GET['posicao'] : 0 ;

if(isset($_GET['posicao'])){
  $resultado = array($posicao => $db->navega($posicao));
}


else{
echo '<table>'
     .'<tr>'
     .'<td><b>TABELA DE USUÁRIOS</b><td>'
     .'</tr>'
     .'<tr>'
     .'<td>&nbsp;</td>'
     .'</tr>';;

foreach ($resultado as $pos => $item) {
    echo '<tr>'
         .'<td><b>Usuário</b></td>'
         .'</tr>'
         .'<tr>'
         .'<td>'.$item['id'].' - '.$item['nome'].'</td>'
         .'</tr>'
         .'<tr>'
         .'<td><a href="exemplo2.6form.php?acao=editar&id='.$item['id'].'&nome='.$item['nome'].'">Editar</a>&nbsp;&nbsp;<a href="exemplo2.6form.php?acao=deletar&id='.$item['id'].'&nome='.$item['nome'].'">Deletar</a></td>'
         .'</tr>'
         .'<tr>'
         .'<td>&nbsp;</td>'
         .'</tr>';
}

echo '</table>';
}
?>
