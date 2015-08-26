<?php


/**
 * Define os tipos de TAG HTML disponiveis
 *
 */
class tipotag {
	protected $_nome;
	protected $_finaliza = true;

	public function __construct($nome, $finaliza) {
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

$variavelQualquer = new tipotag();


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
	return $this_
}

}

?>
