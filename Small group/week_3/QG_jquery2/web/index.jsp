
<!DOCTYPE html>
<html>
<head>
  <title>Login</title>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
</head>
<body>

<h2>Login</h2>

<form id="loginForm">
  userName:<input type="text" name="userName" id="userName"><br>
  password:<input type="password" name="password" id="password"><br>
  <button type="submit">Login</button>
</form>

<form id="registerForm">
  <button type="submit">register</button>
</form>

<div id="responseMsg"></div>

<script>
  $(document).ready(function() {
    $('#loginForm').submit(function(event) {
      event.preventDefault();


      var userName = $('#userName').val();
      var password = $('#password').val();


      $.ajax({
        dataType: "json",
        async: true,
        type: "POST",
        url: "http://localhost:8080/QG_jquery2/LoginServlet",
        data: {
          userName: userName,
          password: password
        },
        beforeSend: function(xhr) {
          xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded; charset=UTF-8');
        },
        success: function(response) {
          var resp = JSON.parse(response);
          if(resp.status === 200) {
            // 登录成功
            $('#responseMsg').html('<p style="color: green;">' + resp.msg + '</p>');
          } else {
            // 登录失败
            $('#responseMsg').html('<p style="color: red;">' + resp.msg + '</p>');
          }
        },
        error: function() {
          $('#responseMsg').html('<p style="color: red;">Error</p>');
        }
      });
    });
  });
</script>

</body>
</html>
