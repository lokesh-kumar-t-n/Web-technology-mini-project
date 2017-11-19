<!DOCTYPE html>
<html>
<head>
	<title>Form Validation with Javascript</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<div id="wrapper">
	<form method="POST" action="index.php" onsubmit="return Validate()" name="vform">
		<div>
			<input type="text" name="firstname" class="textInput" placeholder="FirstName" >
			<div id="fname_error" class="val_error"></div>
		</div>
		<div>
			<input type="text" name="lastname" class="textInput" placeholder="LastName" >
			<div id="lname_error" class="val_error"></div>
		</div>
		<div>
			<input type="text" name="fathername" class="textInput" placeholder="FatherName">
			<div id="ftname_error" class="val_error"></div>
		</div>
		<div>
			<input type="text" name="mothername" class="textInput" placeholder="MotherName">
			<div id="mtname_error" class="val_error"></div>
		</div>
		<div>
			<input type="number" name="mobilenumber" class="textInput" placeholder="Mobile Number">
			<div id="mno_error" class="val_error"></div>
		</div>
		<div>
			<input type="email" name="email" class="textInput" placeholder="Email">
			<div id="email_error" class="val_error"></div>
		</div>
		<select name="Board">
			<option>STATE</option>
			<option>CBSE</option>
			<option>ICSE</option>
		</select>
		<div>
			<input type="text" name="rollno" class="textInput" placeholder="Roll Number">
			<div id="rollno_error" class="val_error"></div>
		</div>
		<div>
			<input type="password" name="password" class="textInput" placeholder="Password">
		</div>
		<div>
			<input type="password" name="password_confirmation" class="textInput" placeholder="Password confirmation">
			<div id="password_error" class="val_error"></div>
		</div>
		<div>
			<input type="radio" id="male" name="gender"><label for ="male">Male</label>
			<input type="radio" id="female" name="gender"><label for ="female">Female</label>
		</div>
		<div>
			<input type="submit" value="Register" class="btn" name="register">
		</div>
	</form>

</div>
</body>
</html>

<script type="text/javascript">

	var firstname = document.forms["vform"]["firstname"];
	var lastname = document.forms["vform"]["lastname"];
	var fathername = document.forms["vform"]["fathername"];
	var mothername = document.forms["vform"]["mothername"];
	var mobilenumber = document.forms["vform"]["mobilenumber"];
	var email = document.forms["vform"]["email"];
	var rollno = document.forms["vform"]["rollno"];
	var password = document.forms["vform"]["password"];
	var password_confirmation = document.forms["vform"]["password_confirmation"];

	var fname_error = document.getElementById("fname_error");
	var lname_error = document.getElementById("lname_error");
	var ftname_error = document.getElementById("ftname_error");
	var mtname_error = document.getElementById("mtname_error");
	var mno_error = document.getElementById("mno_error");
	var email_error = document.getElementById("email_error");
	var rollno_error = document.getElementById("rollno_error");
	var password_error = document.getElementById("password_error");

	/*firstname.addEventListener("blur", fnameVerify, true);
	lastname.addEventListener("blur", lnameVerify, true);
	fathername.addEventListener("blur", ftnameVerify, true);
	mothername.addEventListener("blur", mtnameVerify, true);
	mobilenumber.addEventListener("blur", mnoVerify, true);
	email.addEventListener("blur", emailVerify, true);
	rollno.addEventListener("blur", rollnoVerify, true);
	password.addEventListener("blur", passwordVerify, true);
	*/

	function Validate(){
		if (firstname.value == "") {
			firstname.style.border = "1px solid red";
			fname_error.textContent = "Firstname is required";
			firstname.focus();
			return false;
		}
		if (lastname.value == "") {
			lastname.style.border = "1px solid red";
			lname_error.textContent = "Lastname is required";
			lastname.focus();
			return false;
		}
		if (fathername.value == "") {
			fathername.style.border = "1px solid red";
			ftname_error.textContent = "Fathername is required";
			fathername.focus();
			return false;
		}
		if (mothername.value == "") {
			mothername.style.border = "1px solid red";
			mtname_error.textContent = "Mothername is required";
			mothername.focus();
			return false;
		}
		if (mobilenumber.value == "") {
			mobilenumber.style.border = "1px solid red";
			mno_error.textContent = "Mobile Number is required";
			mobilenumber.focus();
			return false;
		}
		if((mobilenumber.value.length<10)||(mobilenumber.value<0)){
			mobilenumber.style.border= "1px solid red";
			mno_error.textContent="Enter a valid mobile number";
			mobilenumber.focus();
			return false;
		}
		if (email.value == "") {
			email.style.border = "1px solid red";
			email_error.textContent = "email is required";
			email.focus();
			return false;
		}
		if (rollno.value == "") {
			rollno.style.border = "1px solid red";
			name_error.textContent = "Roll Number is required";
			rollno.focus();
			return false;
		}
		if (password.value == "") {
			password.style.border = "1px solid red";
			password_error.textContent = "password is required";
			password.focus();
			return false;
		}
		if (password.value != password_confirmation.value) {
			password.style.border = "1px solid red";
			password_confirmation.style.border = "1px solid red";
			password_error.innerHTML = "The two passwords do not match";
			return false;
		}



	}
</script>
