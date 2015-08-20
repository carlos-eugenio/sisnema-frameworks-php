<?php
    require_once 'classes\classe_bancodados.inc';

    $bd = new mysql();

    $bd->Conectar();

    if(isset($_POST['nome'])){
      $fields = array('nome','senha');
      $values = array($_POST['nome'] , $_POST['senha']);
      $bd->insertSQL('usuarios', $fields, $values);
    }


    $res = $bd->executaSQL("SELECT * FROM `usuarios`");

    while ($row = $res->fetch_assoc()) {
        printf ("%s (%s)\n", $row["id"], $row["nome"]);
    }
?>


<form method="POST" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <p><br><b>INSERIR NOVO USUARIO</b><br></p>
    <p>NOME:<input type="text" name="nome"></p>
    <p>SENHA:<input type="text" name="senha"></p>
    <p><input type="submit" name="envia" value="Enviar"></p>
</form>
