<?php
    $controller = $_GET['controller'] . "controller";
    $action = $_GET['action'];

    spl_autoload($controller);

    $objController = new controller();
    $objController ->action();
?>
