<?php
    require_once 'classes\classe_bancodados.inc';

    $bd = new mysql();

    $bd->Conectar();

    $res = $bd->executaSQL("SELECT * FROM `usuarios`");

    while ($row = $res->fetch_assoc()) {
        printf ("%s (%s)\n", $row["id"], $row["nome"]);
    }
?>
