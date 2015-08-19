<?php
/**
 * Classe B�sica para acesso a Banco de dados
 *	@abstract
 */
abstract class BancoDados {
	protected $_Tipo = null;	// Definido por cada banco de dados
	protected $_Servidor;
	protected $_Porta;
	protected $_Usuario;
	protected $_Senha;
	protected $_Banco;
	protected $_conn = false;
	protected $_dataset = false;
	protected $_numrows = -1;
	protected $_tupla = false;
	protected $_posatual = -1;
	protected $_ultimoerro = "";
	protected $_ind_case = CASE_UPPER;

	abstract public function Conectar();
	abstract public function executaSQL($_sql);
	/*abstract protected function SetNumRows();
	abstract protected function navegainterno($_pos);
	abstract protected function proximointerno();
	abstract public function escapeString($_str);
	abstract public function getLimit($_arr);
	abstract protected function SetAffectedRows();*/

  public function GetConn(){
		if(! $this->_conn){
			   $this->SetConn();
	  }

		return $this->_conn;
	}

	public function SetConn(){
		if(! $this->_conn){
			$this->_conn = new mysqli($this->GetServidor(), $this->GetUsuario(), $this->GetSenha(), $this->GetBanco());
	  }

		else{
			return $this->_conn;
		}
	}


	public function SetServidor($_servidor) {
		  $this->_Servidor = $_servidor;
	}

	public function GetServidor() {
		  return $this->_Servidor;
	}


	public function SetPorta($_porta) {
	}


	public function SetUsuario($_usuario) {
		$this->_Usuario = $_usuario;
	}

	public function GetUsuario() {
			return $this->_Usuario;
	}


	public function SetSenha($_senha) {
		  $this->_Senha = $_senha;
	}

	public function GetSenha() {
			return $this->_Senha;
	}


	public function SetBanco($_banco) {
		  $this->_Banco = $_banco;
	}

	public function GetBanco() {
		  return $this->_Banco;
	}


	public function startTransaction() {
	}

	public function commit() {
	}

	public function ROLLBACK() {
	}

	protected function isSELECT($_sql,$_res) {
	}

	public function setCase($_case=CASE_UPPER) {
	}

	public function getNumRows() {
	}

	public function transforma() {
	}

	public function navega() {
	}

	public function primeiro() {
	}

	public function proximo() {
	}

	public function anterior() {
	}

	public function ultimo() {
	}

	public function getDadosAtual() {
	}

	public function getUltimoErro() {
	}

	public function converteDataToBD() {
	}

	public function converteDataHoraToBD() {
	}

	public function converteDataToHTML() {
	}

	public function converteDataHoraToHTML() {
	}
}



class mysql extends BancoDados{

	 function __construct(){
			$this->SetServidor('localhost');
			$this->SetUsuario('root');
			$this->SetSenha('');
			$this->SetBanco('bdfw');
	 }


   public function Conectar(){
      $this->GetConn();
	 }

	 public function executaSQL($_sql){
		  return $this->GetConn()->query($_sql);
	 }
}