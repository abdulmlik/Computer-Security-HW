<?php
	$text ="";
	$textarea ="";
	$select = ["md5"=>"selected","sha512"=>"","ripemd320"=>""];
	if(isset($_POST['text1']) && isset($_POST['hashfun']))
	{
		
		$textarea = $_POST['text1'];
		$hashf = $_POST['hashfun'];
		$text = hash($hashf, $textarea, false);
		foreach ($select as $k => $v) 
		{
			if ( isset($K) && isset($select[$K]) )//@$select[$K] ="";
				$select[$K] ="";
		}
		$select[$hashf] = "selected";
	}
?>
<!doctype html>
<html lang="en">
  <head>
    <title>Digital Signature!</title>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap 4 CSS -->
    <link rel="stylesheet" href="css/bootstrap.min.css">
	<!-- 
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/css/bootstrap.min.css" integrity="sha384-PsH8R72JQ3SOdhVi3uxftmaW6Vc51MKb0q5P2rRUpPvrszuE4W1povHYgTpBfshb" crossorigin="anonymous">
	-->
	<!-- My CSS -->
	<link rel="stylesheet" href="css/style.css">
	 
  </head>
  <body>
	  <nav class="navbar navbar-expand-sm navbar-fixed-top bg-info navbar-dark">
		  <div class="container-fluid">
			  <a class="navbar-brand" href="#">Digital Signature</a>
		  </div>
	  </nav>
	  <section class="form_input">
		  <div class="container">
			  <form dir="rtl" accept-charset="utf8" method="post"
					action="<?php echo $_SERVER['PHP_SELF']; ?>">
				  <fieldset>
					<div class="form-group row">
					  <label for="disabledSelect" class="col-sm-3 control-label col-form-label-lg text-right">اختر خوارزمية</label>
					  <select name="hashfun" id="disabledSelect" class="col-sm-9 form-control form-control-lg">
						 <option <?php echo $select['md5']; ?> value="md5">MD5</option>
						 <option <?php echo $select['sha512']; ?> value="sha512">Sha512</option>
						 <option <?php echo $select['ripemd320']; ?> value="ripemd320">Ripemd320</option>
					  </select>
					</div>
					 <div class="form-group row">
						<label for="exampleFormControlTextarea1" class="col-sm-3 control-label col-form-label-lg text-right">ادخل النص</label>
						<textarea name="text1" class="col-sm-9 form-control form-control-lg" id="exampleFormControlTextarea1" rows="6" style="resize: none;"><?php echo $textarea; ?></textarea>
					  </div>
					
					<div class="form-group row">
						<div class="col-sm-3"></div>
						<div class="col-sm-4 col-md-3 col-lg-2">
						  <button type="submit" class="btn btn-info btn-lg btn-block">عرض التوقيع</button>
						</div>
					</div>
					<div class="col-sm-5 col-md-6 col-lg-7"></div>
					<div class="form-group row">
					  <label for="disabledTextInput" class="col-sm-3 control-label col-form-label-lg text-right">التوقيع الالكتروني للنص</label>
					  
					<textarea name="text1" class="col-sm-12 form-control form-control-lg" id="exampleFormControlTextarea1" rows="2" placeholder="" disabled><?php echo $text; ?></textarea>
					</div>
				  </fieldset>
				</form>
		  </div>
	  </section>
	  <footer class="_footer bg-info">
		  <div class="copyright text-center">
			  Copyright &copy; 2017 <span></span> .Inc
		  </div>
	  </footer>
  </body>
</html>