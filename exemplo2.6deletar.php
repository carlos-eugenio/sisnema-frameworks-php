<?php

header ('Content-type: text/html; charset=UTF-8');

require_once('classes/classe_bancodados.inc');

$db = new mysql();

if(!isset($_GET['acao'])){
   echo 'Entre pelo exemplo 2.6.php'
        .'<a href="exemplo2.6.php">Voltar aos usuários</a>';

}

else{
$result = $db->deletaSQL('usuarios', $_GET['id']);

if ($result){
    echo '<table>'
         .'<tr>'
         .'<td><b>Usuário deletado com sucesso.</b><td>'
         .'</tr>'
         .'<tr>'
         .'<td>&nbsp;</td>'
         .'</tr>'
         .'<tr>'
         .'<td><a href="exemplo2.6.php">Voltar aos usuários</a></td>'
         .'</tr>'
         .'</table>';
}       
}
