<?php

require_once('classes/classe_bancodados.inc');

$db = new mysql();

$db->find('usuarios', 'id', '1', true);

?>
