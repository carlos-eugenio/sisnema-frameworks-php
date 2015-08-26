<?php
/**
 * Classe para gerenciamento de HTML
 *
 */
class html {
    protected $_tags = Array();
    protected $_otimizado = true;

    public function addTag(tag $_tag) {
        $this->_tags[] = $_tag;
        return sizeof($this->_tags)-1;
    }

    public function setOtimizado($_ot) {
        $this->_otimizado = (bool) $_ot;
    }

    public function deleteTag($_id) {
        unset($this->_tags[$_id]);
    }

    public function toHTML() {
        $_html = "";
        foreach($this->_tags as $_tag) {
            $_html .= $_tag->toHTML($this->_otimizado);
        }
        return $_html;
    }

}

/**
 * Define os tipos de TAG HTML disponiveis
 *
 */
class tipotag {
	protected $_nome;
	protected $_finaliza = true;

	public function __construct($nome, $finaliza = true) {
      $this->_nome = $nome;
			$this->_finaliza = $finaliza;

			return $this;
	}

	public function getNome() {
      return $this->_nome;
	}

	public function getFinaliza() {
      return $this->_finaliza;
	}

}


/**
 * Define um Atributo para o marcador html relacionado
 *
 */
class atributo {
    protected $_nome;
    protected $_valor;

    public function __construct($nome, $valor = null) {
       $this->_nome = $nome;
			 $this->_valor = $valor;

			 return $this;
    }

    public function getAtributo() {
       return "{$this->_nome}".($this->_valor !== null ? "=\"{$this->_valor}\"":"");
    }

    public function getNome() {
       return $this->_nome;
    }

    public function getValor() {
       return $this->_valor;
    }
}


class tipospadrao {
    private $_tipos = Array();

    public function __construct() {
        $this->inicializa();
    }

    public function inicializa() {
        $this->_tipos = Array(  "HTML"=>new tipotag("HTML"),
            "HEAD"=>new tipotag("HEAD"),
            "TITLE"=>new tipotag("TITLE"),
            "LINK"=>new tipotag("LINK",false),
            "BODY"=>new tipotag("BODY"),
            "TABLE"=>new tipotag("TABLE"),
            "TBODY"=>new tipotag("TBOY"),
            "TR"=>new tipotag("TR"),
            "TH"=>new tipotag("TH"),
            "TD"=>new tipotag("TD"),
            "A"=>new tipotag("A"),
            "BR"=>new tipotag("BR",false),
            "FORM"=>new tipotag("FORM"),
            "INPUT"=>new tipotag("INPUT",false),
            "SELECT"=> new tipotag("SELECT"),
            "OPTION"=>new tipotag("OPTION"),
            "TEXTAREA"=>new tipotag("TEXTAREA"),
            "IMG"=>new tipotag("IMG"),
            "DIV"=>new tipotag("DIV"),
            "SPAN"=>new tipotag("SPAN"),
            "BUTTON"=>new tipotag("BUTTON"),
            "SCRIPT"=>new tipotag("SCRIPT"),
            "META"=>new tipotag("META",false),
            "COMMENT"=>new tipotag("COMMENT",false),
            "HR"=>new tipotag("HR",false),
            "P"=>new tipotag("P"),
            "MAP"=>new tipotag("MAP"),
            "IFRAME"=>new tipotag("IFRAME"),
            "AREA"=>new tipotag("AREA",false),
            "BASE"=>new tipotag("BASE",false),
            "STYLE"=>new tipotag("STYLE")
            );
}

public function getTipo($_tipo) {
	  return $this->_tipos[strtoupper($_tipo)];
}

}



/**
 * Classe que contém tags HTML
 *
 */
class tag {
    protected $_tipo;
    protected $_atributos = Array();
    protected $_valor;
    protected $_subtags = Array();

    public function __construct(tipotag $_tipo,$_atributos=Array(),$_valor=null) {
        $this->_tipo = $_tipo;
        $this->_atributos = (is_array($_atributos) ?  $_atributos : Array());
        $this->_valor = $_valor;
        return $this;
    }

    public function setValor($valor) {
        $this->_valor = $valor;
    }

    public function append($valor) {
        $this->_valor .= $valor;
    }

    public function addAtributo(atributo $atributo = null) {
			  $this->_atributos[] = $_atributo;
				return sizeof($this->_atributos)-1;
    }

    public function deleteAtributo($_atributo) {
        unset($this->_atributos[$_atributo]);
    }

    public function clearAtributos() {
        $this->_atributos = array();
    }

    public function addSubTag(tag $_subtag) {
        $this->_subtags[] = $_subtag;
				return sizeof($this->_subtags)-1;
    }

    public function deleteSubTag() {
        unset($this->_subtags[$_id]);
    }

    public function clearSubTags() {
        $this->_subtags = array();
    }

    public function toHTML() {
        $_html = "<{$this->_tipo->getNome()}";

				foreach ($this->_atributos as $_att) {
            $_html .= $_att->getAtributo();
				}

				$_html .= ">{$this->_valor}";

				foreach ($this->_subtags as $subtag) {
					 $_html .= $subtag->toHTML();
				}

				$_html .= ($this->_tipo->getFinaliza() === true ? "</{this->_tipo->getNome()}>" : "" );

				return $_html;
    }

    public function getTipo() {

    }

    public function getAtributos() {

    }

    public function getLastSubTag() {

    }

}


/**
 * Classe geradora de uma lista de Eventos
 */
class Eventos {
    protected $_eventos = Array();

    public function addEvento($_tipo="ONCLICK",$_evento="") {
    }

    public function deleteEvento($_tipo) {
    }

    public function clearEventos() {
    }

    public function getEventos() {
    }

    public function setOnclick($_evento) {
    }

    public function setOnChange($_evento) {
    }

    public function setOnFocus($_evento) {
    }

    public function setOnBlur($_evento) {
    }

    public function setOnMouseOver($_evento) {
    }

    public function setOnMouseOut($_evento) {
    }

    public function setOnKeyPress($_evento) {
    }

}





?>
