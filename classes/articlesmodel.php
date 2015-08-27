<?php

class genericmodel {
    private $bd;
    private $tableName;
    private $collunms;

    public function __construct(){
        $bd = new mysql ('localhost', 'root', '', 'dbcake');
    }

    public function findAll(){
        return $this->bd->executaSQL("SELECT * FROM".$this->tableName);
    }

    class articlesmodel extends genericmodel {
        public function __construct(){
            parent::__construct();
            $this->tableName = 'articles';
            $this->collunms = array('title', 'body');
        }
    }
}
