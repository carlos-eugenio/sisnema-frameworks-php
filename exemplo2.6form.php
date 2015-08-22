<?php header ('Content-type: text/html; charset=UTF-8'); ?>

<form method="POST" action="exemplo2.6editar.php">
   <fieldset>
     <legend>Atualizar novo usuário</legend>
      <dl>
         <dt><label for="nome">Nome</label></dt>
         <dd><input name="nome" id="nome" placeholder="<?php echo $_GET['nome']; ?>"></dd>
      </dl>
   </fieldset>
   <fieldset>
      <dl>
         <dt><label for="senha">Senha</label></dt>
         <dd><input type="password" name="senha" id="senha" placeholder="Digite sua senha"></dd>
         <input type="hidden" name="id" value="<?php echo $_GET['id']; ?>" />
         <input type="submit" value="Enviar" name="enviar"/>
      </dl>
   </fieldset>
</form>
