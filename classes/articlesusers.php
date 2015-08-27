<?php

require_once 'classe_bancodados.inc';

class genericmodel {
    private $bd;
    private $field;
    private $value;
    private $tableName;

    public function __construct(){
        $bd = new mysql ('localhost', 'root', '', 'dbcake');
    }

    public function findAll(){
        return $this->bd->executaSQL("SELECT * FROM'".$this->tableName."' WHERE ".$this->field." = '".$this->value."'");
    }

}

class articlesusers extends genericmodel {
        public function __construct(){
            parent::__construct();
            $this->tableName = 'usuarios';
            $this->field = 'id';
            $this->value = '1';
        }
}
