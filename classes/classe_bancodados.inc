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
	abstract protected function SetNumRows();
	/*abstract protected function navegainterno($_pos);
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



  // Transações MYSQL --------------------
	public function startTransaction() {
		   $this->executaSQL('START TRANSACTION');
	}

	public function commit() {
		   $this->executaSQL('COMMIT');
	}

	public function ROLLBACK() {
		   $this->executaSQL('ROLLBACK');
	}
  // Transações MYSQL --------------------



	protected function isSELECT($_sql,$_res) {
	}


	public function find($onde, $peloque, $qualvalor, $buscaInterna = false){

      $conector = ' = ';

		  if ($buscaInterna && !is_numeric($qualvalor)){
			   $conector = " LIKE ";
				 $qualvalor = "%$qualvalor%";
		  }

		  if (!is_numeric($qualvalor)){
				 $qualvalor = "'$qualvalor'";
			}


      $sql = "select * from `$onde` where `$peloque` $conector $qualvalor";

      $retorno = $this->executaSQL($sql);

			$this->SetNumRows($retorno);
			$this->SetResult($retorno);

      return $retorno;
	}


  public function SetResult($resultado){
		  $this->resultado = $resultado;
	}


	public function GetResult($registro){

		  if ($registro >= 0 && $this->resultado->data_seek($registro)){
				  return $this->resultado->fetch_assoc();
			}

			else if ($registro > 0){
				  return $this->ultimo();
			}

			else{
				  return $this->primeiro();
			}

	}


	public function navega($registro) {

		  if($registro == 'primeiro'){
				  return $this->primeiro();
			}

			if($registro == 'ultimo'){
				  return $this->ultimo();
			}

		  return $this->GetResult($registro);
	}


	public function primeiro(){
		  return $this->GetResult(0);
	}


	public function anterior(){
			$resultSet = $this->GetResultado();
			return $resultSet->next_result();
	}


	public function ultimo(){
		  $ultimo = $this->getNumRows()-1;
			return $this->GetResult($ultimo);
	}


	public function SetNumRows($retorno) {
			$this->_numrows = $retorno->num_rows;
	}


	public function getNumRows() {
			return $this->_numrows;
	}


	public function setCase($_case=CASE_UPPER) {
	}

	public function transforma() {
	}



  /*

	public function primeiro(){
			if(!this->_posatual){
				 $this->_posatual = 0;
			}

			return $this->_posatual;
	}


	public function proximo() {
      $resultSet = $this->GetResult();
			$this->SetAnterior();
			$this->SetAtual();
			$this->SetProximo();

			return $resultSet->next_result();
	}


	public function anterior(){
	    $resultSet = $this->GetResult();
			return $resultSet->next_result();
  }


	public function SetAnterior() {
		  $this->_posanterior = $this->GetAtual();
	}


	public function SetAtual($ponteiro){
		  $this->_posanterior = $this->GetAtual()+1;
	}


	public function GetAtual(){
		  return $this->_posatual;
	}

	*/


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


	 // função criada em aula ---------------

	 public function insertSQL($nomeDaTabela, $arrCampos, $arrValores){

     $strCampos = implode(', ', $arrCampos);
		 $totalArgumentos = func_num_args();
		 $arrArgumentos = func_get_args();
		 $arrStrTodosValores = array();

		 function test_alter(&$item) {
			   $item = "'$item'";
		 }

		 for ($i=2; $i < $totalArgumentos; $i++){
			   array_walk($arrArgumentos[$i], 'test_alter');
				 $strValores = '('. implode(', ', $arraArgumentos[$i]) .')';

				 $arrStrTodosValores[] = $strValores;
		 }

		 $this->startTransaction();

		 foreach ($arrStrTodosValores as $strValorEmLoop){
			   $this->executaSQL("insert into $nomeDaTabela($strCampos) values $strValorEmLoop; ");
		 }

		 $this->commit();

		 return true;


		 /*
     $fie = implode("," , $fields);
		 $val = implode("','" , $values);

		 $this->startTransaction();
		 $this->executaSQL("INSERT INTO ".$table." (".$fie.") values ('".$val."')");
		 $this->commit();
		 */
	 }

	 // função criada em aula ---------------


}
