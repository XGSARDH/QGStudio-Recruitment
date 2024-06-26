<!DOCTYPE html>
<html>
<head>
  <title>Register</title>
  <script src="https://cdn.bootcdn.net/ajax/libs/jquery/3.6.1/jquery.min.js"></script>
</head>
<body>

<h2>Register</h2>

<p>Password rules: At least contain letters, numbers, special characters, 1-9 digits</p>

<form id="registerForm">
  userName:<input type="text" name="userName" id="userName"><br>
  phone:<input type="text" name="phone" id="phone"><br>
  password:<input type="password" name="password" id="password"><br>
  <button type="submit">Register</button>
</form>

<div id="responseMsg"></div>

<script>
  $(document).ready(function() {
    $('#registerForm').submit(function(event) {
      event.preventDefault();

      var userName = $('#userName').val();
      var password = $('#password').val();
      var phone = $('#phone').val();

      $.ajax({
        dataType: "json",
        async: true,
        type: "POST",
        url: "http://localhost:8080/QG_mvcAndLogin_war_exploded/UserServlet", // 假定这是注册的后端接口
        data: {
          method: 'register',
          userName: userName,
          password: password,
          phone: phone
        },
        beforeSend: function(xhr) {
          xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded; charset=UTF-8');
        },
        success: function(response) {
          if(response.status === 200) {
            $('#responseMsg').html('<p style="color: green;">Registration successful. </p>' +
                    '<button onclick="window.location.href=\'index.jsp\'">Return to Login</button>');
          } else if(response.status === 201) {
            $('#responseMsg').html('<p style="color: red;">Your password does not comply with the rules </p>');
          } else if(response.status === 202) {
            $('#responseMsg').html('<p style="color: red;">Your phone does not comply with the rules </p>');
          } else {
            $('#responseMsg').html('<p style="color: red;">Username taken, please choose another. </p>');
          }
        },
        error: function() {
          $('#responseMsg').html('<p style="color: red;">Error during registration.</p>');
        }
      });
    });
  });
</script>

</body>
</html>
