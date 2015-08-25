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

?>
