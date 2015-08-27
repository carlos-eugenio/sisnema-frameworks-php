<?php

class articlescontroller {
   private $bd;

   public function __construct(){
      spl_autoload('articlesmodel');

      $this->bd = new articlesmodel();
   }

   public function index(){
      $articles = $this->bd->findAll();

      $line = '';

      while ($obj = $articles->fetch_object()){
         $line .= $obj->id;
         $line .= $obj->title;
         $line .= $obj->body;
         $line .= "<br>";
      }

      echo $line;
   }
}
