<?php

header ('Content-type: text/html; charset=UTF-8');

require_once('classes/classe_bancodados.inc');

$db = new mysql();

if(isset($_POST['id'])){
  $fields = array('nome','senha');
  $values = array($_POST['nome'] , $_POST['senha']);
  $db->atualizaSQL('usuarios', $_POST['id'], $fields, $values);
}


//@DESAFIO: implementar uma forma de passar mensagem de sucesso e de erro - estudar session
