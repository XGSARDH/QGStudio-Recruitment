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
    password:<input type="password" name="toBePassword" id="toBePassword"><br>
    <button type="submit">Register</button>
</form>

<div id="responseMsg"></div>

<script>
    $(document).ready(function() {
        $('#registerForm').submit(function(event) {
            event.preventDefault();

            var userName = $('#userName').val();
            var phone = $('#phone').val();
            var toBePassword = $('#toBePassword').val();

            if(!phone.match(/\d{3}-\d{8}|\d{4}-\d{7}|^1(3[0-9]|4[57]|5[0-35-9]|7[0678]|8[0-9])\d{8}$/)) {
                $('#responseMsg').html('<p style="color: red;">Your massage is wrong, please choose another. </p>');
            }
            if(!toBePassword.match(/^(?=.*\\d)(?=.*[a-zA-Z])(?=.*[^\\da-zA-Z\\s]).{1,9}$/)) {
                $('#responseMsg').html('<p style="color: red;">Your password does not comply with the rules </p>');
            }


            $.ajax({
                dataType: "json",
                async: true,
                type: "POST",
                url: "http://localhost:8080/QG_mvcAndLogin_war_exploded/UserServlet", // 假定这是注册的后端接口
                data: {
                    method: 'retrievePassword',
                    userName: userName,
                    phone: phone,
                    toBePassword: toBePassword
                },
                beforeSend: function(xhr) {
                    xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded; charset=UTF-8');
                },
                success: function(response) {
                    if(response.status === 200) {
                        $('#responseMsg').html('<p style="color: green;">Change successful. </p>' +
                            '<button onclick="window.location.href=\'index.jsp\'">Return to Login</button>');
                    } else if(response.status === 201) {
                        $('#responseMsg').html('<p style="color: red;">Your password does not comply with the rules </p>');
                    } else {
                        $('#responseMsg').html('<p style="color: red;">Your massage is wrong, please choose another. </p>');
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
