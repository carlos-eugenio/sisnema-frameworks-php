<?php

require_once('classes/classe_bancodados.inc');


class Auth {

   function Auth(){

   }

   function setauth($usr){

      $expira = time() + (60*60*24*30);

      setcookie("USRS", $usr, $expira);

      session_start();
      $_SESSION["USRS"] = $usr;
    }


    function getauth(){

      if(isset($_COOKIE["USRS"]) AND isset($_SESSION["USRS"]))){

          if($_COOKIE["USRS"] == $_SESSION["USRS"]){

             $db = new mysql();
             $res = $db->executaSQL("SELECT nome FROM `usuarios` WHERE nome = ".$_SESSION["USRS"]."");

             $db->SetNumRows($res);

             if($db->getNumRows() == 1){
                return TRUE;
             }

             else{
                return FALSE;
             }
          }

          else{
             return FALSE;
          }

     }
     else{
        return FALSE;
     }

  }


}
