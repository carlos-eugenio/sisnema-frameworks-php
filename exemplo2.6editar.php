<?php

header ('Content-type: text/html; charset=UTF-8');

require_once('classes/classe_bancodados.inc');

$db = new mysql();

if(isset($_POST['acao'])){

  if($_POST['acao'] == 'editar'){
  $fields = array('nome','senha');
  $values = array($_POST['nome'] , $_POST['senha']);
  $result = $db->atualizaSQL('usuarios', $_POST['id'], $fields, $values);
  }

  if($_POST['acao'] == 'deletar'){
  $result = $db->deletaSQL('usuarios', $_POST['id']);
  }
}


if ($result != FALSE){

  $res = $db->executaSQL("SELECT nome FROM `usuarios` WHERE id = $result");

  while ($row = $res->fetch_assoc()) {
    echo '<table>'
         .'<tr>'
         .'<td><b>Usuário '.$row["nome"].' atualizado com sucesso.</b><td>'
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

else{
  echo '<table>'
       .'<tr>'
       .'<td><b>Ocorreu um erro na atualização do usuário. Tente novamente.</b><td>'
       .'</tr>'
       .'<tr>'
       .'<td>&nbsp;</td>'
       .'</tr>'
       .'<tr>'
       .'<td><a href="exemplo2.6.php">Voltar aos usuários</a></td>'
       .'</tr>'
       .'</table>';
}

//@DESAFIO: implementar uma forma de passar mensagem de sucesso e de erro - estudar session
